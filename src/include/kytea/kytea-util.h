#ifndef KYTEA_UTIL__
#define KYTEA_UTIL__

// #include <iostream>
#include <kytea/kytea-dspec.h>
#include <vector>
#include <stdexcept>
#include <sstream>

namespace kytea {

#define THROW_ERROR(msg) do {                   \
    std::ostringstream oss;                     \
    oss << msg;                                 \
    throw std::runtime_error(oss.str()); }       \
  while (0);

template <class T>
void checkPointerEqual(const T* lhs, const T* rhs);

// Vector equality checking function
template <class T>
KYTEA_API void checkValueVecEqual(const std::vector<T> & a, const std::vector<T> & b);

// Vector equality checking with null pointers
template <class T>
KYTEA_API void checkValueVecEqual(const std::vector<T> * a, const std::vector<T> * b);

// Vector equality checking function
template <class T>
KYTEA_API void checkPointerVecEqual(const std::vector<T*> & a, const std::vector<T*> & b);

// Vector equality checking with null pointers
template <class T>
KYTEA_API void checkPointerVecEqual(const std::vector<T*> * a, const std::vector<T*> * b);

};

#endif // KYTEA_UTIL__
