#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n; cin>>t;
    while(t--) {
        cin>>n;
        puts(n%3?"First":"Second");
    }
    return 0;
}