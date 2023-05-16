#include <bits/stdc++.h>
using namespace std;
int t,n;
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}
int a[10000];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=1000;i++) {
            if((i+n*(n+1)/2-1)%n==0){
                a[1]=i;
                break;
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}