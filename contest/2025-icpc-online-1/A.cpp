#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
struct Submission {
    int team;
    char problem;
    int time;
    int result;     // 1 AC, 0 WA, -1 UNK
};
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
struct Team {
    int id;
    int problem;
    int time;
};
bool operator<(const Submission& lhs, const Submission& rhs) {
    return lhs.time < rhs.time;
}
const int inf = 114514;
void solve() {
    int n; cin >> n;
    vector<Submission> vec0, vec1;
    map<string,int> mp;
    vector<string> rmp(n+5);
    auto ok = Vec<int>(n+5, 30, 0), ok2 = Vec<int>(n+5, 30, 0);
    auto nw = Vec<int>(n+5, 0);
    auto pen = Vec<int>(n+5, 30, 0);
    auto pa = Vec<int>(n+5, 0);
    int ct = 0;
    rep(i,1,n) {
        string ss; cin >> ss;
        if(!mp.count(ss)) {
            mp[ss] = ++ct;
            rmp[ct] = ss;
        }
        Submission sub = {};
        sub.team = mp[ss];
        cin >> sub.problem >> sub.time;
        sub.problem -= 'A';
        string x; cin >> x;
        if(x[0] == 'A') sub.result = 1;
        else if(x[0] == 'R') sub.result = 0;
        else sub.result = -1;
        if(sub.result != -1) vec0.push_back(sub);
        else vec1.push_back(sub);
    }
    sort(vec0.begin(), vec0.end());
    sort(vec1.begin(), vec1.end());
    for(auto &sub : vec0) {
        if(ok[sub.team][sub.problem]) continue;
        if(sub.result == 0) pen[sub.team][sub.problem] += 20;
        else {
            ok[sub.team][sub.problem] = true;
            pa[sub.team] += pen[sub.team][sub.problem] + sub.time;
        }
    }
    Team best = {};
    best.problem = -1;
    rep(i,1,ct) {
        Team now = {};
        now.problem = 0;
        now.time = 0;
        now.id = i;
        rep(j,0,25)
            if(ok[i][j])
                now.problem++;
        now.time = pa[i];
        if(now.problem > best.problem || (now.problem == best.problem && now.time < best.time))
            best = now;
    }

    // cout << rmp[best.id] << ' ' << best.problem << ' ' << best.time << endl;
    for(auto &sub : vec1) {
        if(ok[sub.team][sub.problem]) continue;
        if(ok2[sub.team][sub.problem]) continue;
        if(sub.result == 0) pen[sub.team][sub.problem] += 20;
        else {
            ok2[sub.team][sub.problem] = true;
            pa[sub.team] += pen[sub.team][sub.problem] + sub.time;
        }
    }
    
    vector<string> ans;
    rep(i,1,ct) {
        Team now = {};
        now.id = i;
        rep(j,0,25) {
            if(ok[i][j] || ok2[i][j])
                now.problem ++;
        }
        now.time = pa[i];
        // cout << ": " << rmp[now.id] << ' ' << now.problem << ' ' << now.time << endl;
        if(now.problem > best.problem || (now.problem == best.problem && now.time <= best.time))
            ans.push_back(rmp[now.id]);
    }
    sort(ans.begin(), ans.end());
    for(auto &i : ans) cout << i << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}