#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    bool z = true;
    for(int i=s.size()-1;i>=0;i--) {
        if(z && s[i] != 'Z') {
            z = false;
        }else if(!z && s[i] == 'Z') {
            cout << -1 << endl;
            return 0;
        }
    }
    string a, b;
    for(auto i : s) {
        if(i == 'X') {
            a += '2';
            b += '1';
        }else if(i == 'Y') {
            a += '1';
            b += '2';
        }else{
            a += '5';
            b += '5';
        }
    }
    cout << a << endl << b << endl;
}