#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const int base=103;
const ll mod=998244353;
int n,h[maxn],m,to_idx[107],ct;
ll base_[maxn];
ll hsh[107][maxn];
struct Piece{
    int k;
    ll hash;
}p[107];
map<int,int> mp;
bool used[maxn];
deque<int> stk;
bool dfs(int pos) {
    //printf("(%d)",pos);
    if(pos==n) return true;
    for(int i=1;i<=m;i++) {
        //if(pos==1) printf("%d: %d\n",i,used[i]);
        if(!used[i] && pos+p[i].k-1<=n && hsh[mp[p[i].k]][pos]==p[i].hash) {
            stk.push_back(i);
            used[i]=true;
            if(dfs(pos+p[i].k-1)) return true;
            used[i]=false;
            stk.pop_back();
        }
    }
    return false;
}
signed main() {
    base_[0]=1;
    for(int i=1;i<=1e4+1;i++) base_[i]=(base_[i-1]*base)%mod;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>p[i].k;
        ll now_hash=0;
        for(int j=1;j<=p[i].k;j++){
            int tmp; cin>>tmp;
            p[i].hash=(p[i].hash*base+tmp)%mod;
        }
        if(!mp.count(p[i].k)){
            to_idx[++ct]=p[i].k;
            mp.insert(make_pair(p[i].k,ct));
        }
    }
    for(int i=1;i<=ct;i++) {
        for(int j=1;j<=to_idx[i];j++) {
            hsh[i][1]=(hsh[i][1]*base+h[j])%mod;
        }
        for(int j=2;j+to_idx[i]-1<=n;j++) {
            //printf("deb: %d %d %d %d\n",to_idx[i],j,j-1,j+to_idx[i]-1);
            hsh[i][j]=(((hsh[i][j-1]-base_[to_idx[i]-1]*h[j-1])%mod+mod)*base + h[j+to_idx[i]-1])%mod;
        }
    }
    /*
    for(int i=1;i<=m;i++) cout<<p[i].hash<<' ';
    cout<<endl;
    for(int i=1;i<=ct;i++){
        cout<<to_idx[i]<<':';
        for(int j=1;j+p[i].k-1<=n;j++)
            cout<<hsh[i][j]<<' ';
        cout<<endl;
    }
    */
    dfs(1);
    while(!stk.empty()){
        int tmp=stk.front();
        cout<<tmp;
        stk.pop_front();
        if(!stk.empty()) cout<<' ';
    }
    return 0;
}
