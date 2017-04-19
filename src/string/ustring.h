#ifndef USTRING_H
#define USTRING_H
#include <vector>
#include <algorithm>
#include "uchar.h"
namespace str {


class UString
{
public:
    typedef UChar TypeValue;
    typedef UChar& Reference;
    typedef const UChar& ConstReference;
    typedef typename std::vector<TypeValue>::iterator Iterator;
    typedef typename std::vector<TypeValue>::const_iterator ConstIterator;
    typedef typename std::vector<TypeValue>::reverse_iterator ReverseIterator;
    typedef typename std::vector<TypeValue>::const_reverse_iterator ConstReverseIterator;

public:
    UString();
    UString(const std::string& utf8str);
    Reference at(std::size_t n) { return datas_[n]; }
    ConstReference at(std::size_t n) const { return datas_[n]; }
    Reference operator[] (std::size_t n) { return at(n); }
    ConstReference operator[] (std::size_t n)  const { return at(n); }
    Reference front() { return datas_.front(); }
    ConstReference front() const { return datas_.front(); }
    Reference back() { return datas_.back(); }
    ConstReference back() const { return datas_.back(); }
    bool empty() const { return datas_.empty(); }
    std::size_t size() const { return datas_.size(); }
    std::size_t length() const { return datas_.size(); }

    Iterator begin() { return datas_.begin(); }
    ConstIterator begin() const { return datas_.begin(); }
    ConstIterator cbegin() const { return datas_.cbegin(); }
    ReverseIterator rbegin() { return datas_.rbegin(); }
    ConstReverseIterator rbegin() const { return datas_.rbegin(); }
    ConstReverseIterator crbegin() const { return datas_.crbegin(); }

    Iterator end() { return datas_.end(); }
    ConstIterator end() const { return datas_.end(); }
    ConstIterator cend() const { return datas_.cend(); }
    ReverseIterator rend() { return datas_.rend(); }
    ConstReverseIterator rend() const { return datas_.rend(); }
    ConstReverseIterator crend() const { return datas_.crend(); }

    Iterator erase(ConstIterator position) { return datas_.erase(position); }
    Iterator erase(ConstIterator first, ConstIterator last) { return datas_.erase(first, last); }
    UString& erase(std::size_t pos, std::size_t size);

    void clear() { datas_.clear(); }
    void reserve(std::size_t n) { datas_.reserve(n); }
    void resize(std::size_t n) { datas_.reserve(n); }
    std::size_t capacity() const { return datas_.capacity(); }

   static std::size_t npos() { return std::string::npos; }

//    std::size_t find(ConstReference c, std::size_t start_pos = 0)  ;
//    Iterator find(ConstReference c, Iterator pos) ;
//    Iterator find(ConstReference c, Iterator start, Iterator end) ;

    static UString from_utf8(const std::string& str);
private:
    std::vector<TypeValue> datas_;
};
} //namespace
#endif // USTRING_H
