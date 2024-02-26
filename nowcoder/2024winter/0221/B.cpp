#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod=1e9+7;
string s;
ll ct[200005];
void init() {
    ct[0]=1;
    ct[1]=2;
    for(int i=2;i<=200000;i++) ct[i]=(ct[i-1]+ct[i-2])%mod;
}
int main() {
    init();
    cin>>s;
    int n = s.size();
    s = " " + s + "       ";
    vector<string> pat = {"mygo", "m ygo", "my go", "myg o", "m y go", "m yg o", "my g o", "m y g o"};
    ll ans=0;
    for(int i=1;i<=n;i++) {
        for(auto &j:pat) {
            auto x = s.substr(i, j.size());
            auto check = [&](string str, string pat) -> auto {
                for(int i=0; i<pat.size(); i++) {
                    if(pat[i]==' ') continue;
                    if(str[i]!=pat[i]) return false;
                }
                return true;
            };
            if(check(x,j)) {
                ans+=ct[i-1]*ct[n-(i+j.size()-1)];
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}