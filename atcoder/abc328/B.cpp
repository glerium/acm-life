#include <bits/stdc++.h>
using namespace std;
int n,d[105];
bool check(int x,int y) {
    if(x>=100||y>=100) return false;
    set<int> st;
    if(x<=9) st.insert(x);
    else st.insert(x/10),st.insert(x%10);
    if(y<=9) st.insert(y);
    else st.insert(y/10),st.insert(y%10);
    return st.size()==1;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=d[i];j++)  {
            ans+=check(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}