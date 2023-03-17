#include "ChildClass.h"

#include <string>

template <typename T>
ChildClass<T>::ChildClass(T value): member(value){}

template <typename T>
std::string ChildClass<T>::
func1() {
    return "Child function 1";
}

template <typename T>
template <typename U> 
std::string ChildClass<T>::
func2() {
    return "Child function 2";
}