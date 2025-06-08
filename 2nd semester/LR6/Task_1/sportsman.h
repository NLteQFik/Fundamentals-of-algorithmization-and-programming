#ifndef SPORTSMAN_H
#define SPORTSMAN_H

struct sportsman
{
    int age;
    double height;
    char category = '\0';
    bool professional;
    static const int MaxNameLength = 20;
    char name[MaxNameLength]{'\0'};
    static const int MaxResultsLength = 3;
    double results[MaxResultsLength];
};

#endif // SPORTSMAN_H
