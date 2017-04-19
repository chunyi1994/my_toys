#ifndef BIT
#define BIT
#include <cstddef>
#include <assert.h>
#include <iostream>
namespace str {

class Bit {
    friend class Byte;
public:
    Bit& operator= (int bit);

    bool operator== (int bit) const;

    friend std::ostream& operator<< (std::ostream&, const Bit&);

    int value() const;
private:

    Bit(unsigned char& data, std::size_t n);

    unsigned char& data_;
    unsigned char mask_;
};

inline Bit &Bit::operator=(int bit) {
    assert(bit == 0 || bit == 1);
    if (1 == bit) {
        data_ |= mask_;
    } else {
        data_ &= ~mask_;
    }
    return *this;
}

inline bool Bit::operator==(int bit) const {
    assert(bit == 0 || bit == 1);
    if (bit == 1) {
        return data_ &mask_;
    } else {
        return !(data_ & mask_);
    }
}

inline std::ostream & operator<<(std::ostream &os, const Bit &bit) {
    os<<bit.value();
    return os;
}

int Bit::value() const {
    int value = 0;
    if (data_ & mask_) {
        value = 1;
    }
    return value;
}

inline Bit::Bit(unsigned char &data, std::size_t n)  :
    data_(data), mask_(1<<n) {
    assert(n < 8);
}

}
#endif // BIT

