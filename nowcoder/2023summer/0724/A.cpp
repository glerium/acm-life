#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll read() {
    ll ret=0; char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch<='9'&&ch>='0') {
        ret=ret*2+ch-'0';
        ch=getchar();
    }
    return ret;
}
int main() {
    x=read();
    y=read();
    ll ans=abs(x-y);
    if(x!=0) cout<<ans;
    else if(x==y) cout<<0;
    else cout<<-1;
    return 0;
}