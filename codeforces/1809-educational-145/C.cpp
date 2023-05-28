#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        int r=1,rem=0;
        for(int i=1;i<=30;i++) {
            if(i*(i+1)/2==k) {
                for(int j=1;j<=i;j++) printf("1 ");
                for(int j=i+1;j<=n;j++) printf("-1000 ");
                puts("");
                goto end;
            }
        }
        while(r*(r+1)/2<k) r++;
        for(int i=1;i<r;i++) printf("30 ");
        rem=k-r*(r-1)/2;
        printf("%d ",-(30*(r-1-rem)+10));
        for(int i=r+1;i<=n;i++) printf("-1000 ");
        puts("");
end:    ;
    }
    return 0;
}