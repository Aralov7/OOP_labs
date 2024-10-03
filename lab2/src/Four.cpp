#include "Four.h"

Four::Four() 
{
 _size{0};
 _array{nullptr};
}


Four::Four(const std::string &t){
    _array = new unsigned char[t.size()];
    _size = t.size

    for(size_t i{0};i<_size;++i) _array[i] = t[t.size() - i];
}

Four::Four(const Four &other){
    _size = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0}; i < _size; ++i) _array[i] = other._array[i];
}

Four::~Four() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}