#include <iostream>
#include <string>
using std::cin, std::cout, std::endl;
struct Person {
    std::string name;
    std::string address;
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    Person() = default;
    Person(std::string name, std::string address) : name(name), address(address) {}
    Person(std::istream &is) {
        is >> name >> address;
    }
};
std::ostream &print(std::ostream &os, const Person &data) {
    os << "name: " << data.getName() << '\n'
       << "address: " << data.getAddress() << endl;
    return os;
}
std::istream &read(std::istream &is, Person &data) {
    is >> data.name >> data.address;
    return is;
}
int main() {
    const size_t MAXN = 2;
    for(int i = 0; i < MAXN; i++) {
        Person trans(cin);
        print(cout, trans);
    }
    return 0;
}