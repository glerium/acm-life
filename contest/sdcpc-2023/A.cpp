#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=107;
int t,n;
ll k;
struct Order {
    int x;
    ll y;
    bool operator<(const Order& rhs)const{
        return x<rhs.x;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
        sort(a+1,a+1+n);
        bool yes=true;
        ll ct=0;
        for(int i=1;i<=n;i++) {
            ct+=a[i].y;
            // cout<<":"<<a[i].x<<' '<<ct<<endl;
            if(a[i].x*k<ct) {
                yes=false;
                break;
            }
        }
        puts(yes?"Yes":"No");
    }
    return 0;
}