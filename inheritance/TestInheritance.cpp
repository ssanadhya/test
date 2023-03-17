#include <iostream>

#include "ParentClass.h"
#include "ChildClass.h"

int main(){
    ParentClass parent1;
    ChildClass child1;

    std::cout << "Parent's name" << parent1.getName() << std::endl;
    std::cout << "Child's name" << child1.getName() << std::endl;
}
