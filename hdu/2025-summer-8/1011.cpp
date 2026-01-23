#include <bits/stdc++.h>
using namespace std; using ll = long long; int t_ = 1;
template <class T> requires (ranges::contiguous_range<T> && !is_same_v<remove_cvref_t<T>, string>) istream& operator>>(istream &in, T &c) { for (auto &x : c) in >> x; return in; }
#ifndef ONLINE_JUDGE
template <class... Args> void debug_7_divided_by_3(int testcase, int line, string name, const Args&... args) { int stk = 0; for (auto &x : name) { if (x == '(') stk++; if (x == ')') stk--; if (x == ',' && stk == 0) x = '\t'; } int i = 0; vector<string> names; for (auto part : name | views::split("\t"sv)) { names.emplace_back(part.begin(), part.end()); } cerr << format("T{}L{}: {{", testcase, line); ((cerr << format("{} = {}{}", names[i], args, (i + 1 < sizeof...(args) ? "," : "}\n")), ++i), ...); }
#define debug(...) debug_7_divided_by_3(t_, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 7 / 3
#endif

struct PHS
{
    vector<int> ver;
    void insert(int x, auto cmp)
    {
        ver.insert(ranges::lower_bound(ver, x, cmp), x);
    }
    void erase(int x, auto cmp)
    {
        ver.erase(ranges::lower_bound(ver, x, cmp));
    }
    int rank(int x, auto cmp)
    {
        return ranges::lower_bound(ver, x, cmp) - ver.begin() + 1;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    map<string, int> mp;
    vector<int> team_name_order(3 * n + 1);
    vector<pair<string, int>> team_name_v(3 * n + 1);
    vector<int> group(3 * n + 1);
    vector<vector<int>> groupin(4);
    vector<int> group_rank(3 * n + 1);
    vector<int> wins(3 * n + 1);
    vector<int> jingsheng(3 * n + 1);
    vector<int> wuxiao(k + 1);
    vector<array<int, 4>> messages(k + 1); //[A B x y]
    map<int, queue<int>> mpq;
    vector<PHS> groupPHS(4);
    for (int i = 1; i <= 3 * n; i++)
    {
        cin >> team_name_v[i].first;
        mp[team_name_v[i].first] = i;
        team_name_v[i].second = i;
        for (int j = 0; j < 5; j++)
        {
            string name;
            cin >> name;
            mp[name] = i;
        }
        int groupid;
        cin >> groupid;
        group[i] = groupid;
        groupin[groupid].push_back(i);
    }
    sort(team_name_v.begin() + 1, team_name_v.end());
    for (int i = 1; i <= 3 * n; i++)
        team_name_order[team_name_v[i].second] = i;

    auto cmp = [&](int i, int j) -> bool
    {
        if (wins[i] != wins[j]) return wins[i] > wins[j];
        if (jingsheng[i] != jingsheng[j]) return jingsheng[i] > jingsheng[j];
        return team_name_order[i] < team_name_order[j];
    };

    for (int i = 1; i <= 3 * n; i++)
        groupPHS[group[i]].insert(i, cmp);

    auto add_message = [&](int message_id) -> void
    {
        auto [A, B, x, y] = messages[message_id];
        groupPHS[group[A]].erase(A, cmp);
        groupPHS[group[B]].erase(B, cmp);
        if (x > y)
            wins[A]++;
        else
            wins[B]++;
        jingsheng[A] += x - y;
        jingsheng[B] += y - x;
        groupPHS[group[A]].insert(A, cmp);
        groupPHS[group[B]].insert(B, cmp);
    };

    auto del_message = [&](int message_id) -> void
    {
        auto [A, B, x, y] = messages[message_id];
        groupPHS[group[A]].erase(A, cmp);
        groupPHS[group[B]].erase(B, cmp);
        if (x > y)
            wins[A]--;
        else
            wins[B]--;
        jingsheng[A] -= x - y;
        jingsheng[B] -= y - x;
        groupPHS[group[A]].insert(A, cmp);
        groupPHS[group[B]].insert(B, cmp);
    };

    auto trans_int = [&](int A, int B) -> int
    {
        return 3001 * min(A, B) + max(A, B);
    };

    // auto group_sort = [&](int group_id) -> void
    // {
    //     auto &v = groupin[group_id];
    //     ranges::sort(v, cmp);
    //     for (int j = 0; j < n; j++) group_rank[v[j]] = j + 1;
    // };
    // for (int i = 1; i <= 3; i++)
    //     group_sort(i);

    int tot_message = 0;

    for (int i = 1; i <= k; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            vector<string> s(14);
            cin >> s;
            s[3].pop_back();
            int A = mp[s[3]];
            int B = mp[s[11]];
            int x, y;
            sscanf(s[13].c_str(), "%d-%d.", &x, &y);
            tot_message++;
            messages[tot_message] = {A, B, x, y};
            if (A == B || group[A] != group[B]) continue;
            add_message(tot_message);
            // group_sort(group[A]);
            auto &q = mpq[trans_int(A, B)];
            q.push(tot_message);
        }
        else if (op == 2)
        {
            int id; cin >> id;
            auto [A, B, x, y] = messages[id];
            wuxiao[id] = true;
            auto &q = mpq[trans_int(A, B)];
            bool ok = 1;
            if (q.size() && q.front() == id)
            {
                del_message(id);
                q.pop();
            }
            while (q.size() && wuxiao[q.front()]) q.pop();
            if (q.size() && !wuxiao[q.front()]) add_message(q.front());
            // if (!ok) group_sort(group[A]);
        }
        else
        {
            int id; cin >> id;
            cout << groupPHS[group[id]].rank(id, cmp) << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (t_ = 1; t_ <= t; t_ ++)
        solve();
    return 0;
}
