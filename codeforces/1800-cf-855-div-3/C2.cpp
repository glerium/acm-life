#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,s[maxn];
priority_queue<long long> q;
int main() {
    cin>>t;
    while(t--) {
        while(!q.empty()) q.pop();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        long long last=0,ans=0;
        for(int i=1;i<=n;i++) {
            if(s[i]) q.push(s[i]);
            else {
                if(!q.empty()) {
                    long long tt=q.top();
                    q.pop();
                    ans+=tt;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}