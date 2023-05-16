#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,k,head[maxn],idx;
struct Edge{
    int to;
    int nxt;
}g[maxn<<1];
void add(int x,int y){
    g[++idx]=(Edge){y,head[x]};
    head[x]=idx;
}
int main(){
    cin>>n>>k;
    {
        int x,y;
        while(k--) {
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }
        
    }
    return 0;
}