#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
int ct,ctgold;
const int go[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>> a;
vector<vector<bool>> v;
int getnum(){
    char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    return ch-'0';
}
bool dfs(int x, int y) {
    //cout<<x <<' '<<y<<endl;
    v[x][y]=true;
    bool ret=a[x][y]!=1;
    for(int i=0;i<4;i++) {
        int tx=x+go[i][0],
            ty=y+go[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!v[tx][ty]) {
            if(a[tx][ty]) {
                ret|=dfs(tx,ty);
            }
        }
    }
    return ret;
}
int main(){
    cin>>n>>m;
    a.push_back(vector<int>());
    v.push_back(vector<bool>());
    for(int i=1;i<=n;i++) {
        vector<int> aaa;
        vector<bool> vvv;
        int tmp;
        aaa.push_back(0);
        vvv.push_back(0);
        for(int j=1;j<=m;j++){
            tmp=getnum();
            aaa.push_back(tmp);
            vvv.push_back(false);
        }
        a.push_back(aaa);
        v.push_back(vvv);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(!v[i][j]&&a[i][j]) {
                ctgold+=dfs(i,j);
                ct++;
            }
        }
    }
    cout<<ct<<' '<<ctgold<<endl;
    return 0;
}
