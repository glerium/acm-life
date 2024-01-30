#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn=3e5+10;
int t,n;
vector<int> ans;
int mylog2(unsigned long long x) {
    for(int i=0;;i++) {
        if((1ull<<(i+1))>x) return i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>t;
    while(t--) {
        ans.clear();
        unsigned long long x; cin>>x;
        if(x==2) cout<<"1\n1"<<endl;
        else {
            int ctinc=mylog2(x);
            for(int i=1;i<=ctinc;i++) ans.push_back(i*10);
            x-=1ull<<ctinc;
            while(x) {
                // if(x==1) {
                //     ans.push_back(0);
                //     break;
                // }
                int ctima=mylog2(x);
                ans.push_back(ctima*10+5);
                x-=1ull<<ctima;
            }
            cout<<ans.size()<<endl;
            for(auto i:ans) cout<<i<<' ';
            cout<<endl;
        }
    }
    return 0;
}