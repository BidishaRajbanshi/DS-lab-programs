#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Holder {
    char name[50];
    struct Date dob;
    char address[100];
    char nationality[30];
};

struct Passport {
    char passport_number[15];
    struct Date issue_date;
    struct Date expiry_date;
    char issuing_country[30];
    struct Holder holder;
};
