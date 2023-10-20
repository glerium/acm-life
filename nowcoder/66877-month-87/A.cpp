#include <bits/stdc++.h>
using namespace std;
char s[100];
int main() {
    cin>>(s+1);
    int ans=strlen(s+1);
    int n=ans;
    for(int i=n;i>=1;i--) {
        if((s[i]-'0')%2==0) 
            ans = min(ans,n-i);
    }
    cout<<ans<<endl;
    return 0;
}