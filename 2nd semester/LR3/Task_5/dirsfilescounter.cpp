#include "dirsfilescounter.h"

DirsFilesCounter::DirsFilesCounter() {}

void DirsFilesCounter::Count(long long &dirs_number, long long &files_number, QString path)
{
    QDir cur_dir = QDir(path);
    if (cur_dir.isEmpty() || !cur_dir.exists())
        return;
    files_number += cur_dir.entryList(QDir::Files).size();
    for (QString& sub_path : cur_dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot)) {
        dirs_number++;
        Count(dirs_number, files_number, path + '/' + sub_path);
    }
}
