#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QVector>

#include <QDebug>

class Student
{
public:
    Student(QString speciality, int group, QString name, QString *subjects, int *marks);
    Student(QString speciality, QString group, QString name, QString *subjects, QString *marks);

    QString GetSpeciality();
    int GetGroup();
    QString GetName();
    QString* GetSubjects();
    int* GetMarks();
    double GetAverageMark();

    bool CheckValidity();

private:
    QString speciality;
    int group;
    QString name;
    QString subjects[5]{""};
    int marks[5]{0};
    double average_mark = 0;
};

#endif // STUDENT_H
