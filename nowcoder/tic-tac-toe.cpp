#include <bits/stdc++.h>
using namespace std;
int t;
char a[5][5];
bool check(char c) {
    for(int i=1;i<=3;i++) if(a[i][1]==c&&a[i][2]==c&&a[i][3]==c) return true;
    for(int i=1;i<=3;i++) if(a[1][i]==c&&a[2][i]==c&&a[3][i]==c) return true;
    if(a[1][1]==c&&a[2][2]==c&&a[3][3]==c) return true;
    if(a[1][3]==c&&a[2][2]==c&&a[3][1]==c) return true;
    return false;
}
int main() {
    cin>>t;
    while(t--) {
        for(int i=1;i<=3;i++) cin>>(a[i]+1);
        bool ya=check('A'),
             yb=check('B');
        if(ya&&yb) puts("invalid");
        else if(!ya&&!yb) puts("draw");
        else if(ya) puts("Yes");
        else puts("No");
    }
    return 0;
}