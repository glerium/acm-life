#include <iostream>
using std::cout, std::endl;
class Debug {
public:
    Debug() = default;
    constexpr Debug(bool val) : hw(val), io(val), other(val) {}
    constexpr Debug(bool hw, bool io, bool other) : hw(hw), io(io), other(other) {}
    constexpr bool if_any() { return io || hw || other; }
    void set_hw(bool val) { hw = val; }
    void set_io(bool val) { io = val; }
    void set_other(bool val) { other = val; }
private:
    bool hw, io, other;
};
int main() {
    constexpr Debug obj(true, false, false);
    return 0;
}