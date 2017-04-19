#ifndef BYTE
#define BYTE
#include <cstddef>
#include <assert.h>
#include "bit.h"
namespace str {


class Byte {
public:
    Byte();
    explicit Byte(char byte);
    //explicit Byte(unsigned char byte);
    Byte& operator=(char byte);
    bool operator==(char byte) const;
    Bit operator[] (std::size_t n);
    const Bit operator[] (std::size_t n) const;
    Bit at(std::size_t n);
    const Bit at(std::size_t n) const;
    unsigned char to_uchar() const;
    friend std::ostream& operator<<(std::ostream& os, const Byte& byte);
private:
    mutable unsigned char data_;
};

inline Byte::Byte() : data_(0)
{
}

inline Byte::Byte(char byte) : data_(byte)
{
}


inline Byte &Byte::operator=(char byte) {
    data_ = byte;
    return *this;
}

inline bool Byte::operator==(char byte) const {
    return data_ == byte;
}

inline Bit Byte::operator[](std::size_t n) {
    assert(n < 8);
    return Bit(data_, 7 - n);
}

const Bit Byte::operator[](std::size_t n) const{
    assert(n < 8);
    const Bit b{data_, 7 - n};
    return b;
}

inline Bit Byte::at(std::size_t n) {
    assert(n < 8);
    return Bit(data_, 7 - n);
}

inline const Bit Byte::at(std::size_t n) const {
    assert(n < 8);
    const Bit b{data_, 7 - n};
    return b;
}

inline unsigned char Byte::to_uchar() const {
    return data_;
}

inline std::ostream& operator<<(std::ostream &os, const Byte &byte) {
    os << "0x";
    for (int i = 0; i < 8; ++i) {
        os<<byte.at(i);
    }
    return os;
}

} //namespace
#endif // BYTE

