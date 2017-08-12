#include "cmakebuildmover.h"

#include <QDir>
#include <QTextStream>

#include <easylogging++.h>

bool CmakeBuildMover::moveBuildDirectory(const QString& src_dir, const QString& dest_dir)
{
	// first check if cmake cache exists. 
	LOG(INFO) << "Starting recursive file copying...";
	auto copy_ok = copyRecursive(src_dir, dest_dir);
	if (copy_ok) {
		auto adjust_ok = adjustCmakeCache(src_dir, dest_dir);
		return adjust_ok;
	}
	LOG(ERROR) << "Recursive copy failed.";
	return copy_ok;
}

bool CmakeBuildMover::copyRecursive(const QString& src_dir, const QString& dest_dir)
{
	// Taken from: https://gist.github.com/ssendeavour/7324701
	QFileInfo srcFileInfo(src_dir);
	if (srcFileInfo.isDir()) {
		LOG(INFO) << "Copying directory...";
		QDir sourceDir(src_dir);
		QDir targetDir(dest_dir);
		auto ok = targetDir.mkpath(dest_dir);
		
		if(!ok)
		{
			LOG(ERROR) << "Could not make target directory path. Exiting...";
			return ok;
		}

//		if (!targetDir.mkdir(QFileInfo(dest_dir).fileName())) {
//			LOG(ERROR) << "Could not make target directory.";
//			return false;
//		}
		auto fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
		foreach(const QString &fileName, fileNames) {
			const auto newSrcFilePath
				= src_dir + QLatin1Char('/') + fileName;
			const auto newTgtFilePath
				= dest_dir + QLatin1Char('/') + fileName;
			if (!copyRecursive(newSrcFilePath, newTgtFilePath)) {
				return false;
			}
		}
	}
	else {
		LOG(INFO) << "Copying file: " << src_dir.toStdString();
		if (!QFile::copy(src_dir, dest_dir)) {
			LOG(ERROR) << "File copy failed.";
			return false;
		}
		LOG(INFO) << "File copy succeeded.";
	}
	LOG(INFO) << "Directory copying succeeded.";
	return true;
}

bool CmakeBuildMover::adjustCmakeCache(const QString& src_dir, const QString& dst_dir)
{

	// at the point this function is called, we know for user the cmake cache exists.
	QDir dstDir(dst_dir);
	auto cmake_cache_path = dstDir.absoluteFilePath("CMakeCache.txt");
	LOG(INFO) << "CMakeCache output path: " << cmake_cache_path.toStdString();
	QFileInfo cache_info(cmake_cache_path);
	if (cache_info.exists())
	{
		QFile cache(cmake_cache_path);
		QStringList lines;
		if(cache.open(QIODevice::ReadOnly|QIODevice::Text))
		{
			QTextStream stream(&cache);
			while(!stream.atEnd())
			{
				auto line = stream.readLine();
				lines.append(line);
			}
			cache.close();

			if (cache.open(QIODevice::WriteOnly | QIODevice::Text))
			{
				LOG(INFO) << "Adjusting CMakeCache in destination...";
				QTextStream out_stream(&cache);
				for (auto s : lines)
				{
					auto output = s;
					if (s.contains(src_dir, Qt::CaseInsensitive))
					{
						output = s.replace(src_dir, dst_dir, Qt::CaseInsensitive);
					}
					out_stream << output << endl;
				}
				cache.close();
				// success!
				LOG(INFO) << "Move completed.";
				return true;
			}
			// couldn't open file again.
			LOG(ERROR) << "Could not open CMakeCache.txt in destination directory.";
			return false;
		}

		// couldn't open file.
		LOG(ERROR) << "Could not open CMakeCache.txt in destination directory.";
		return false;
	}
	LOG(ERROR) << "CMake cache does not exist in destination directory.";

	// file doesn't exist. 
	return false;
}
