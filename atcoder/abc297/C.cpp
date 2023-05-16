#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[107][107];
bool operate(char* s) {
    for(int i=1;i<m;i++) {
        if(s[i]=='T'&&s[i+1]=='T') {
            s[i]='P';
            s[i+1]='C';
            return true;
        }
    }
    return false;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i]+1;
    int ans=0;
    for(int i=1;i<=n;i++)
        while(operate(s[i]));
    for(int i=1;i<=n;i++) cout<<s[i]+1<<endl;
    return 0;
}