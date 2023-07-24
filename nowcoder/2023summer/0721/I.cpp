#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        if(n%2==0&&n/2%2!=0&&m%2!=0) {
            for(int i=1;i<=n;i++) {
                bool ch = (i+1)/2%2;
                if(i==n) ch=!ch;
                for(int j=1;j<=m;j++) {
                    putchar((ch^(j%2))?'o':'x');
                }
                putchar('\n');
            }
        }else{
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    bool ch = (i+1)/2%2;
                    putchar((ch^(j%2))?'o':'x');
                }
                putchar('\n');
            }
        }
    }
}