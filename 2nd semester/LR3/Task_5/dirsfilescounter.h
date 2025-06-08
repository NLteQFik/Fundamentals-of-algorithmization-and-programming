#ifndef DIRSFILESCOUNTER_H
#define DIRSFILESCOUNTER_H

#include <QDir>

class DirsFilesCounter
{
public:
    DirsFilesCounter();
    void Count(long long& dirs_number, long long& files_number, QString path);
};

#endif // DIRSFILESCOUNTER_H
