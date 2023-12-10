#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,g,m,a,b;
void tt() {
    if(a==g) a=0;
    else if(b==0) b=m;
    else {
        int mx=min(b,g-a);
        b-=mx, a+=mx;
    }
}
int main() {
    cin>>k>>g>>m;
    while(k--) tt();
    cout<<a<<' '<<b<<endl;
    return 0;
}