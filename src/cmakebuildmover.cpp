#include "cmakebuildmover.h"

#include <QDir>
#include <QTextStream>

bool CmakeBuildMover::moveBuildDirectory(const QString& src_dir, const QString& dest_dir)
{
	// first check if cmake cache exists. 
	QFileInfo srcFileInfo(src_dir);
	if (srcFileInfo.isDir())
	{
		QDir src(src_dir);
		auto cmake_cache = src.absoluteFilePath("CMakeCache.txt");
		QFileInfo cache(cmake_cache);
		if (!cache.exists())
		{
			return false;
		}
	}
	auto copy_ok = copyRecursive(src_dir, dest_dir);
	if (copy_ok) {
		auto adjust_ok = adjustCmakeCache(src_dir, dest_dir);
		return adjust_ok;
	}
	return copy_ok;
}

bool CmakeBuildMover::copyRecursive(const QString& src_dir, const QString& dest_dir)
{
	// Taken from: https://gist.github.com/ssendeavour/7324701
	QFileInfo srcFileInfo(src_dir);
	if (srcFileInfo.isDir()) {
		QDir sourceDir(src_dir);
		QDir targetDir(dest_dir);
		targetDir.cdUp();
		if (!targetDir.mkdir(QFileInfo(dest_dir).fileName()))
			return false;
		auto fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
		foreach(const QString &fileName, fileNames) {
			const auto newSrcFilePath
				= src_dir + QLatin1Char('/') + fileName;
			const auto newTgtFilePath
				= dest_dir + QLatin1Char('/') + fileName;
			if (!moveBuildDirectory(newSrcFilePath, newTgtFilePath))
				return false;
		}
	}
	else {
		if (!QFile::copy(src_dir, dest_dir))
			return false;
	}
	return true;
}

bool CmakeBuildMover::adjustCmakeCache(const QString& src_dir, const QString& dst_dir)
{

	// at the point this function is called, we know for user the cmake cache exists.
	QDir dstDir(dst_dir);
	auto cmake_cache_path = dstDir.absoluteFilePath("CMakeCache.txt");
	QFileInfo cache_info(cmake_cache_path);
	if (!cache_info.exists())
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
				QTextStream out_stream(&cache);
				for (auto s : lines)
				{
					if (s.toLower().contains(src_dir))
					{
						s.replace(src_dir, dst_dir);
						out_stream << s;
					}
				}
				// success!
				return true;
			}
			// couldn't open file again.
			return false;
		}

		// couldn't open file.
		return false;
	}

	// file doesn't exist. 
	return false;
}
