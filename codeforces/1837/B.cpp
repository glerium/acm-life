#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<n;) {
            if(s[i]=='<') {
                int ima=0;
                while(s[i]=='<') {
                    ima++;
                    i++;
                }
                ans=max(ans,ima);
            }else{
                int ima=0;
                while(s[i]=='>') {
                    ima++;
                    i++;
                }
                ans=max(ans,ima);
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}