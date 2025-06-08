#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QList>

#include <QDebug>

class Date
{
public:
    Date(int day, int month, int year);
    Date(const QString &str);

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    bool CheckValidity() const;

    int DaysInMonth(int month) const;
    Date NextDay() const;
    Date PreviousDay() const;
    bool IsLeap() const;
    short WeekNumber() const;
    int DaysFromStart() const;
    int DaysTillYourBithday(Date bithdaydate) const;
    int Duration(Date date) const;
    int Difference(Date date) const;
    QString DateToString() const;

private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
