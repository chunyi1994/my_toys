#include "uchar.h"
#include <stdio.h>
#include <iostream>
namespace str {
UChar::UChar() :
    data_()
{
    data_.data = 0;
}

UChar::UChar(char c) {
    data_.data = (unsigned short)c;
}

UChar::UChar(unsigned char c) {
    data_.data = (unsigned short)c;
}

UChar::UChar(unsigned short c) :
    data_()
{
    data_.data = c;
}


} //namespace
