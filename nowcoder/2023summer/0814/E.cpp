#include <bits/stdc++.h>
using namespace std;
int t,n,m,c,w,x,y,dx,dy,l;
vector<vector<int>> ans;
void calc(){
    cout<<c<<' '<<w<<endl;
    l = min(c,w);
    if(c>=w) dx=w,dy=0,c-=w;
    else dy=c,dx=0,w-=c;
}
int main() {
    cin>>t;
    while(t--){
        ans.clear();
        cin>>n>>m;
        x=1,y=1;
        c=n;
        w=m;
        while(c&&w) {
            calc();
            vector<int> cur;
            cur.push_back(x-1);
            cur.push_back(y-1);
            cur.push_back(l);
            ans.push_back(cur);
            x+=dx;
            y+=dy;
        }
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(auto i : ans){
            for(auto j:i) cout<<j<<' ';
            cout<<endl;
        }
    }
}