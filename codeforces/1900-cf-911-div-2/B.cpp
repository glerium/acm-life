#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=107;
int t,a,b,c;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        cout<<(b%2==c%2)<<' '<<(a%2==c%2)<<' '<<(a%2==b%2)<<endl;
    }
    return 0;
}