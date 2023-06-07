#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,k;
bool check() {  // check sum{1..2^(k-1)} < n
    ll s=0;
    for(int i=0;i<k;i++) {
        s+=(1<<i);
        if(s>n) return false;
    }
    return true;
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        if(check()) {
            cout<<(1ll<<k)<<endl;
        }else{
            cout<<n+1<<endl;
        }
    }
}