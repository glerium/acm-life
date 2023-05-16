#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,c;
string s[5007];
int ct[5007], tch[5007], ans[5007];
int room[100007], ctr;
bool check() {
    for(int i=1;i<=n;i++) {
        if(ct[i]) return false;
    }
    return true;
}
int findmax(){
    int mx=0;
    for(int i=1;i<=n;i++) {
        if(ct[i]>mx) mx=i;
    }
    return mx;
}
int findroom(int x) {
    for(int i=1;i<=ctr;i++) {
        if(room[i]>=x) return i;
    }
    return -1;
}
int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>s[i]>>ct[i];
    while(!check()) {
        int mx=findmax();
        if(ct[mx]>=c) ct[mx]-=c, ans[mx]++, ctr++;
        else {
            int ima = findroom(ct[mx]);
            if(ima!=-1) {
                room[ima]-=ct[mx];
                ct[mx]=0;
                ans[mx]++;
            }else{
                room[++ctr] = c-ct[mx];
                ct[mx]=0;
                ans[mx]++;
            }
        }
    }
    for(int i=1;i<=n;i++) {cout<<s[i]<<' '<<ans[i]<<endl;}
    cout<<ctr;
    return 0;
}
