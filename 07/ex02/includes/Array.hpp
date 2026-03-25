#pragma once

#include <stdexcept>

template<typename T>
class Array{
  private:
    T*      _array;
    size_t  _size;
  public:
    Array(void);
    Array(unsigned int size);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array(void);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size(void) const;
};

#include "Array.tpp"
