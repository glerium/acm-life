#include <bits/stdc++.h>
using namespace std;
int n,x;
int dsum(int x){
    int s=0;
    while(x) s+=x%10, x/=10;
    return s;
}
int main() {
    cin>>n;
    while(n--){
        cin>>x;
        bool have=true;
        int ss=dsum(x);
        for(int i=2;i<=9;i++){
            if(dsum(x)!=dsum(x*i)){
                have=false;
                break;
            }
        }
        if(have) printf("%d\n",ss);
        else printf("NO\n");
    }
    return 0;
}
