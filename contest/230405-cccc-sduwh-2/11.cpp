#include <bits/stdc++.h>
using namespace std;
const int maxn=507, maxm=507*508/2;
int v,e,k,n,clr[maxn];
struct Edge{
    int x,y;
}a[maxm];
set<int> st;
int main() {
    cin>>v>>e>>k;
    for(int i=1;i<=e;i++) {
        int x,y; cin>>x>>y;
        a[i].x=x, a[i].y=y;
    }
    cin>>n;
    for(int i=1;i<=n;i++) {
        st.clear();
        for(int j=1;j<=v;j++) cin>>clr[j], st.insert(clr[j]);
        bool good=true;
        if(st.size()>k) good=false;
        else {
            for(int j=1;j<=e;j++){
                if(clr[a[j].x] == clr[a[j].y]) {
                    good=false;
                    break;
                }
            }
        }
        cout << (good?"Yes":"No")<<endl;
    }
}
