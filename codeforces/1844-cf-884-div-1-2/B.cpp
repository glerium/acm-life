#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn],pri[maxn],ct,ctpri[maxn];
bool notp[maxn];
void init(int n) {
    notp[1]=true;
    int mx = sqrt(n);
    for(int i=2;i<=n;i++) {
        if(!notp[i]) {
            for(int j=i+i;j<=n;j+=i) {
                notp[j]=true;
            }
            pri[++ct]=i;
        }
    }
    for(int i=1;i<=n;i++) {
        ctpri[i]=ctpri[i-1]+(!notp[i]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    init(200003);
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> left, right, midl, midr;
        for(int i=1;pri[i]<=n;i++) {
            left.push_back(pri[i]);
            i++;
            if(pri[i]<=n) right.push_back(pri[i]);
        }
        int ctt = n-ctpri[n];
        bool lef=true;
        for(int i=1;i<=n;i++) {
            if(!notp[i]) continue;
            if(lef) midl.push_back(i);
            else midr.push_back(i);
            lef = !lef;
        }
        for(int i=left.size()-1;i>=0;i--) cout<<left[i]<<' ';
        for(int i=midl.size()-1;i>=0;i--) cout<<midl[i]<<' ';
        for(int i=0;i<midr.size();i++) cout<<midr[i]<<' ';
        for(int i=0;i<right.size();i++) cout<<right[i]<<' ';
        cout<<endl;
    }
    return 0;
}