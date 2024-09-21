#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
struct Problem {
    string id;
    int teams;
    bool operator<(const Problem& rhs)const{
        if(teams != rhs.teams)
            return teams > rhs.teams;
        return id < rhs.id;
    }
};
void solve() {
    int n; cin >> n;
    map<string, set<string>> mp;
    rep(i,1,n) {
        string team, prob, ac;
        cin >> team >> prob >> ac;
        if(ac[0] == 'r') continue;
        mp[prob].insert(team);
    }
    vector<Problem> pb;
    for(auto [x,y] : mp) {
        Problem tmp;
        tmp.id = x;
        tmp.teams = y.size();
        pb.push_back(tmp);
    }
    sort(pb.begin(), pb.end());
    cout << pb.begin()->id << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}