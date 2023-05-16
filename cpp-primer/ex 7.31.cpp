class X;
class Y;
class X {
    Y * data;
};
class Y {
    X data;
};
int main() {
    X data1;
    Y data2;
    return 0;
}