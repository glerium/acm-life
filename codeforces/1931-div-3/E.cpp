#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
int t;
array<int,2> count_digit(int x){
    int ct = 0;
    while(x % 10 == 0) {
        ct++;
        x /= 10;
    }
    int ct2 = 0;
    while(x) {
        ct2++;
        x /= 10;
    }
    return {ct,ct2};
};
int count_digit2(int x) {
    int ct = 0;
    while(x) {
        ct++;
        x /= 10;
    }
    return ct;
};
bool mygreater(int x, int y) {
    return count_digit(x)[0] < count_digit(y)[0];
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans = 0;
    priority_queue<int,vector<int>,function<bool(int,int)>> q(mygreater);
    for(int i=1;i<=n;i++) q.push(a[i]);
    bool isadd = false;
    while(!q.empty()) {
        int now = q.top(); q.pop();
        if(isadd) ans+=count_digit2(now);
        else ans+=count_digit(now)[1];
        isadd = !isadd;
    }
    puts(ans > m ? "Sasha" : "Anna");
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) solve();
}