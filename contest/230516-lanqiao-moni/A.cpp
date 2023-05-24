#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int main() {
    cin>>n;
    while(n--) {
        string s;
        getline(cin,s);
        if(s.empty()) {
            n++;
            continue;
        }
        int type;   //4: int, 8: long, -1: String
        bool array;
        int cnt=1;
        int l=s.size();

        if(s[0]=='i') type=4;
        else if(s[0]=='l') type=8;
        else type=-1;

        if(type!=-1) {
            for(int i=1;i<l;i++) if(s[i-1]=='['&&s[i]==']') array=true;
            for(int i=0;i<l;i++) if(s[i]==',') cnt++;
            int ima=0;
            bool in=false;
            if(array) {
                for(int i=0;i<l;i++) {
                    if(s[i]=='['&&s[i+1]!=']'&&i!=l-1) {
                        in=true;
                        ima=0;
                    }else if(isdigit(s[i])&&in) ima = ima*10 + s[i]-'0';
                    else if(s[i]==']'&&in) {
                        in=false;
                        ans += ima*type;
                        cnt--;
                    }
                }
            }
            ans += cnt*type;
        }else{
            int cnt=0;
            bool in=false;
            for(int i=0;i<l;i++) {
                if(s[i]=='\"'&&!in) in = true;
                else if(in) {
                    if(s[i]!='\"') cnt++;
                    else in=false;
                }
            }
            ans+=cnt;
        }
        // cout<<ans<<endl;
    }
    long long gb = ans / (1024ll*1024*1024);
    ans %= (1024ll*1024*1024);
    long long mb = ans / (1024ll*1024);
    ans %= (1024ll*1024);
    long long kb = ans / (1024ll);
    ans %= (1024ll);
    long long b = ans;

    if(gb) cout<<gb<<"GB";
    if(mb) cout<<mb<<"MB";
    if(kb) cout<<kb<<"KB";
    if(b)  cout<<b<<'B';
    return 0;
}