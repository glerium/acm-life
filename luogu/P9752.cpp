#include <bits/stdc++.h>
using namespace std;
int n,a[10];
map<int,int> mp;
set<int> st;
int gt() {
    return a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
}
int add(int &x) {
    if(x<9) return ++x;
    return x=0;
}
int mns(int &x) {
    if(x>0) return --x;
    return x=9;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int i=1;i<=5;i++) cin>>a[i];
        st.insert(gt());
        for(int i=1;i<=5;i++) {
            for(int j=1;j<=9;j++) {
                for(int k=1;k<=j;k++) {
                    add(a[i]);
                }
                // cout<<":"<<gt()<<endl;
                mp[gt()]++;
                for(int k=1;k<=j;k++) {
                    mns(a[i]);
                }
            }
        }
        for(int i=1;i<=4;i++) {
            for(int j=1;j<=9;j++) {
                for(int k=1;k<=j;k++) {
                    add(a[i]);
                    add(a[i+1]);
                }
                mp[gt()]++;
                for(int k=1;k<=j;k++) {
                    mns(a[i]);
                    mns(a[i+1]);
                }
            }
        }
    }
    int ans=0;
    for(auto i:mp) {
        // cout<<i.first<<' '<<i.second<<endl;
        if(i.second==n&&!st.count(i.first)) ans++;
    }
    cout<<ans<<endl;
}