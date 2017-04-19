#include "ustring.h"
#include <iterator>
#include "byte.h"
namespace str {

UString::UString() :
    datas_()
{

}

//UString::UString(const std::string &utf8str) {
//    std::vector<Byte> bytes;
//    for () {
//    }
//}

UString &UString::erase(std::size_t pos, std::size_t size) {
    auto begin_iter = cbegin() + pos;
    auto end_iter = begin_iter + size;
    erase(begin_iter, end_iter);
    return *this;
}

//std::size_t UString::find(UString::ConstReference c, std::size_t start_pos) {
//    if (start_pos >= length()) {
//        return npos();
//    }
//    auto iter_begin = cbegin() + start_pos;
//    auto iter_find = std::find(iter_begin, cend(), c);
//    if (iter_find == cend()) {
//        return npos();
//    }
//    return std::distance(iter_begin, iter_find);
//}

//UString::Iterator UString::find(UString::ConstReference c, UString::Iterator pos)  {
//    return std::find(pos, end(), c);
//}

//UString::Iterator UString::find(UString::ConstReference c, UString::Iterator start, UString::Iterator end) {
//    return std::find(start, end, c);
//}

UString UString::from_utf8(const std::string &)
{
    return UString();
}

} //namespace
