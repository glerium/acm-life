#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int _,n;
vector<string> ans;
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        if(n==1) cout<<1<<endl;
        else if(n==3) cout<<"169\n196\n961\n";
        else{
            ans.clear();
            ans.push_back("196");
            ans.push_back("169");
            ans.push_back("961");
            for(int i=5;i<=n;i+=2) {
                for(int j=0;j<ans.size();j++) ans[j]+="00";
                string s="1";
                for(int j=1;j<=(i-3)/2;j++) s+="0";
                s+="6";
                for(int j=1;j<=(i-3)/2;j++) s+="0";
                s+="9";
                ans.push_back(s);
                
                s="9";
                for(int j=1;j<=(i-3)/2;j++) s+="0";
                s+="6";
                for(int j=1;j<=(i-3)/2;j++) s+="0";
                s+="1";
                ans.push_back(s);
            }
            for(int i=0;i<n;i++) cout<<ans[i]<<endl;
        }
    }
    return 0;
}