#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=6;i++) {
        for(int j=1;j<=6;j++) {
            for(int k=1;k<=6;k++) {
                int x=0,y=0;
                if(i==1||i==4) x+=i;
                else y+=i;
                if(j==1||j==4) x+=j;
                else y+=j;
                if(k==1||k==4) x+=k;
                else y+=k;
                if(x==a&&y==b) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
}