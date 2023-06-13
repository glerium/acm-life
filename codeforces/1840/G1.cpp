#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    int x;
    scanf("%d",&x);
    mp.insert({x,0});
    int cur=0;
    for(int i=1;i<=1000;i++) {
        printf("+ 1\n");
        fflush(stdout);
        cur++;
        scanf("%d",&x);
        if(mp.count(x)) {
            printf("! %d\n",cur-mp[x]);
            fflush(stdout);
            return 0; 
        }
        mp.insert({x,cur});
    }
    for(int i=1;i<=1000;i++) {
        printf("+ 1000\n");
        fflush(stdout);
        cur+=1000;
        scanf("%d",&x);
        if(mp.count(x)) {
            printf("! %d\n",cur-mp[x]);
            fflush(stdout);
            return 0;
        }
        mp.insert({x,cur});
    }
    return 0;
}