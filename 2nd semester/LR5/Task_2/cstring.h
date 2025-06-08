#ifndef CSTRING_H
#define CSTRING_H

#include <memory>

    char* strcpy(char* dest, const char* src);
    char* strncpy(char* dest, const char* src, size_t count);
    char* strcat(char* dest, const char* src);
    char* strncat(char* dest, const char* src, size_t count);
    size_t strxfrm(char* dest, const char* src, size_t count);

    size_t strlen(const char* str);
    int strcmp(const char* lhs, const char* rhs);
    int strncmp(const char* lhs, const char* rhs, size_t count);
    int strcoll(const char* lhs, const char* rhs);
    char* strtok(char* str, const char* delim);
    static char *strchr(const char *str, int ch);

    int memcmp(const void* lhs, const void* rhs, size_t count);
    void* memset(void* dest, int ch, size_t count);
    void* memcpy(void* dest, const void* src, size_t count);
    void* memmove(void* dest, const void* src, size_t count);

    char* strerror(int errnum);

#endif // CSTRING_H
