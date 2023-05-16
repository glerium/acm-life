#include <iostream>
#include <string>
using namespace std;
class Quote {
public:
    Quote() = default;
    Quote(const string& no, double price) : bookNo(no), price(price) {};
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n*price; }
    virtual Quote* get_this() {return this;}
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price;
};
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc) :
        Quote(book, price), qty(qty), discount(disc) {}
    virtual double net_price(size_t n) const = 0;
protected:
    size_t qty;
    double discount;
};
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) {}
    virtual double net_price(size_t) const override;
};
double Bulk_quote::net_price(size_t n) const {
    if(n >= qty)
        return n * price * (1 - discount);
    else
        return n * price;
}
class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double price, size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) {}
    virtual double net_price(size_t) const override;
};
double Limit_quote::net_price(size_t n) const {
    if(n >= qty)
        return (n - qty) * price * (1 - discount) + qty * price;
    else    
        return n * price;
}
int main() {
    
}