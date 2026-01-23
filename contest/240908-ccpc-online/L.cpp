#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m; cin >> n >> m;
    char s[n+2][m+2];
    for(int i=1;i<=n;i++)
        scanf("%s", s[i]+1);
    int ct = 0;
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(s[i][j] == 'c' && s[i][j+1] == 'c' && s[i+1][j] == 'p' && s[i+1][j+1] == 'c')
                ct++;
        }
    }
    cout << ct << endl;
    return 0;
}
