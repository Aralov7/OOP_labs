// ComplexType.h

#ifndef COMPLEX_TYPE_H
#define COMPLEX_TYPE_H

#include <string>

struct ComplexType {
    int a;
    double b;
    std::string c;

    ComplexType(int a_, double b_, const std::string& c_);
};

#endif // COMPLEX_TYPE_H