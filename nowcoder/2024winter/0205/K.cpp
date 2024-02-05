#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=5e3+10;
constexpr int mod=1e9+7;
int t,n;
string s,y;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>s>>y;
        if(n==1) {
            if(isdigit(s[0])) {
                if(s[0]=='8') {
                    if(y<"8") cout<<0<<endl;
                    else cout<<1<<endl;
                }else if(s[0]=='0') cout<<1<<endl;
                else cout<<0<<endl;
            }else{
                if(y<"8") cout<<1<<endl;
                else cout<<2<<endl;
            }
            continue;
        }
        set<string> st;
        rep(a,0,9) {
            rep(b,0,9) {
                if(a==b) continue;
                rep(c,0,9) {
                    if(c==a||c==b) continue;
                    rep(d,0,9) {
                        if(d==a||d==b||d==c) continue;
                        rep(p,0,9) {
                            string pw;
                            rep(i,0,n-1) {
                                if(isdigit(s[i])) pw+=s[i];
                                else if(s[i]=='a') pw+='0'+a;
                                else if(s[i]=='b') pw+='0'+b;
                                else if(s[i]=='c') pw+='0'+c;
                                else if(s[i]=='d') pw+='0'+d;
                                else pw+='0'+p;
                            }
                            if(pw[0]=='0') continue;
                            if(pw>y) continue;
                            int tt=0;
                            if(pw.size()>=1) tt+=pw[n-1]-'0';
                            if(pw.size()>=2) tt+=10*(pw[n-2]-'0');
                            if(pw.size()>=3) tt+=100*(pw[n-3]-'0');
//                             cout<<pw<<' '<<tt<<endl;
                            if(tt%8!=0) continue;
//                             cout<<":"<<pw<<endl;
                            st.insert(pw);
                        }
                    }
                }
            }
        }
        cout<<st.size()%mod<<endl;
    }
    return 0;

}