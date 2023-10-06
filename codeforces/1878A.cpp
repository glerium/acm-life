#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n,k; cin>>n>>k;
        bool ans=false;
        int a;
        while(n--) {
            cin>>a;
            if(a==k) ans=true;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}