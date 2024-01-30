#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
    cin>>n;
    n--;
    if(!n) cout<<0<<endl;
    string s;
    while(n) {
        s+=n%5*2+'0';
        n/=5;
    }
    cout<<string(s.rbegin(), s.rend())<<endl;
    return 0;
}