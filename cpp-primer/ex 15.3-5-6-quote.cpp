// ex 15.3, 15.5, 15.6
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
    virtual void debug(ostream&) const;
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price;
};
void print_total(ostream& os, Quote &obj, int n) {
    os << "ISBN: " << obj.isbn() << endl
       << "Price: " << obj.net_price(n) << endl;
}
void Quote::debug(ostream& os) const {
    os << "bookNo, price" << endl;
}
class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {};
    virtual double net_price(size_t cnt) const override;
    virtual Bulk_quote* get_this() override {return this;}
    virtual void debug(ostream&) const override;
    double net_price_limited(size_t cnt) const;
private:
    size_t min_qty = 0;
    double discount = 0;
};
double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty) 
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
double Bulk_quote::net_price_limited(size_t cnt) const {
    if(cnt >= min_qty)
        return min_qty * price + (cnt - min_qty) * (1 - discount) * price;
    else
        return cnt * price;
}
void Bulk_quote::debug(ostream& os) const {
    os << "bookNo, price, min_qty, discount" << endl;
}

int main() {
    Quote obj1("Book A", 10.0);
    Bulk_quote obj2("Book B", 20.0, 8, 0.2);
    obj1.debug(cout);
    obj2.debug(cout);
    return 0;
}