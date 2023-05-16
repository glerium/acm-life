#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m,k;
char x[1000];
int main(){
    cin>>n>>x>>m>>k;
    if(k==n) printf("mei you mai %s de",x);
    else if(k==m) printf("kan dao le mai %s de",x);
    else printf("wang le zhao mai %s de",x);
    return 0;
}
