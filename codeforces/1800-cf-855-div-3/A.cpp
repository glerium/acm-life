#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n;
char s[100];
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        bool yes=true;
        for(int i=0;i<n;i++) s[i]=tolower(s[i]);
        int m=0;
        for(int i=0;i<n;i++) {
            while(s[i]==s[i+1]&&i+1<n) i++;
            s[m++]=s[i];
        }
        s[m]=0;
        // cout<<s<<endl;
        cout<<(strcmp(s,"meow")==0?"Yes":"No")<<endl;
    }
    return 0;
}