#include "string.h"

String::String() : _ptr(std::make_unique<char[]>(1)), _sz(0), _cap(0)
{
    _ptr[0] = '\0';
}

String::String(size_t count, char ch) : _ptr(std::make_unique<char[]>(count + 1)), _sz(count), _cap(count)
{
    for (size_t i = 0; i < _sz; i++) {
        _ptr[i] = ch;
    }
    _ptr[_sz] = '\0';
}

String::String(const char *str, size_t count) : _ptr(std::make_unique<char[]>(count + 1)), _sz(count), _cap(count)
{
    memcpy(_ptr.get(), str, count);
    _ptr[count] = '\0';
}

String::String(const char *str)
{
    size_t length = strlen(str);
    _ptr = std::make_unique<char[]>(length + 1);
    _sz = length;
    _cap = length;
    memcpy(_ptr.get(), str, length);
    _ptr[length] = '\0';
}

String::String(const String &other) : _ptr(std::make_unique<char[]>(other._cap + 1)), _sz(other._sz), _cap(other._cap)
{
    strcpy(this->_ptr.get(), other._ptr.get());
}

String::String(String &&other) noexcept : _ptr(std::move(other._ptr)), _sz(other._sz), _cap(other._cap)
{
    other._ptr = std::make_unique<char[]>(1);
    other._sz = 0;
    other._cap = 0;
    _ptr[0] = '\0';
}

String::String(const String &other, size_t pos)
{
    size_t length = other._cap - pos;
    length = length > 0 ? length : 0;
    _ptr = std::make_unique<char[]>(length + 1);
    _sz = length;
    _cap = length;
    strncpy(this->_ptr.get(), other._ptr.get(), length);
    _ptr[length] = '\0';
}

String::String(const String &other, size_t pos, size_t count)
{
    size_t length = std::min(other._cap - pos, count);
    length = length > 0 ? length : 0;
    _ptr = std::make_unique<char[]>(length + 1);
    _sz = length;
    _cap = length;
    strncpy(this->_ptr.get(), other._ptr.get(), length);
    _ptr[length] = '\0';
}

String::~String()
{
    _ptr.reset();
    _sz = 0;
    _cap = 0;
}

String &String::operator=(const String &str)
{
    if (&str != this)
    {
        _ptr = std::make_unique<char[]>(str._cap + 1);
        _sz = str._sz;
        _cap = str._cap;
        strcpy(_ptr.get(), str._ptr.get());
    }
    return *this;
}

String &String::operator=(String&& str) noexcept
{
    _ptr = std::move(str._ptr);
    _sz = str._sz;
    _cap = str._cap;
    str._ptr = std::make_unique<char[]>(1);
    str._sz = 0;
    str._cap = 0;
    str._ptr[0] = '\0';
    return *this;
}

String &String::operator=(const char* str)
{
    size_t length = strlen(str);
    _ptr = std::make_unique<char[]>(length + 1);
    _sz = length;
    _cap = length;
    memcpy(_ptr.get(), str, length);
    _ptr[length] = '\0';
    return *this;
}

String &String::operator=(char ch)
{
    _ptr = std::make_unique<char[]>(2);
    _sz = 1;
    _cap = 1;
    _ptr[0] = ch;
    _ptr[1] = '\0';
    return *this;
}

String &String::assign(const String &str)
{
    return *this = str;
}

String &String::assign(String &&str) noexcept
{
    return *this = std::move(str);
}

String &String::assign(size_t count, char ch)
{
    clear();
    resize(count, ch);
    return *this;
}

String &String::assign(const char *s, size_t count)
{
    _ptr = std::make_unique<char[]>(count + 1);
    _sz = count;
    _cap = count;
    memcpy(_ptr.get(), s, count);
    _ptr[count] = '\0';
    return *this;
}

String &String::assign(const char *s)
{
    return assign(s, strlen(s));
}

String &String::assign(const String &str, size_t pos, size_t count)
{
    size_t length = std::min(count, str.size() - pos);
    _ptr = std::make_unique<char[]>(length + 1);
    _sz = length;
    _cap = length;
    memcpy(_ptr.get(), str._ptr.get(), length);
    return *this;
}

char &String::at(size_t pos)
{
    if (pos >= _sz)
        throw "Out of range!";
    return _ptr[pos];
}

char &String::operator[](size_t pos)
{
    return _ptr[pos];
}

const char &String::operator[](size_t pos) const
{
    return _ptr[pos];
}

char &String::front()
{
    return _ptr[0];
}

char &String::back()
{
    return _ptr[_sz - 1];
}

const char *String::data() const
{
    return _ptr.get();
}

