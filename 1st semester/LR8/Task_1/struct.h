#pragma once

#define NAME_SIZE 35
#define DATE_SIZE 9

typedef struct product {
    char name[NAME_SIZE] {'\0'};
    int quantity;
    float price;
    int weight;
    char date[DATE_SIZE] {'\0'};
    union {
        long long mass;
        double cost;
    } details;
} product;