#pragma once

#include <string>

#include "ParentClass.h"

template <typename T>
class ChildClass : public ParentClass {
    public:
        ChildClass(T value);

        std::string func1() override;

        template <typename U>
        std::string func2();

    private:
        T member;
};