const char *String::c_str() const
{
    return _ptr.get();
}

String::iterator String::begin()
{
    return _ptr.get();
}

String::const_iterator String::cbegin() const noexcept
{
    return _ptr.get();
}

String::iterator String::end()
{
    return _ptr.get() + _sz;
}

String::const_iterator String::cend() const noexcept
{
    return _ptr.get() + _sz;
}

String::reverse_iterator String::rbegin()
{
    return std::reverse_iterator<iterator>(_ptr.get() + _sz - 1);
}

String::const_reverse_iterator String::crbegin() const noexcept
{
    return std::reverse_iterator<iterator>(_ptr.get() + _sz - 1);
}

String::reverse_iterator String::rend()
{
    return std::reverse_iterator<iterator>(_ptr.get() - 1);
}

String::const_reverse_iterator String::crend() const noexcept
{
    return std::reverse_iterator<iterator>(_ptr.get() - 1);
}

bool String::empty() const
{
    return _sz == 0;
}

size_t String::size() const
{
    return _sz;
}

size_t String::length() const
{
    return _sz;
}

void String::reserve(size_t new_cap)
{
    if (new_cap <= _cap)
        return;
    std::unique_ptr<char[]>new_ptr(std::make_unique<char[]>(new_cap + 1));
    memcpy(new_ptr.get(), _ptr.get(), _sz);
    _ptr = std::move(new_ptr);
    _cap = new_cap;
}

size_t String::capacity() const
{
    return _cap;
}

void String::clear()
{
    resize(0);
}

String &String::insert(size_t index, size_t count, char ch)
{
    if (index > _sz)
        throw "Out of range!";
    reserve(_sz + count);
    memmove(_ptr.get() + index + count, _ptr.get() + index, _sz - index + 1);
    for (size_t i = 0; i < count; ++i) {
        _ptr[index + i] = ch;
    }
    _sz += count;
    return *this;
}

String &String::insert(size_t index, const char *s)
{
    if (index > _sz)
        throw "Out of range!";
    size_t length = strlen(s);
    reserve(_sz + length);
    memmove(_ptr.get() + index + length, _ptr.get() + index, _sz - index + 1);
    memcpy(_ptr.get() + index, s, length);
    _sz += length;
    return *this;
}

String &String::insert(size_t index, const char *s, size_t count)
{
    if (index > _sz)
        throw "Out of range!";
    reserve(_sz + count);
    memmove(_ptr.get() + index + count , _ptr.get() + index, _sz - index + 1);
    memcpy(_ptr.get() + index, s, count);
    _sz += count;
    return *this;
}

String &String::insert(size_t index, const String &str)
{
    if (index > _sz)
        throw "Out of range!";
    reserve(_sz + str._sz);
    memmove(_ptr.get() + index + str._sz , _ptr.get() + index, _sz - index + 1);
    memcpy(_ptr.get() + index, str._ptr.get(), str._sz);
    _sz += str._sz;
    return *this;
}

String &String::insert(size_t index, const String &str, size_t s_index, size_t count)
{
    if (index > _sz || s_index > str._sz)
        throw "Out of range!";
    String t(std::move(str.substr(s_index, count)));
    reserve(_sz + t._sz);
    memmove(_ptr.get() + index + t._sz , _ptr.get() + index, _sz - index + 1);
    memcpy(_ptr.get() + index, t._ptr.get(), t._sz);
    _sz += t._sz;
    return *this;
}

String::iterator String::insert(iterator pos, char ch)
{
    size_t length = pos - begin();
    reserve(_sz + 1);
    memmove(_ptr.get() + length + 1, _ptr.get() + length, _sz - length + 1);
    _ptr[length] = ch;
    ++_sz;
    return pos;
}

String::iterator String::insert(const_iterator pos, char ch)
{
    size_t length = pos - begin();
    reserve(_sz + 1);
    memmove(_ptr.get() + length + 1, _ptr.get() + length, _sz - length + 1);
    _ptr[length] = ch;
    ++_sz;
    return const_cast<iterator>(pos);
}

String::iterator String::insert(iterator pos, size_t count, char ch)
{
    size_t length = pos - begin();
    reserve(_sz + 1);
    memmove(_ptr.get() + length + count, _ptr.get() + length, _sz - length + 1);
    for (size_t i = 0; i < count; i++) {
        _ptr[length + i] = ch;
    }
    _sz += count;
    return pos;
}

