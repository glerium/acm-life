#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
pair<string,string> make(const string &s) {
    int spacePos = s.find(' ');
    pair<string,string> ret;
    ret.first = s.substr(0, spacePos);
    ret.second = s.substr(spacePos + 1);
    ret.second.pop_back();
    return ret;
}
vector<string> split(const string& s) {
    vector<string> ret;
    string now;
    for(auto ch : s) {
        if(ch == '.') {
            ret.push_back(now);
            now.clear();
        } else {
            now += ch;
        }
    }
    ret.push_back(now);
    return ret;
}
void solve() {
    int n,m; cin >> n >> m;
    cin.ignore();
    map<string,string> mp;
    rep(i,1,n) {
        string s; getline(cin, s);
        auto ret = make(s);
        mp[ret.second] = ret.first;
    }
    rep(i,1,m) {
        string s; cin >> s;
        vector<string> query = split(s);
        string type = mp[query[0]];
        bool first = true;
        for(const auto &pos : query) {
            if(first) {
                first = false;
                continue;
            }
            int stt = 0;
            int fnd = -1;
            rep(i,5,type.size() - 1) {
                if(type[i] == ',' && stt == 0) {
                    fnd = i;
                    break;
                } else {
                    if(type[i] == '<')
                        stt++;
                    else if(type[i] == '>')
                        stt--;
                }
            }
            if(pos == "first") {
                type = type.substr(5, fnd - 5);
            } else {
                type = type.substr(fnd + 1);
                type.pop_back();
            }
        }
        cout << type << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}