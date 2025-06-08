#ifndef BITSET_H
#define BITSET_H

#include <cstddef>
#include <cstdint>
#include <string>

template <std::size_t N>
class Bitset
{
private:
    static const size_t syst = 8 * sizeof(size_t);
    static const size_t _blocks_quantity = 1 + (N - 1) / syst;
    size_t _blocks[_blocks_quantity];

    class Reference
    {
    private:
        size_t* _block;
        size_t _pos;
    public:
        Reference(size_t* block, size_t pos) : _block(block), _pos(pos % syst) {}
        Reference(const Reference& x)
        {
            if (x)
                *_block |= static_cast<size_t>(1 << _pos);
            else
                *_block &= static_cast<size_t>(~(1 << _pos));
            return *this;
        }

        Reference& operator=(bool x)
        {
            if (x)
                *_block |= static_cast<size_t>(1 << _pos);
            else
                *_block &= static_cast<size_t>(~(1 << _pos));
            return *this;
        }
        Reference& operator=(const Reference& x)
        {
            if (x)
                *_block |= static_cast<size_t>(1 << _pos);
            else
                *_block &= static_cast<size_t>(~(1 << _pos));
            return *this;
        }

        operator bool() const
        {
            return (*_block >> _pos) & 1;
        }

        bool operator~() const
        {
            if (*this)
                return 0;
            return 1;
        }

        Reference& flip()
        {
            *_block ^= 1 << _pos;
        }
    };

public:
    Bitset()
    {
        for (size_t i = 0; i < _blocks_quantity; i++)
            _blocks[i] = 0;
    }
    Bitset(size_t val)
    {
        for (size_t i = 0; i < _blocks_quantity; i++)
            _blocks[i] = 0;
        _blocks[0] = val;
    }
    Bitset(const Bitset<N> &other)
    {
        for (int i = 0; i < _blocks_quantity; i++)
            _blocks[i] = other._blocks[i];
    }

    bool operator==(const Bitset& other) const
    {
        for (int i = 0; i < _blocks_quantity; i++)
            if (_blocks[i] != other._blocks[i])
                return false;
        return true;
    }
    bool operator!=(const Bitset& other) const
    {
        for (int i = 0; i < _blocks_quantity; i++)
            if (_blocks[i] == other._blocks[i])
                return false;
        return true;
    }

    bool operator[](size_t pos) const
    {
        return Reference(_blocks + pos / syst, pos);
    }
    Reference operator[](size_t pos)
    {
        return Reference(_blocks + pos / syst, pos);
    }
    bool test(size_t pos) const
    {
        if (pos >= N)
            throw "Out of range!";
        return Reference(const_cast<size_t*>(_blocks + pos / syst), pos);
    }

    bool all() const
    {
        return count() == N;
    }
    bool any() const
    {
        return count() != 0;
    }
    bool none() const
    {
        return count() == 0;
    }

    size_t count() const
    {
        size_t bits = 0;
        size_t temp;
        for (size_t i = 0; i < _blocks_quantity; i++) {
            temp = _blocks[i];
            while (temp) {
                temp &= (temp - 1);
                ++bits;
            }
        }
        return bits;
    }

    size_t size() const
    {
        return N;
    }

    Bitset& set()
    {
        for (size_t i = 0; i < _blocks_quantity; i++)
            _blocks[i] = ~0;
        return *this;
    }
    Bitset& set(size_t pos, bool value = true)
    {
        _blocks[0];
        if (pos >= N)
            throw "Out of range!";
        if (value)
            _blocks[pos / syst] |= static_cast<size_t>(1 << pos);
        else
            _blocks[pos / syst] &= static_cast<size_t>(~(1 << pos));
        return *this;
    }

    Bitset& reset()
    {
        for (size_t i = 0; i < _blocks_quantity; i++)
            _blocks[i] = 0;
        return *this;
    }
    Bitset& reset(size_t pos)
    {
        if (pos >= N)
            throw "Out of range!";
        _blocks[pos / syst] &= static_cast<size_t>(~(1 << pos));
        return *this;
    }

    Bitset& flip()
    {
        for (size_t i = 0; i < _blocks_quantity; i++)
            _blocks[i] = ~_blocks[i];
        return *this;
    }
    Bitset& flip(size_t pos)
    {
        if (pos >= N)
            throw "Out of range!";
        _blocks[pos / syst] ^= static_cast<size_t>(1 << pos);
        return *this;
    }

    std::string to_string(char zero = '0', char one = '1') const {
        std::string res(N, zero);
        for (int i = 0; i < N; i++)
            if (test(i))
                res[i] = one;
        return res;
    }

    unsigned long long to_ullong() const {
        if (N > 64)
            throw "Overflow!";
        return _blocks[0];
    }

    unsigned long to_ulong() const {
        if (N > 32)
            throw "Overflow!";
        return _blocks[0];
    }

    Bitset operator&(const Bitset<N> &other) const {
        Bitset<N> res;
        for (size_t i = 0; i < _blocks_quantity; i++)
            res._blocks[i] = _blocks[i] & other._blocks[i];
        return res;
    }
    Bitset operator|(const Bitset<N> &other) const {
        Bitset<N> res;
        for (size_t i = 0; i < _blocks_quantity; i++)
            res._blocks[i] = _blocks[i] | other._blocks[i];
        return res;
    }
    Bitset operator^(const Bitset<N> &other) const {
        Bitset<N> res;
        for (size_t i = 0; i < _blocks_quantity; i++)
            res._blocks[i] = _blocks[i] ^ other._blocks[i];
        return res;
    }
};

#endif // BITSET_H
