#include "fileservices.h"

FileServices::FileServices() {}

void FileServices::FindFile(QWidget* w)
{
    QString opened_file = QFileDialog::getOpenFileName(w, "Select .txt file with dates", QDir::homePath(), "Text files(*.txt)");
    if(!opened_file.isEmpty()) {
        file_name = opened_file;
    }
}

int FileServices::ReadFromFile(QVector<Student> &students)
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 1;
    }

    students.clear();
    int i = 0;
    QString speciality;
    QString group;
    QString name;
    QString subjects[5];
    QString marks[5];
    while (!file.atEnd()) {
        speciality = file.readLine();
        if (!file.atEnd()) group = file.readLine();
        if (!file.atEnd()) name = file.readLine();
        for (int i = 0; i < 5; i++) {
            if (!file.atEnd()) subjects[i] = file.readLine();
            if (!file.atEnd()) marks[i] = file.readLine();
            else {
                return 2;
            }
        }
        students.push_back(Student(speciality, group, name, subjects, marks));
        if (students[i].CheckValidity() == false) {
            return 2;
        }
        i++;
    }
    file.close();
    return 0;
}

int FileServices::SaveToFile(QVector<Student> &students)
{
    QFile file(file_name);
    file.resize(0);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        return 1;
    }

    QTextStream out(&file);
    for (int i = 0; i < students.size(); i++) {
        out << students[i].GetSpeciality() << '\n';
        out << QString::number(students[i].GetGroup()) << "\n";
        out << students[i].GetName() << '\n';
        for (int j = 0; j < 5; j++) {
            out << students[i].GetSubjects()[j] << '\n';
            out << QString::number(students[i].GetMarks()[j]) << "\n";
        }
    }
    file.close();
    return 0;
}
