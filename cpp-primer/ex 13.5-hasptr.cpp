#include <string>
using std::string;
class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(HasPtr &obj) : ps(obj.ps), i(obj.i) {}
    HasPtr& operator=(const HasPtr& rhs) {
        ps = rhs.ps;
        i = rhs.i;
        return *this;
    }
    ~HasPtr() {}
private:
    string *ps;
    int i;
};
int main(){
    return 0;
}