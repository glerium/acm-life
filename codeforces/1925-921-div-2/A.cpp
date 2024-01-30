#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<m;j++)
                putchar('a'+j);
        }
        putchar('\n');
    }
    return 0;
}