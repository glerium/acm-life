#include <iostream>
#include <string>
using std::cout, std::endl, std::string;
struct X {
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X& operator=(const X&) {cout << "operator=(const X&)" << endl; return *this;}
    ~X() {cout << "~X()" <<endl;}
};
void func() {
    X a,b;
    a = b;
    X tmp(a);
    return;
}
void fun_x(X arg) {
    return;
}
void func2() {
    X a;
    fun_x(a);
    X *pt = new X();
    delete pt;
    return;
}
int main() {
    func();
    cout << "func2: \n";
    func2();
    return 0;
}