#include <bits/stdc++.h>
using namespace std;
int n,fl[1003],fo[1003];
char s[1003];
int main() {
    cin>>n>>(s+1);
    for(int i=1;i<=n;i++) {
        fl[i]=fl[i-1]+(s[i]=='L');
        fo[i]=fo[i-1]+(s[i]=='O');
    }
    for(int i=1;i<n;i++) {
        if(fl[i]!=fl[n]-fl[i]&&fo[i]!=fo[n]-fo[i]) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}