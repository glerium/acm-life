#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn],st[maxn][20];
template<typename T> void read(T& x){
    x=0; char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch<='9'&&ch>='0') {x=x*10+ch-'0'; ch=getchar();}
}
template<typename T> void write(T x) {
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main() {
    read(n), read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    int r=ceil(log2(n));
    for(int i=1;i<=r;i++) {
        for(int j=1;j+(1<<i)-1<=n;j++) {
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1;i<=m;i++) {
        int x,y; read(x), read(y);
        int r=log2(y-x+1);
        // cout<<y-(1<<r)+1<<endl;
        write(max(st[x][r],st[y-(1<<r)+1][r]));
        putchar('\n');
    }
    return 0;
}