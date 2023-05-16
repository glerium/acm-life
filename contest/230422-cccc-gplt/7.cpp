#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int x,y,n;
int main(){
    cin>>x>>y>>n;
    int ans=1e9, wuhu, qifei;
    for(int i=1;i<=x;i++) {     // girls per room
        if(x%i!=0) continue;
        if(n-x/i<=0) continue;
        if(y%(n-x/i)!=0) continue;
        if(i==1||y/(n-x/i)==1) continue;
        if(abs(i-(y/(n-x/i)))<ans) {
            ans=abs(i-(y/(n-x/i)));
            wuhu=x/i;
            qifei=n-x/i;
        }
    }
    if(ans!=1e9) printf("%d %d\n",wuhu,qifei);
    else printf("No Solution\n");
    return 0;
}
