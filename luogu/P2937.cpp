#include <bits/stdc++.h>
using namespace std;
int w,h;
char mp[202][202];
bool v[202][202];
struct Point{
    int x,y;
    bool operator==(const Point& rhs)const{
        return x==rhs.x&&y==rhs.y;
    }
}st,ed;
struct Node {
    Point pos;
    int step;
    bool operator<(const Node& rhs)const {
        return step>rhs.step;
    }
};
priority_queue<Node> q;
int main() {
    ios::sync_with_stdio(false);
    cin>>w>>h;
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>mp[i][j];
    {
        vector<Point> v;
        for(int i=1;i<=h;i++) {
            for(int j=1;j<=w;j++) {
                if(mp[i][j]=='C') v.push_back({i,j});
            }
        }
        st=v[0];
        ed=v[1];
    }
    v[st.x][st.y]=true; //h*w
    q.push({st,0});
    while(!q.empty()) {
        auto ima=q.top();
        q.pop();
        // cout<<ima.pos.x<<' '<<ima.pos.y<<endl;
        if(ima.pos==ed) {
            cout<<ima.step-1<<endl;
            return 0;
        }
        int x=ima.pos.x,y=ima.pos.y;
        for(int i=x-1;i>=1&&mp[i][y]!='*';i--) {
            if(v[i][y]) continue;
            v[i][y]=1;
            q.push({i,y,ima.step+1});
        }
        for(int i=x+1;i<=h&&mp[i][y]!='*';i++) {
            if(v[i][y]) continue;
            v[i][y]=1;
            q.push({i,y,ima.step+1});
        }
        for(int i=y-1;i>=1&&mp[x][i]!='*';i--) {
            if(v[x][i]) continue;
            v[x][i]=1;
            q.push({x,i,ima.step+1});
        }
        for(int i=y+1;i<=w&&mp[x][i]!='*';i++) {
            if(v[x][i]) continue;
            v[x][i]=1;
            q.push({x,i,ima.step+1});
        }
    }
}