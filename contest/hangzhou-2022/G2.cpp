#include <iostream>
using namespace std;

constexpr size_t MAXN = 1e5 + 5;
using ull = unsigned long long;

struct Edge {
    size_t to;
    Edge *next;
} edges[MAXN * 2];

struct Vertex {
    Edge *first;
    size_t fa;
    bool is_visited;
    bool is_ring;
} vertices[MAXN];

struct TNode {
    ull hash;
} nodes[MAXN];

size_t n_edges = 0;
void add_edge(size_t u, size_t v)
{
    n_edges++;
    edges[n_edges] = {v, vertices[u].first};
    vertices[u].first = edges + n_edges;
    n_edges++;
    edges[n_edges] = {u, vertices[v].first};
    vertices[v].first = edges + n_edges;
}

size_t dfs(size_t u, size_t fa = 0)
{
    vertices[u].fa = fa;
    if (vertices[u].is_visited)
    {
        return u;
    }
    vertices[u].is_visited = true;
    for (Edge *e = vertices[u].first; e; e = e->next)
    {
        size_t v = e->to;
        if (v != fa)
        {
            size_t ans = dfs(v, u);
            if (ans != 0)
            {
                return ans;
            }
        }
    }
    return 0;
}

constexpr ull mask = 201196838060716227651722188221965ull;

ull shift(ull x)
{
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

void tree_hash(size_t u, size_t fa = 0)
{
    nodes[u].hash = 1;
    for (Edge *e = vertices[u].first; e; e = e->next)
    {
        size_t v = e->to;
        if (v != fa && !vertices[v].is_ring)
        {
            vertices[v].fa = u;
            tree_hash(v, u);
            nodes[u].hash += shift(nodes[v].hash);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    size_t t;
    cin >> t;
    while (t--)
    {
        size_t n, m;
        cin >> n >> m;
        for (size_t i = 1; i <= n; i++)
        {
            vertices[i].first = nullptr;
            vertices[i].is_ring = false;
            vertices[i].is_visited = false;
        }
        for (size_t i = 1; i <= m; i++)
        {
            size_t u, v;
            cin >> u >> v;
            add_edge(u, v);
        }
        if (m == n - 1)
        {
            cout << "YES\n";
        }
        else if (m > n)
        {
            cout << "NO\n";
        }
        else
        {
            size_t u = dfs(1);
            vertices[u].is_ring = true;
            for (size_t v = vertices[u].fa; v != u; v = vertices[v].fa)
            {
                vertices[v].is_ring = true;
            }
            tree_hash(u);
            ull h = nodes[u].hash;
            bool flag = true;
            for (size_t v = vertices[u].fa; v != u; v = vertices[v].fa)
            {
                tree_hash(v);
                if (nodes[v].hash != h)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}