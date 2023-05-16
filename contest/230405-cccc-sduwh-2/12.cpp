#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n, fa[maxn];
set<int> st;
int fnd(int x) {
    if(x==fa[x]) return x;
    else return fa[x]=fnd(fa[x]);
}
void merg(int x,int y) {
    fa[fnd(x)]=fnd(y);
}
bool same(int x, int y){
    return fnd(x)==fnd(y);
}
int pcnt=10;
void deb() {
    return;
    for(int i=1;i<=pcnt;i++) fnd(i), printf("(%d) ",fa[i]);
    cout<<endl;
}
int main() {
    cin>>n;
    for(int i=1;i<=1e4+1;i++) fa[i]=i;
    {
        set<int> person;
        for(int i=1;i<=n;i++){
            int k; cin>>k;
            int first; cin>>first;
            person.insert(first);
            for(int j=2;j<=k;j++) {
                int tmp; cin>>tmp;
                person.insert(tmp);
                merg(first,tmp);
            }
            deb();
        }
        pcnt=person.size();
    }
    for(int i=1;i<=pcnt;i++){
        fnd(i);
        st.insert(fa[i]);
    }
    printf("%d %d\n",pcnt,st.size());
    int t; cin>>t;
    while(t--) {
        int x,y; cin>>x>>y;
        cout<<(same(x,y)?'Y':'N')<<endl;
    }
    return 0;
}
