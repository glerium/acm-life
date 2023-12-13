#include <bits/stdc++.h>
using namespace std;
int t,a,b,ct;
int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b;
        ct=0;
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        set<pair<int,int>> st;
        if(a==b) {
            int x[4][2]={{a,a},{a,-a},{-a,a},{-a,-a}};
            for(int i=0;i<4;i++) {
                st.insert({x1+x[i][0], y1+x[i][1]});
                st.insert({x2+x[i][0], y2+x[i][1]});
            }
            cout<<8-st.size()<<endl;
        }else{
            int x[8][2]={{a,b},{a,-b},{-a,b},{-a,-b},{b,a},{b,-a},{-b,a},{-b,-a}};
            for(int i=0;i<8;i++) {
                st.insert({x1+x[i][0], y1+x[i][1]});
                st.insert({x2+x[i][0], y2+x[i][1]});
            }
            cout<<16-st.size()<<endl;
        }
    }
    return 0;
}