String::iterator String::insert(const_iterator pos, size_t count, char ch)
{
    size_t length = pos - begin();
    reserve(_sz + 1);
    memmove(_ptr.get() + length + count, _ptr.get() + length, _sz - length + 1);
    for (size_t i = 0; i < count; i++) {
        _ptr[length + i] = ch;
    }
    _sz += count;
    return const_cast<iterator>(pos);
}

String &String::erase(size_t index, size_t count)
{
    if (index > _sz)
        throw "Out of range!";
    size_t length = std::min(count, _sz - index);
    memmove(_ptr.get() + index, _ptr.get() + index + length, _sz - index - length + 1);
    _sz -= length;
    return *this;
}

String::iterator String::erase(iterator position)
{
    size_t index = position - begin();
    memmove(_ptr.get() + index, _ptr.get() + index + 1, _sz - index);
    --_sz;
    return position;
}

String::iterator String::erase(iterator first, iterator last)
{
    size_t index = first - begin();
    size_t count = last - first;
    memmove(_ptr.get() + index, _ptr.get() + index + count, _sz - index - count + 1);
    _sz -= count;
    return first;
}

void String::push_back(char ch)
{
    ++_sz;
    if (_sz > _cap)
    {
        reserve(_cap == 0 ? 1 : _cap * 2);
    }
    _ptr[_sz - 1] = ch;
    _ptr[_sz] = '\0';
}

void String::pop_back()
{
    if (_sz)
    {
        --_sz;
        _ptr[_sz] = '\0';
    }
    return;
}

String &String::append(size_t count, char ch)
{
    reserve(_sz + count);
    for (size_t i = 0; i < count; i++)
    {
        _ptr[_sz + i] = ch;
    }
    _sz += count;
    _ptr[_sz] = '\0';
    return *this;
}

String &String::append(const char *s, size_t count)
{
    reserve(_sz + count);
    for (size_t i = 0; i < count; i++)
    {
        _ptr[_sz + i] = s[i];
    }
    _sz += count;
    _ptr[_sz] = '\0';
    return *this;
}

String &String::append(const char *s)
{
    size_t length = strlen(s);
    reserve(_sz + length);
    for (size_t i = 0; i < length; i++)
    {
        _ptr[_sz + i] = s[i];
    }
    _sz += length;
    _ptr[_sz] = '\0';
    return *this;
}

String &String::append(const String &str)
{
    reserve(_sz + str._sz);
    for (size_t i = 0; i < str._sz; i++)
    {
        _ptr[_sz + i] = str[i];
    }
    _sz += str._sz;
    _ptr[_sz] = '\0';
    return *this;
}

String &String::append(const String &str, size_t pos, size_t count)
{
    String t(std::move(str.substr(pos, count)));
    reserve(_sz + t._sz);
    for (size_t i = 0; i < t._sz; i++)
    {
        _ptr[_sz + i] = str[i];
    }
    _sz += t._sz;
    _ptr[_sz] = '\0';
    return *this;
}

String &String::operator+=(const String &str)
{
    append(str);
    return *this;
}

String &String::operator+=(char ch)
{
    append(1, ch);
    return *this;
}

String &String::operator+=(const char* s)
{
    append(s);
    return *this;
}

String &String::replace(size_t pos, size_t count, const String &str)
{
    size_t length = std::min(pos + count, _sz);
    erase(pos, length);
    insert(pos, str);
    return *this;
}

String &String::replace(const_iterator first, const_iterator last, const String &str)
{
    erase(const_cast<iterator>(first), const_cast<iterator>(last));
    insert(first - cbegin(), str);
    return *this;
}

String &String::replace(size_t pos, size_t count, const String &str, size_t pos2, size_t count2)
{
    size_t length = std::min(pos + count, _sz);
    erase(pos, length);
    insert(pos, str.substr(pos2, count2));
    return *this;
}

String &String::replace(size_t pos, size_t count, const char *cstr, size_t count2)
{
    size_t length = std::min(pos + count, _sz);
    erase(pos, length);
    insert(pos, cstr, count2);
    return *this;
}

String &String::replace(const_iterator first, const_iterator last, const char *cstr, size_t count2)
{
    erase(const_cast<iterator>(first), const_cast<iterator>(last));
    insert(first - cbegin(), cstr, count2);
    return *this;
}

String &String::replace(size_t pos, size_t count, const char *cstr)
{
    size_t length = std::min(pos + count, _sz);
    erase(pos, length);
    insert(pos, cstr);
    return *this;
}

String &String::replace(const_iterator first, const_iterator last, const char *cstr)
{
    erase(const_cast<iterator>(first), const_cast<iterator>(last));
    insert(first - cbegin(), cstr);
    return *this;
}

