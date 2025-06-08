#ifndef FILESERVICES_H
#define FILESERVICES_H

#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include <QString>

#include "student.h"

class FileServices
{
public:
    FileServices();

    void FindFile(QWidget* w);
    int ReadFromFile(QVector<Student> &students);
    int SaveToFile(QVector<Student> &students);

private:
    QString file_name = "/home/matsvei/Documents/453502/2sem/LR2/Task_2/Students.txt";
};

#endif // FILESERVICES_H
