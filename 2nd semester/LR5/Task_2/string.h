#ifndef STRING_H
#define STRING_H

#include <memory>
#include <iterator>
#include "cstring.h"

class String
{
private:
    std::unique_ptr<char[]> _ptr;
    size_t _sz;
    size_t _cap;

    using iterator = char*;
    using const_iterator = const char*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    String();
    String(size_t count, char ch);
    String(const char* str, size_t count);
    String(const char* str);
    String(const String& other);
    String(String&& other) noexcept;
    String(const String& other, size_t pos);
    String(const String& other, size_t pos, size_t count);
    ~String();

    String& operator=(const String& str);
    String& operator=(String&& str) noexcept;
    String& operator=(const char* str);
    String& operator=(char ch);

    String& assign(const String& str);
    String& assign(String&& str) noexcept;
    String& assign(size_t count, char ch);
    String& assign(const char* s, size_t count);
    String& assign(const char* s);
    String& assign(const String& str, size_t pos, size_t count);

    char& at(size_t pos);
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    char& front();
    char& back();
    const char* data() const;
    const char* c_str() const;

    iterator begin();
    const_iterator cbegin() const noexcept;
    iterator end();
    const_iterator cend() const noexcept;
    reverse_iterator rbegin();
    const_reverse_iterator crbegin() const noexcept;
    reverse_iterator rend();
    const_reverse_iterator crend() const noexcept;

    bool empty() const;
    size_t size() const;
    size_t length() const;
    //size_t max_size() const;
    void reserve (size_t new_cap);
    size_t capacity() const;

    void clear();

    String& insert(size_t index, size_t count, char ch);
    String& insert(size_t index, const char* s);
    String& insert(size_t index, const char* s, size_t count);
    String& insert(size_t index, const String& str);
    String& insert(size_t index, const String& str, size_t s_index, size_t count);
    iterator insert(iterator pos, char ch);
    iterator insert(const_iterator pos, char ch);
    iterator insert(iterator pos, size_t count, char ch);
    iterator insert(const_iterator pos, size_t count, char ch);

    String& erase(size_t index, size_t count);
    iterator erase(iterator position );
    iterator erase(iterator first, iterator last );

    void push_back(char ch);
    void pop_back();

    String& append(size_t count, char ch);
    String& append(const char* s, size_t count);
    String& append(const char* s);
    String& append(const String& str);
    String& append(const String& str, size_t pos, size_t count);

    String& operator+=(const String& str);
    String& operator+=(char ch);
    String& operator+=(const char* s);

    String& replace(size_t pos, size_t count, const String& str);
    String& replace(const_iterator first, const_iterator last, const String& str);
    String& replace(size_t pos, size_t count, const String& str, size_t pos2, size_t count2);
    String& replace(size_t pos, size_t count, const char* cstr, size_t count2);
    String& replace(const_iterator first, const_iterator last, const char* cstr, size_t count2);
    String& replace(size_t pos, size_t count, const char* cstr);
    String& replace(const_iterator first, const_iterator last, const char* cstr);
    String& replace(size_t pos, size_t count, size_t count2, char ch);
    String& replace(const_iterator first, const_iterator last, size_t count2, char ch);

    size_t copy(char* dest, size_t count, size_t pos = 0) const;

    void resize(size_t count);
    void resize(size_t count, char ch);

    void swap(String& other) noexcept;

    String substr(size_t pos, size_t count) const;

    size_t find(const String& str, size_t pos = 0) const;
    size_t find(const char* s, size_t pos, size_t count) const;
    size_t find(const char* s, size_t pos = 0) const;
    size_t find(char ch, size_t pos = 0) const;
    //Other finds

    int compare(const String& str) const;
    int compare(size_t pos1, size_t count1, const String& str ) const;
    int compare(size_t pos1, size_t count1, const String& str, size_t pos2, size_t count2) const;
    int compare(const char* s ) const;
    int compare(size_t pos1, size_t count1, const char* s) const;
    int compare(size_t pos1, size_t count1, const char* s, size_t count2) const;

    String operator+(const String& rhs);
    bool operator==(const String& rhs) noexcept;
    bool operator!=(const String& rhs) noexcept;
    bool operator<(const String& rhs) noexcept;
    bool operator>(const String& rhs) noexcept;
    bool operator<=(const String& rhs) noexcept;
    bool operator>=(const String& rhs) noexcept;
};

#endif // STRING_H
