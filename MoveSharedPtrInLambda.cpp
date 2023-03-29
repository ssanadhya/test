#include <iostream>
#include <memory>

/**
 * This is a sample code from
 * https://stackoverflow.com/questions/43319352/stdmove-with-stdshared-ptr-in-lambda 
 * to test move semantics with lambdas in C++
 *
 * Compare the outputs of
 *
 * g++ -std=c++14 -o out.exe MoveSharedPtrInLambda.cpp && ./out.exe
 *
 * 1 0x55e5e5680ec0 #refs: 1
 * 3 0x55e5e5680ec0 #refs: 1
 * 2 0 #refs: 0
 *
 * g++ -std=c++14 -o outLambda1.exe MoveSharedPtrInLambda.cpp -DLAMBDA1 && ./outLambda1.exe
 * 1 0x55f7d4581ec0 #refs: 1
 * 3 0x55f7d4581ec0 #refs: 3
 * 2 0x55f7d4581ec0 #refs: 2
 * 
 *  g++ -std=c++14 -o outLambda2.exe MoveSharedPtrInLambda.cpp -DLAMBDA2 && ./outLambda2.exe
 * 1 0x55b4a05dfec0 #refs: 1
 * 3 0x55b4a05dfec0 #refs: 1
 * 2 0 #refs: 0
*/

void f(std::shared_ptr<int> ptr) {
  std::cout << 3 << " " << ptr.get() << " #refs: " << ptr.use_count() << std::endl;
}

int main() {
  auto ptr = std::make_shared<int>(42);
  std::cout << 1 << " " << ptr.get() << " #refs: " << ptr.use_count() << std::endl;
#ifdef LAMBDA1
  auto lambda = [ptr]() {
#endif
#ifdef LAMBDA2
  auto lambda = [&ptr]() {
#endif
    f(std::move(ptr));
    std::cout << 2 << " " << ptr.get() << " #refs: " << ptr.use_count() << std::endl;
#if defined LAMBDA1 || defined LAMBDA2
  };
  lambda();
#endif

}