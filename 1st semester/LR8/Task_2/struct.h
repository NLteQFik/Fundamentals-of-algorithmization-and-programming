#pragma once

#define NAME_SIZE 33
#define DATE_SIZE 9
#define STAT_SIZE 23

typedef struct radio {
    char name[NAME_SIZE] {'\0'};
    char mark[NAME_SIZE] {'\0'};
    char date[DATE_SIZE] {'\0'};
    char state[STAT_SIZE] {'\0'};
    union {
        float price;
        int weight;
    } details;
} radio;