#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s;
bool is_prime(ll x) {
    if(x<=1) return false;
    if(x==2) return true;
    ll mx=sqrt(x);
    if(x%2==0) return false;
    for(int i=3;i<=mx;i+=2) if(x%i==0&&x!=i) return false;
    return true;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        ll t; cin>>t;
        s+=t;
    }
    if(n==1) {
        if(is_prime(s)) cout<<"Yes";
        else cout<<"No";
    }else if(n==2) {
        if(s%2==0&&s>=2*n) cout<<"Yes";
        else if(s%2==1) {
            if(is_prime(s-2)) cout<<"Yes";
            else cout<<"No";
        }
    }else{
        if(s>=2*n) cout<<"Yes";
        else cout<<"No";
    }
}