#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c; cin >> a >> b >> c;
    if(a >= 35 && (b == 1 && c >= 33)) {
        cout << "Bu Tie" << endl;
        cout << a << endl;
    }else{
        if(a >= 35 && b == 0 && c >= 33) {
            cout << "Shi Nei" << endl;
            cout << a << endl;
        }else if(b == 1 && (a < 35 || c < 33)) {
            cout << "Bu Re" << endl;
            cout << c << endl;
        } else{
            cout << "Shu Shi" << endl;
            cout << c << endl;
        }
    }
}