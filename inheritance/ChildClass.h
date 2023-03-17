#pragma once

#include <string>

#include "ParentClass.h"

class ChildClass : public ParentClass {
    public:
        ChildClass();
        std::string getName();
};
