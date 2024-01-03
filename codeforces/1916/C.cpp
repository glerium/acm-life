#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int _,n;
ll a[maxn],s;
struct State{
    int o,e;
    bool f;
    bool operator<(const State& rhs)const{
        if(o!=rhs.o) return o<rhs.o;
        if(e!=rhs.e) return e<rhs.e;
        if(f!=rhs.f) return f<rhs.f;
        return false;
    }
};
map<State,int> mp;
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int dfs(int o,int e,bool f) {
    if(o+e==0) return 0;
    if(o+e==1) return 0;
    if(o==0) return 0;
    if(o==1) return 1;
    const State stt = {o,e,f};
    if(mp.count(stt)) return mp[stt];
    int ans;
    if(f) {
        if(o>=2) ans=dfs(o-2,e+1,!f);
        else if(e>=2) ans=dfs(o,e-1,!f);
        else ans=dfs(o-1,e,!f)+1;
    }else{
        if(o&&e) ans=dfs(o-1,e,!f)+1;
        else if(e>=2) ans=dfs(o,e-1,!f);
        else if(o>=2) ans=dfs(o-2,e+1,!f);
    }
    mp[stt]=ans;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        s=0;
        cin>>n;
        rep(i,1,n) cin>>a[i];
        int cto=0,cte=0;
        rep(i,1,n) {
            cto+=a[i]%2;
            cte+=a[i]%2==0;
            s+=a[i];
            int ans=0;
            int o=cto,e=cte;
            int ttt=o/3;
            ans+=ttt;
            o-=ttt*3, e+=ttt;
            ans+=dfs(o,e,true);
            cout<<s-ans<<' ';
        }
        cout<<endl;
    }
    return 0;
}