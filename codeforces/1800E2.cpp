#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,k,ct[30],ct2[30];
char s[maxn],r[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%s%s",&n,&k,s+1,r+1);
        for(int i=0;i<26;i++) ct[i]=ct2[i]=0;
        for(int i=1;i<=n;i++) {
            ct[s[i]-'a']++;
            ct2[r[i]-'a']++;
        }
        for(int i=0;i<26;i++) if(ct[i]!=ct2[i]) {
            puts("No");
            goto here;
        }
        for(int i=n-k+1;i<=min(k,n);i++) {
            if(s[i]!=r[i]) {
                puts("No");
                goto here;
            }
        }
        puts("Yes");
here:   ;
    }
    return 0;
}