#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define yes puts("YES")
#define no puts("NO")
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int _;
bool v[maxn];
ll a[maxn],n;
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        rep(i,1,n) v[i]=false;
        rep(i,1,n-1) cin>>a[i];
        if(a[n-1]!=n*(n+1)/2&&a[n-1]!=n*(n-1)/2) {
            no;
            continue;
        }
        rep(i,1,n) if(a[i]-a[i-1]<maxn) v[a[i]-a[i-1]]=true;
        int ct=0;
        rep(i,1,n) {
            if(!v[i]){
                ct++;
            }
        }
        // cout<<"CT="<<ct<<' '<<v[n]<<' '<<(a[n-1]==n*(n-1)/2)<<endl;
        if(ct==2&&a[n-1]==n*(n+1)/2||ct==1) yes;
        else no;
    }
    return 0;
}