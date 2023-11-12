#include <bits/stdc++.h>
using namespace std;
char s[200005];
int st[200005],top;
int main() {
    cin>>(s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) {
        st[++top]=s[i];
        if(top>=3&&st[top-2]=='A'&&st[top-1]=='B'&&st[top]=='C') {
            top-=3;
        }
    }
    for(int i=1;i<=top;i++) putchar(st[i]);
    return 0;
}