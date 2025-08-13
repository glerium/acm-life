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
    printf("? ");
    for(auto i : a)
        printf("%d ", i);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
void answer(const vector<int>& a, int n) {
    printf("! ");
    rep(i,1,n) {
        if(a[i] == '0')
            printf("(");
        else
            printf(")");
    }
    printf("\n");
    fflush(stdout);
}
int tab[10][10];
void solve() {
    int n; scanf("%d", &n);
    if(n <= 4) {
        vector<int> ans(n+5);
        rep(i,1,n) rep(j,1,n) {
            vector<int> tmp = {i, j};
            int ret = ask(tmp);
            if(ret != 0) {
                ans[i] = 0;
                ans[j] = 1;
            }
        }
        answer(ans, n);
        printf("\n");
        fflush(stdout);
        return;
    }
    int mp[n+5] = {};
    rep(i,1,n) mp[i] = i;
    random_shuffle(mp + 1, mp + 1 + n);
    int rmp[n+5] = {};
    rep(i,1,n) rmp[mp[i]] = i;
    vector<int> ans(n+5), unk;
    for(int i=1;i<=n;i+=4) {
        vector<int> tmp1 = {i, i+1, i+2, i+3, i, i+1, i+2, i+3};
        int ret1 = ask(tmp1);
        vector<int> tmp2 = {i+3, i+2, i+1, i, i, i+1, i+2, i+2};
        int ret2 = ask(tmp2);
        if(ret1 && ret2) {
            int now = tab[ret1][ret2];
            rep(j,0,3) {
                ans[i+j] = bool(now & (1 << (3 - j)));
            }
        } else {
            unk.push_back(i);
        }
    }
}
int main() {
    tab[9][0] = 1;
    tab[7][11] = 2;
    tab[12][8] = 3;
    tab[5][6] = 4;
    tab[10][4] = 5;
    tab[8][11] = 6;
    tab[9][6] = 7;
    tab[3][6] = 8;
    tab[8][4] = 9;
    tab[6][11] = 10;
    tab[7][6] = 11;
    tab[4][8] = 12;
    tab[5][4] = 13;
    tab[3][7] = 14;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int t; cin>>t;
    while(t--) solve();
    return 0;
}