#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    cin>>n>>m;
    if(m==0) cout<<1<<endl;
    else if(n==m) printf("%.8lf\n",1.0/n);
    else printf("%.8lf\n",1.0/(m+1));
    return 0;
}