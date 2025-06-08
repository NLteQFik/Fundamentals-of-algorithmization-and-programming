#include "date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const QString &str)
{
    QStringList str_split = str.split('.');
    if (str.split('.').size() != 3)
        *this = Date(0, 0, 0);
    int temp_day = str.split('.')[0].toInt();
    int temp_month = str.split('.')[1].toInt();
    int temp_year = str.split('.')[2].toInt();
    Date new_date = Date(temp_day, temp_month, temp_year);
    if (new_date.CheckValidity() == true) {
        *this = new_date;
        return;
    }
    *this = Date(0, 0, 0);
}

int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}

bool Date::CheckValidity() const
{
    if (year > 0 && year < 10000 && month > 0 && month < 13 && day > 0 && day < DaysInMonth(month) + 1)
        return true;
    return false;
}

int Date::DaysInMonth(int month) const
{
    switch (month) {
    case 2:
        return IsLeap() ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

Date Date::NextDay() const
{
    if (day + 1 > DaysInMonth(month) && month == 12)
        return Date(1, 1, year + 1);
    if (day + 1 > DaysInMonth(month))
        return Date(1, month + 1, year);
    return Date(day + 1, month, year);
}

Date Date::PreviousDay() const
{
    if (day == 1 && month == 1)
        return Date(31, 12, year - 1);
    if (day == 1)
        return Date(DaysInMonth(month - 1), month - 1, year);
    return Date(day - 1, month, year);
}

bool Date::IsLeap() const
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

short Date::WeekNumber() const
{
    int january_first_week_day = (Date(1, 1, year).DaysFromStart() + 6) % 7 + 1;
    qDebug() << january_first_week_day;
    int week_number = (Date(day, month, year).DaysFromStart() - Date(1, 1, year).DaysFromStart() + january_first_week_day - 1) / 7 + 1;
    return (short)week_number;
}

int Date::DaysFromStart() const
{
    int result = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; i++) {
        result += DaysInMonth(i);
        qDebug() << DaysInMonth(month) << month;
    }
    result += day;
    return result;
}

int Date::DaysTillYourBithday(Date birthdaydate) const
{
    int days_left = this->Difference(Date(birthdaydate.GetDay(), birthdaydate.GetMonth(), year));
    if (days_left <= 0)
        return -days_left;
    return -this->Difference(Date(birthdaydate.GetDay(), birthdaydate.GetMonth(), year + 1));
}

int Date::Difference(Date date) const
{
    return this->DaysFromStart() - date.DaysFromStart();
}

int Date::Duration(Date date) const
{
    return qAbs(this->DaysFromStart() - date.DaysFromStart());
}

QString Date::DateToString() const
{
    QString date_str = "";
    date_str += (day < 10 ? "0" : "") + QString::number(day) + "." + (month < 10 ? "0" : "") + QString::number(month) + ".";
    if (year >= 1000)
        date_str += QString::number(year);
    else if (year >= 100)
        date_str += "0" + QString::number(year);
    else if (year >= 10)
        date_str += "00" + QString::number(year);
    else
        date_str += "000" + QString::number(year);
    return date_str;
}
