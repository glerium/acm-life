#include <bits/stdc++.h>
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
int ask(const vector<int>& a) {
    printf("? %d ", (int)a.size());
    for(auto i : a)
        printf("%d ", i);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
int askRange(int l, int r) {
    vector<int> vec;
    rep(i,l,r) vec.push_back(i);
    return ask(vec);
}
void answer(const vector<int>& a, int n) {
    printf("! ");
    rep(i,1,n) {
        if(a[i] == 0)
            printf("(");
        else
            printf(")");
    }
    printf("\n");
    fflush(stdout);
}
void solve() {
    int n; scanf("%d", &n);
    // find )
    function<pair<int,int>()> find = [&]() -> pair<int,int> {
        if(askRange(1, n) == 0) return {n, 1};
        int l = 1, r = n, mid, ans;
        while(l <= r) {
            mid = l + r >> 1;
            if(askRange(1, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return {ans - 1, ans};
    };
    auto [lpos, rpos] = find();
    vector<int> vec;
    for(int i=7;i>=0;i--) {
        rep(j,1,1<<i) {
            vec.push_back(lpos);
            vec.push_back(rpos);    
        }
        vec.push_back(rpos);
    }
    const int baseline = ask(vec);
    vector<int> ans(n+5);
    for(int i=1;i<=n;i+=8) {
        int p = i;
        vector<int> vec;
        vector<int> nums;
        rep(j,1,8) {
            nums.push_back(p);
            int pt2 = 8 - j;
            rep(k,1,(1<<pt2)) {
                if(k == 1) vec.push_back(p);
                else vec.push_back(lpos);
                vec.push_back(rpos);
            }
            vec.push_back(rpos);
            p = min({p+1, i+7, n});
        }
        int ret = ask(vec);
        int delta = baseline - ret;
        rep(j,0,7) {
            ans[nums[7 - j]] = (delta & (1 << j));
        }
    }
    answer(ans, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}