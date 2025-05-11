#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU
{
    vector<int> f;
    vector<int> tag;
    int n;
    DSU(int n_)
    {
        n = n_ + 1;
        f.resize(n);
        tag.resize(n);
        iota(f.begin(), f.end(), 0);
    }
    int find(int x)
    {
        while(x != f[x])
            x = f[x] = f[f[x]];
        return x;
    }
    void merge(int x, int y)
    {
        if(find(x) == find(y)) return;
        f[y] = x;
        modifytag(x, tag[y]);
        // if(tag[y]) tag[x] = tag[y];
    }
    void modifytag(int x, int t)
    {
        x = find(x);
        tag[x] = t;
    }
    int gettag(int x)
    {
        return tag[find(x)];
    }
};
int n;
vector<int> a;
int query(vector<int> &a)
{
    cout << "0 ";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    int r;
    cin >> r;
    return r;
}
void answer(vector<int> &a)
{
    cout << "1 ";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}
vector<int> getq(int x, int y, int l, int r, int s)
{
    vector<int> a(n + 1);
    int mid = (l + r) / 2;
    for(int i = 1; i <= n; i++)
    {
        if(l <= i && i <= mid) a[i] = x;
        else if(mid < i && i <= r) a[i] = y;
        else a[i] = s;
    }
    return a;
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
vector<int> ans;
void f(int l, int r, vector<int> nums)
{
    // cerr << "f:" << l << ' ' << r << '\n';
    if(l == r)
    {
        ans[l] = nums[0];
        return;
    }
    DSU dsu(n);
    int m = nums.size();
    // shuffle(nums.begin(), nums.end(), mt);
    bool flag = false;
    for(int i1 = 0, i2 = 1; i1 < m && !flag; i2++)
    {
        if(i2 == m)
        {
            i2 = 0;
            flag = true;
        }
        auto qv = getq(nums[i1], nums[i2], l, r, nums[i1]);
        int res = query(qv);
        if(res == 0)
        {
            dsu.modifytag(nums[i1], 2);
            dsu.modifytag(nums[i2], 1);
            i1 = i2 + 1;
            i2++;
        }
        else if(res == 1)
        {
            dsu.merge(nums[i1], nums[i2]);
        }
        else if(res == 2)
        {
            dsu.modifytag(nums[i1], 1);
            dsu.modifytag(nums[i2], 2);
            i1 = i2 + 1;
            i2++;
        }
    }
    vector<int> vl, vr;
    for(int i = 1; i <= n; i++)
    {
        if(dsu.gettag(i) == 1) vl.push_back(i);
        if(dsu.gettag(i) == 2) vr.push_back(i);
    }
    int mid = (l + r) / 2;
    f(l, mid, vl);
    f(mid + 1, r, vr);
}
void solve()
{
    cin >> n;
    a.resize(n + 1);
    ans.resize(n + 1);
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    f(1, n, nums);
    answer(ans);
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // int t = 1;
    // cin >> t;
    // while(t--)
        solve();
}