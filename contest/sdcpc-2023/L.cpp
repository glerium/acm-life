#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,X1,Y1,X2,Y2;
struct Answer{
    int r,c,h,w;
}ve[100007];
int ct=0;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    int sz=n;
    X1=Y1=1,X2=Y2=n;
    puts("Yes");
    while(X1!=X2||Y1!=Y2) {
        if(X1!=a&&Y1!=b) {          // left up
            ve[++ct]=(Answer){X1,Y1,sz-1,sz-1};
            X1++; Y1++;
        }else if(X2!=a&&Y1!=b) {    // left down    
            ve[++ct]=(Answer){X2,Y1,1-sz,sz-1};
            X2--; Y1++;
        }else if(X1!=a&&Y2!=b) {    // right up
            ve[++ct]=(Answer){X1,Y2,sz-1,1-sz};
            X1++; Y2--;
        }else{
            ve[++ct]=(Answer){X2,Y2,1-sz,1-sz};
            X2--; Y2--;
        }
        sz--;
    }
    printf("%d\n",ct);
    for(int i=1;i<=ct;i++) printf("%d %d %d %d\n",ve[i].r,ve[i].c,ve[i].h,ve[i].w);
    return 0;
}