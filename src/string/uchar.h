#ifndef UCHAR_H
#define UCHAR_H
#include <array>
namespace str {

union UCharData{
    unsigned short data;
    unsigned char s[2];
};

class UChar
{
public:
    UChar();
    UChar(char c);
    UChar(unsigned char c);
    UChar(unsigned short c);
    bool operator==(const UChar& other) const { return this->data_.data == other.data_.data; }
    bool operator!=(const UChar& other) const { return this->data_.data != other.data_.data;  }
    //char* to_ascii() const { return &data_; }
private:
    UCharData data_;
};

} //namespace
#endif // UCHAR_H
