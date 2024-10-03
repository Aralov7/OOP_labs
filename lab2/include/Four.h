#pragma once

#include <iostream>
#include <string>

class Four
{
public:
    Four();
    Four(const std::string &t);
    Four(const Four& other);
    Four(const size_t & n, unsigned char t = 0);
    Four(const std::initializer_list< unsigned char> &t);
    Four(Four&& other) noexcept; 
    
    virtual ~Four() noexcept;
private:
    size_t _size;
    unsigned char *_Four
};

