#include <iostream>
#include <string>
using namespace std;
class Book {
public:
    Book(string name = "") : name(name) {}
    Book(string name, string author, double price,
         int year): name(name), author(author), price(price), year(year) {}
private:
    string name;
    string author;
    double price;
    int year;
};