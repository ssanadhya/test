#include <iostream>

#include "ParentClass.h"
#include "ChildClass.h"
#include "ChildClass-Impl.h"

/* 
Sample output
$ g++ *.cpp -o out.exe
$ ./out.exe 
Parent1 func1 Parent Function 1
Parent1 func2 Parent Function 2
Child1 func1 Child function 1
Child1 func2 Child function 2
Parent2 func1 Child function 1
Parent2 func2() Parent Function 2
*/

int main(){
    ParentClass parent1;
    ChildClass<int> child1(2);
    ParentClass* parent2 = &child1;

    std::cout << "Parent1 func1 " << parent1.func1() << std::endl;
    std::cout << "Parent1 func2 " << parent1.func2() << std::endl;

std::cout << "Child1 func1 " << child1.func1() << std::endl;
    std::cout << "Child1 func2 " << child1.func2<int>() << std::endl;


std::cout << "Parent2 func1 " << parent2->func1() << std::endl;
std::cout << "Parent2 func2() " << parent2->func2() << std::endl;

// Compiler error
// std::cout << "Parent2 func2<int>()" << parent2->func2<int>() << std::endl;   
}
