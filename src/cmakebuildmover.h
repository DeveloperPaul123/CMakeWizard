#pragma once

#include <QString>

struct CmakeBuildMover
{
	static bool moveBuildDirectory(const QString &src_dir, const QString &dest_dir);

private:
	static bool copyRecursive(const QString &src_dir , const QString &dest_dir);
	static bool adjustCmakeCache(const QString &src_dir, const QString &dst_dir);
};