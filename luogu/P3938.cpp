#include <bits/stdc++.h>
using namespace std;
int m;
long long fib[100];
long long make(long long x) {
    for(int i=70;i>=0;i--) {
        if(fib[i]<x) return x-fib[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>m;
    fib[1]=fib[2]=1;
    for(int i=3;i<=70;i++) fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=m;i++) {
        long long x,y;
        cin>>x>>y;
        while(x!=y) {
            if(x>y) x=make(x);
            else y=make(y);
        }
        cout<<x<<endl;
    }
    return 0;
}