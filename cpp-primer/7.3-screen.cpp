#include <iostream>
#include <string>
#include <vector>
using std::cin, std::cout, std::endl;

class Screen;
class Window_mgr;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {};
    inline char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen &set(char ch);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    pos size() const;
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable int mutable_int = 0;
    void do_display(std::ostream &os) const { os << contents; }
};


void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.width * s.height, ' ');
}

inline Screen &Screen::move(pos r, pos c) {
    pos position = r * width + c;
    cursor = position;
    return *this;
}
inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch) {
    pos position = r * width + c;
    contents[position] = ch;
    return *this;
}
inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}
inline Screen::pos Screen::size() const {
    return height * width;
}

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.display(cout);
    cout << endl;
    myScreen.move(4,0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
}