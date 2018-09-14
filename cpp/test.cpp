#include <iostream>
#include <utility>
 
void f(int& x) {
    std::cout << "lvalue reference overload f(" << x << ")\n";
}
 
void f(const int& x) {
    std::cout << "lvalue reference to const overload f(" << x << ")\n";
}
 
void f(int&& x) {
    std::cout << "rvalue reference overload f(" << x << ")\n";
}
 
int main() {
  return 0;
}