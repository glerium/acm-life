#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main() {
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++) {
        int l,r; char c1,c2;
        cin>>l>>r>>c1>>c2;
        l--,r--;
        for(int j=l;j<=r;j++) if(s[j]==c1) s[j]=c2;
    }
    cout<<s<<endl;
}