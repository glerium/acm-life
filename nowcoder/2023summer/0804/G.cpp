#include <bits/stdc++.h>
#define yes puts("YES")
#define no puts("NO")
using namespace std;
long long gcd(long long x,long long y) {
    return !y?x:gcd(y,x%y);
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        long long x,y,z;
        cin>>x>>y>>z;
        if(z==0&&(x&&y)) no;
        else if(!x) {
            if(z%y==0) yes;
            else no;
        }else if(!y) {
            if(z%x==0) yes;
            else no;
        }else {
            long long g = gcd(x,y);
            if(z%g==0) yes;
            else no;
        }
    }
    return 0;
}