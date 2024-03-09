#include <bits/stdc++.h>
using namespace std;
constexpr size_t maxn=1e5+10;
int n, k;
bitset<maxn> ok;
int main() {
    cin>>n>>k;
    int ct = 0;
    ok[0] = true;
    for(int i=1;i<=k;i++) {
        int x,y; cin>>x>>y;
        if(!ok[y]) ct++;
        ok[x] = true;
    }
    cout<<ct<<endl;
}