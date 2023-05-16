#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,b[maxn],pre[maxn],suf[maxn];
int mx=0,mx1=0,mx2=0;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar();}
	x=v*w; return;
}
int main(){
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],b[i]+i);
        suf[n+1]=INT_MIN;
        for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],b[i]-i);
        int ans=0;
        for(int i=2;i<n;i++) ans=max(ans,b[i]+pre[i-1]+suf[i+1]);
        printf("%d\n",ans);
    }
    return 0;
}