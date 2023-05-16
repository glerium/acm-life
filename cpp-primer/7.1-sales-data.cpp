#include <iostream>
#include <string>
using std::cin, std::cout, std::cerr, std::endl;
using std::string;
class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}
    Sales_data(std::istream &is) : Sales_data("") { read(is, *this); }
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double avg_price() const;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price() const {
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main(){
    Sales_data total;
    total = static_cast<Sales_data>(string("a"));
    goto end;
    if(read(cin, total)) {
        Sales_data trans;
        while(read(cin, trans)) {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data" << endl;
    }
end:
    std::clog << "Done" << endl;
    return 0;
}