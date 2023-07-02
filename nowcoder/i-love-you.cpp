#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int f[maxn][13];
int main() {
    cin>>(s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) {
        s[i]=tolower(s[i]);
        for(int j=1;j<=8;j++) f[i][j]=f[i-1][j];
        if(s[i]=='i') f[i][1]++;
        else if(s[i]=='l') f[i][2]+=f[i-1][1];
        else if(s[i]=='o') {
            f[i][3]+=f[i-1][2];
            f[i][7]+=f[i-1][6];
        }else if(s[i]=='v') f[i][4]+=f[i-1][3];
        else if(s[i]=='e') f[i][5]+=f[i-1][4];
        else if(s[i]=='y') f[i][6]+=f[i-1][5];
        else if(s[i]=='u') f[i][8]+=f[i-1][7];
        for(int j=1;j<=8;j++) f[i][j]%=20010905;
    }
    cout<<f[n][8]<<endl;
    return 0;
}