#pragma once

#include<iostream>
#include<string>

template<typename T, typename F>
void  iter(T *array, const size_t size, void (*function)(F)){
  for (size_t i = 0; i < size; i++){
    function(array[i]);
  }
}
