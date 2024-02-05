#include <bits/stdc++.h>
using namespace std;
int t,n;
const char s1[]="dfs", s2[]="DFS";
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int i=0,c1=0,c2=0;
        while(i<n&&c1<3) {
            if(s[i]==s1[c1]) c1++;
            i++;
        }
        i=0;
        while(i<n&&c2<3) {
            if(s[i]==s2[c2]) c2++;
            i++;
        }
        printf("%d %d\n", c2==3, c1==3);
    }
}