String &String::replace(size_t pos, size_t count, size_t count2, char ch)
{
    size_t length = std::min(pos + count, _sz);
    erase(pos, length);
    insert(pos, count2, ch);
    return *this;
}

String &String::replace(const_iterator first, const_iterator last, size_t count2, char ch)
{
    erase(const_cast<iterator>(first), const_cast<iterator>(last));
    insert(first - cbegin(), count2, ch);
    return *this;
}

size_t String::copy(char* dest, size_t count, size_t pos) const
{
    size_t length = std::min(pos + count, _sz);
    memcpy(dest, substr(pos, length).c_str(), count);
    return substr(pos, length).size();
}

void String::resize(size_t count)
{
    reserve(count);
    for (size_t i = _sz; i < count; i++)
        _ptr[i] = '\0';
    _sz = count;
    _ptr[_sz] = '\0';
}

void String::resize(size_t count, char ch)
{
    reserve(count);
    for (size_t i = _sz; i < count; i++)
        _ptr[i] = ch;
    _sz = count;
    _ptr[_sz] = '\0';
}

void String::swap(String &other) noexcept
{
    String temp = std::move(other);
    other = std::move(*this);
    *this = std::move(temp);
}

String String::substr(size_t pos, size_t count) const
{
    size_t length = std::min(pos + count, _sz);
    return String(*this, pos, length);
}

size_t String::find(const String &str, size_t pos) const
{
    size_t k = 0;
    while (str._sz + k + pos <= _sz)
    {
        for (size_t i = 0; i < str._sz; i++)
        {
            if (str[i] != _ptr[i + pos + k]) {
                return k + pos;
            }
        }
        ++k;
    }
    return -1;
}

size_t String::find(const char *s, size_t pos, size_t count) const
{
    size_t k = 0;
    while (count + k + pos <= _sz)
    {
        for (size_t i = 0; i < count; i++)
        {
            if (s[i] != _ptr[i + pos + k]) {
                return k + pos;
            }
        }
        ++k;
    }
    return -1;
}

size_t String::find(const char *s, size_t pos) const
{
    return find(s, pos, strlen(s));
}

size_t String::find(char ch, size_t pos) const
{
    size_t k = 0;
    while (k + pos <= _sz)
    {
        if (ch == _ptr[pos + k]) {
            return pos + k;
        }
        ++k;
    }
    return -1;
}

int String::compare(const String &str) const
{
    for (size_t i = 0; i <= _sz; i++)
    {
        if (_ptr[i] != str[i])
            return _ptr[i] - str[i];
    }
    return 0;
}

int String::compare(size_t pos1, size_t count1, const String &str) const
{
    size_t length1 = std::min(pos1 + count1, str._sz);
    return compare(str.substr(pos1, length1));
}

int String::compare(size_t pos1, size_t count1, const String &str, size_t pos2, size_t count2) const
{
    size_t length2 = std::min(pos2 + count2, str._sz);
    size_t length1 = std::min(pos1 + count1, _sz);
    return (*this).substr(pos1, length1).compare(str.substr(pos2, length2));
}

int String::compare(const char *s) const
{
    for (size_t i = 0; i <= _sz; i++)
    {
        if (_ptr[i] != s[i])
            return _ptr[i] - s[i];
    }
    return 0;
}

int String::compare(size_t pos1, size_t count1, const char *s) const
{
    size_t length1 = std::min(pos1 + count1, _sz);
    for (size_t i = pos1; i <= pos1 + length1; i++)
    {
        if (_ptr[i] != s[i - pos1])
            return _ptr[i] - s[i - pos1];
    }
    return 0;
}

int String::compare(size_t pos1, size_t count1, const char *s, size_t count2) const
{
    size_t length1 = std::min(pos1 + count1, _sz);
    size_t i = pos1;
    for (; i < pos1 + count2 && i < length1; i++)
    {
        if (_ptr[i] != s[i - pos1])
            return _ptr[i] - s[i - pos1];
    }
    return _ptr[i] - '\0';
}

String String::operator+(const String &rhs)
{
    return append(rhs);
}

bool String::operator==(const String &rhs) noexcept
{
    return compare(rhs) == 0;
}

bool String::operator!=(const String &rhs) noexcept
{
    return compare(rhs) != 0;
}

bool String::operator<(const String &rhs) noexcept
{
    return compare(rhs) < 0;
}

bool String::operator>(const String &rhs) noexcept
{
    return compare(rhs) > 0;
}

bool String::operator<=(const String &rhs) noexcept
{
    return compare(rhs) <= 0;
}

bool String::operator>=(const String &rhs) noexcept
{
    return compare(rhs) >= 0;
}

