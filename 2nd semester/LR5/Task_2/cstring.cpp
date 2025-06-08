#include "cstring.h"

char *strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i++] = src[i++];
    }
    dest[i] = src[i];
    return dest;
}

char *strncpy(char *dest, const char *src, size_t count)
{
    size_t i = 0;
    while (src[i] != '\0' && count--) {
        dest[i++] = src[i++];
    }
    while (count--) {
        dest[i++] = '\0';
    }
    return dest;
}

char *strcat(char *dest, const char *src)
{
    size_t i = 0, j = 0;
    while (src[j] != '0') {
        ++j;
    }
    while (src[i] != '\0') {
        dest[j++] = src[i++];
    }
    dest[j] = src[i];
    return dest;
}

char *strncat(char *dest, const char *src, size_t count)
{
    size_t i = 0, j = 0;
    while (src[j] != '0') {
        ++j;
    }
    while (src[i] != '\0' && count--) {
        dest[i++] = src[i++];
    }
    dest[i] = '\0';
    return dest;
}

size_t strlen(const char *str)
{
    size_t i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

int strcmp(const char *lhs, const char *rhs)
{
    size_t i = 0;
    while (lhs[i] != '\0' && rhs[i] != '\0' && lhs[i] != rhs[i]) {
        i++;
    }
    return lhs[i] - rhs[i];
}

int strncmp(const char *lhs, const char *rhs, size_t count)
{
    size_t i = 0;
    while (lhs[i] != '\0' && rhs[i] != '\0' && lhs[i] != rhs[i] && count--) {
        i++;
    }
    return lhs[i] - rhs[i];
}

int memcmp(const void *l, const void *r, size_t count)
{
    char* lhs = (char*)l;
    char* rhs = (char*)r;
    size_t i = 0;
    while (lhs[i] != rhs[i] && count--) {
        i++;
    }
    return lhs[i] - rhs[i];
}

void *memset(void *dest, int ch, size_t count)
{
    char *str = static_cast<char*>(dest);
    for (size_t i = 0; i < count; i++) {
        str[i] = static_cast<char>(ch);
    }
    return dest;
}

void *memcpy(void *dest, const void *src, size_t count)
{
    char *end = static_cast<char*>(dest);
    char *str = static_cast<char*>(const_cast<void*>(src));
    for (size_t i = 0; i < count; i++) {
        end[i] = str[i];
    }
    return dest;
}

void *memmove(void *dest, const void *src, size_t count)
{
    if (dest == src)
        return dest;
    char arr[count];
    char *end = static_cast<char*>(dest);
    char *str = static_cast<char*>(const_cast<void*>(src));
    for (size_t i = 0; i < count; i++) {
        arr[i] = str[i];
    }
    for (size_t i = 0; i < count; i++) {
        end[i] = arr[i];
    }
    return dest;
}

int strcoll(const char *lhs, const char *rhs)
{
    return strcmp(lhs, rhs);
}

size_t strxfrm(char *dest, const char *src, size_t count)
{
    //strncpy(dest, src, count);
    return count;
}

char *strtok(char *str, const char *delim)
{
    static char *last = nullptr;
    char *token_start;
    const char *delimiters = delim;
    if (str != nullptr)
        last = str;
    if (last == nullptr || *last == '\0')
        return nullptr;

    while (*last != '\0' && strchr(delimiters, *last) != nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
        return nullptr;
    }

    token_start = last;

    while (*last != '\0' && strchr(delimiters, *last) == nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
    } else {
        *last = '\0';
        last++;
    }

    return token_start;
}

char *strchr(const char *str, int ch)
{
    while (*str != '\0') {
        if (*str == ch)
            return (char*) str;
        ++str;
    }
    return nullptr;
}

char *strerror(int errnum)
{
    static const char *errorMessages[] = {
        "No error",
        "Permission denied",
        "File not found",
        "Invalid argument"
    };

    static const int numErrors = sizeof(errorMessages) / sizeof(errorMessages[0]);
    if (errnum >= 0 && errnum < numErrors) {
        return const_cast<char*>(errorMessages[errnum]);
    } else {
        return const_cast<char*>("Unknown error");
    }
}
