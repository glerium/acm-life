#include <bits/stdc++.h>
#define yes {puts("YES"); continue;}
#define no {puts("NO"); continue;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int maxn=2e5+10;
int n,q,x,y,l,r;
string s;
pii way[maxn], wayr[maxn];
map<pii,vector<int>> tml, tmr;
pii operator+(const pii& rhs,const pii& lhs) {return {rhs.first+lhs.first,rhs.second+lhs.second};}
pii operator-(const pii& rhs,const pii& lhs) {return {rhs.first-lhs.first,rhs.second-lhs.second};}
void generate_way(string s, pii *way, map<pii,vector<int>>& tm) {
    pii now={0,0};
    int ct=0;
    if(!tm.count(now)) tm[now]=vector<int>();
    tm[now].push_back(ct);
    for(auto i:s) {
        if(i=='U') now.second+=1;
        else if(i=='D') now.second-=1;
        else if(i=='L') now.first-=1;
        else now.first+=1;
        way[++ct]=now;
        if(!tm.count(now)) tm[now]=vector<int>();
        tm[now].push_back(ct);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>q>>s;
    generate_way(s,way,tml);
    generate_way(string(s.crbegin(),s.crend()),wayr,tmr);
    while(q--) {
        cin>>x>>y>>l>>r;
        if(tml.count({x,y})&&tml[{x,y}][0]<l) yes;
        if(tml.count({x,y})&&tml[{x,y}][tml[{x,y}].size()-1]>=r) yes;
        pii rx=way[r]+make_pair(x,y)-way[l-1];
        vector<int>& tms=tmr[rx];
        // find [l,r-1]
        int ll=n-r+1,rr=n-l+1;
        auto it=lower_bound(tms.cbegin(), tms.cend(), ll);
        if(it!=tms.end()&&*it<=rr) puts("YES");
        else puts("NO");
    }
    return 0;
}