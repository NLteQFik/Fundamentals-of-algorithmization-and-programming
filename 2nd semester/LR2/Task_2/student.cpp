#include "student.h"

Student::Student(QString speciality, int group, QString name, QString *subjects, int *marks)
{
    this->speciality = speciality;
    this->group = group;
    this->name = name;
    for (int i = 0; i < 5; i++) {
        this->subjects[i] = subjects[i];
        this->marks[i] = marks[i];
        average_mark += marks[i];
    }
    average_mark /= 5.0;
}

Student::Student(QString speciality, QString group, QString name, QString *subjects, QString *marks)
{
    this->speciality = speciality.remove('\n');
    this->group = group.toInt();
    this->name = name.remove('\n');
    for (int i = 0; i < 5; i++) {
        this->subjects[i] = subjects[i].remove('\n');
        this->marks[i] = marks[i].toInt();
        average_mark += marks[i].toInt();
    }
    average_mark /= 5.0;
}

QString Student::GetSpeciality()
{
    return speciality;
}

int Student::GetGroup()
{
    return group;
}

QString Student::GetName()
{
    return name;
}

QString *Student::GetSubjects()
{
    return subjects;
}

int *Student::GetMarks()
{
    return marks;
}

double Student::GetAverageMark()
{
    return average_mark;
}

bool Student::CheckValidity()
{
    bool check = true;
    for (int i = 0; i < 5; i++) {
        check = (check && (marks[i] >= 0 && marks[i] <= 10));
        check = (check && !subjects[i].isEmpty());
    }
    check = (check && group > 0);
    check = (check && !speciality.isEmpty());
    check = (check && !name.isEmpty());
    if (check)
        return true;
    else
        return false;
}
