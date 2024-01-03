#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e5+10;
int t,n;
bitset<maxn> v;
char s[maxn];
bool isc(char ch){
    if(ch=='b'||ch=='c'||ch=='d') return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>(s+1);
        v.reset();
        int i=n;
        while(i>=1) {
            if(isc(s[i])) v[i-=3]=true;
            else v[i-=2]=true;
        }
        for(int i=1;i<=n;i++) {
            putchar(s[i]);
            if(i!=1&&v[i]) putchar('.');
        }
        putchar('\n');
    }
    return 0;
}