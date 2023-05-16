#include <iostream>
#include <string>
using std::cout, std::endl, std::string;
class Account {
public:
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
private:
    static double interestRate;
    static double initRate() { return 0.5; }
};
double Account::interestRate = initRate();
int main(){
    cout << Account::rate() << endl;
    Account a, b;
    a.rate(0.1);
    cout << b.rate();
}