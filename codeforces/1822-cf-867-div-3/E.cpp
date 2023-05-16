#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        if(n%2==1) {
            cout<<-1<<endl;
            continue;
        }
        vector<int> ct(30);
        for(auto i : s) ct[i-'a']++;
        {
            int mxcnt=0;
            for(int i=0;i<26;i++) mxcnt=max(mxcnt,ct[i]);
            if(mxcnt>n/2) {
                cout<<-1<<endl;
                continue;
            }
        }
        vector<map<char,int>> a(n/2+7);
        for(int i=0;i<n;i++) {
            if(i<n/2) a[i][s[i]]++;
            else a[n-1-i][s[i]]++;
        }
        vector<int> ctrow(26);
        for(auto i : a) {
            for (auto j : i)
                if(j.second == 2) ctrow[j.first-'a']++;
        }
        int mxctrow=-1, sumctrow=0;
        for(auto i:ctrow) mxctrow=max(mxctrow,i), sumctrow+=i;
        int ans=0;
        if(mxctrow <= sumctrow-mxctrow) {
            ans = sumctrow/2 + sumctrow%2;
        }else{
            ans = sumctrow;
        }
        cout<<ans<<endl;
    }
    return 0;
}