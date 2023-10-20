#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e6+10;
int t,n,step[maxn];
bool v[maxn];
struct State{
    int x;
    int step;
    bool operator<(const State& rhs)const{
        return step>rhs.step;
    }
};
priority_queue<State> q;
int main() {
    memset(step,0x3f,sizeof(step));
    step[1048576]=step[0]=0;
    v[1048576]=true;
    q.push({1048576,0});
    while(!q.empty()) {
        auto cur = q.top();
        q.pop();
        // cout<<cur.x<<endl;
        if(cur.step != step[cur.x]) continue;
        if(cur.x%2==0) {
            int nw=(cur.x+1048576)/2;
            if(!v[nw]&&cur.step+1<step[nw]) {
                q.push({nw,cur.step+1});
                step[nw]=cur.step+1;
                v[nw]=true;
            }
            nw=cur.x/2;
            if(!v[nw]&&cur.step+1<step[nw]) {
                q.push({nw,cur.step+1});
                step[nw]=cur.step+1;
                v[nw]=true;
            }
        }
        if(cur.x-1>=1) {
            int nw=cur.x-1;
            if(!v[nw]&&cur.step+1<step[nw]) {
                q.push({nw,cur.step+1});
                step[nw]=cur.step+1;
                v[nw]=true;
            }
        }
    }
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<step[n%1048576]<<endl;
    }
    return 0;
}