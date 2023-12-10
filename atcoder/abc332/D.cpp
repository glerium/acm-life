#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[10][10],b[10][10],r[10],c[10];
vector<int> rows[10], cols[10];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
    for(int i=1;i<=n;i++) {
        vector<int> t;
        for(int j=1;j<=m;j++) t.push_back(b[i][j]);
        sort(t.begin(), t.end());
        rows[i]=t;
    }
    for(int j=1;j<=m;j++) {
        vector<int> t;
        for(int i=1;i<=n;i++) t.push_back(b[i][j]);
        sort(t.begin(), t.end());
        cols[j]=t;
    }
    
    return 0;
}