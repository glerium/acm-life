#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxm=1e6+10;
int n,a[maxn],step[maxn];
vector<vector<int>> ve(maxm);
map<int,int> mp;
struct Node{
    int x;
    int step;
    bool operator<(const Node& rhs)const{
        return step>rhs.step;
    }
};
priority_queue<Node> q;
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        ve[a[i]].push_back(i);
        mp[i]=ve[a[i]].size()-1;
    }
    memset(step,0x3f,sizeof(step));
    step[1]=0;
    q.push({1,0});
    while(!q.empty()) {
        auto now = q.top();
        q.pop();
        if(now.x==n) break;
        if(now.step!=step[now.x]) continue;
        // cout<<now.x<<' '<<now.step<<endl;
        if(now.x+1<=n&&step[now.x+1]>step[now.x]+1) {
            step[now.x+1]=step[now.x]+1;
            q.push({now.x+1, step[now.x+1]});
        }
        if(now.x-1>=1&&step[now.x-1]>step[now.x]+1) {
            step[now.x-1]=step[now.x]+1;
            q.push({now.x-1, step[now.x-1]});
        }
        if(ve[a[now.x]].size()>mp[now.x]+1) {
            int i=mp[now.x]+1;
            if(step[ve[a[now.x]][i]]<=step[now.x]+1) continue;
            step[ve[a[now.x]][i]]=step[now.x]+1;
            q.push({ve[a[now.x]][i],step[now.x]+1});
        }
    }
    cout<<step[n]<<endl;
    return 0;
}