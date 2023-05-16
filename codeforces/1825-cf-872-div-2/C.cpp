#include <bits/stdc++.h>
using namespace std;
int t,n,m,ctl,ctr;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        int mlef=0,mrig=10000000;
        ctl=ctr=0;
        vector<bool> occ(m+3);
        vector<int> ctocc(m+3);
        {
            int tmp;
            for(int i=1;i<=n;i++) {
                cin>>tmp;
                if(tmp==-1) ctl++;
                else if(tmp==-2) ctr++;
                else {
                    if(occ[tmp]) continue;
                    else {
                        occ[tmp]=true;
                        mlef=min(mlef,tmp);
                        mrig=max(mrig,tmp);
                    }
                }
            }
            for(int i=1;i<=m;i++) ctocc[i]=ctocc[i-1]+occ[i];
            // cout<<endl;
        }
        // 从左侧开始
        int ans=0;
        int cur=0;
        cur=min(m,ctocc[m]+ctr);
        // cout<<":"<<cur<<endl;
        ans=max(ans,cur);
        // from right
        cur=min(m,ctocc[m]+ctl);
        ans=max(ans,cur);
        // cout<<":"<<cur<<endl;
        // from middle
        for(int i=1;i<=m;i++) {
            cur=0;
            if(!occ[i]) continue;
            cur+=ctocc[m];
            cur+=min(ctl,(i-1)-ctocc[i-1]);
            cur+=min(ctr,(m-i)-(ctocc[m]-ctocc[i]));
            // cout<<":"<<i<<' '<<cur<<endl;
            ans=max(ans,cur);
        }
        cout<<ans<<endl;
    }
    return 0;
}