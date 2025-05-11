#include <bits/stdc++.h>
#define int long long // 使用long long防止整数溢出
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;

struct Edge {
    int v,c,l;
};

struct State {
    int x;
    pair<int,int> dis; // dis.first: 时间点索引, dis.second: 当前时间点内累积的长度
    
    // 定义小于运算符，使优先队列作为最小堆工作 (lexicographical comparison)
    bool operator<(const State& rhs) const {
        return dis > rhs.dis; 
    }
};

// 稀疏表（Sparse Table）实现
struct ST {
    const int n; // 稀疏表处理的元素数量 (1-indexed)
    int k_lg;    // log2(n), 用于确定稀疏表层数
    vector<int> in; // 输入数据 (1-indexed)
    vector<vector<int>> mx; // 稀疏表，mx[k][i] 表示从 i 开始的 2^k 个元素的最大值
    
    ST(int size) : n(size), in(size+1) {
        if (size > 0) {
            k_lg = __lg(size); // 计算log2(size)，避免__lg(0)
        } else {
            k_lg = 0; // 如果size为0，则log2为0
        }
        mx.resize(k_lg + 1, vector<int>(size + 1));
    }

    // 初始化稀疏表
    void init() {
        for(int i = 1; i <= n; i++) {
            mx[0][i] = in[i]; // 第0层直接是原始数据
        }
        for(int i = 0, t = 1; i < k_lg; i++, t <<= 1) {
            const int T = n - (t << 1) + 1; // 计算当前层循环的结束位置
            for(int j = 1; j <= T; j++) {
                mx[i + 1][j] = max(mx[i][j], mx[i][j + t]); // 更新下一层的值
            }
        }
    }

    // 查询区间 [l, r] 的最大值
    int getMax(int l, int r) {
        if(l > r) swap(l, r); // 确保 l <= r
        if (l < 1 || r > n || n == 0) return -1; // 处理空或无效范围
        int curr_k = (r - l + 1 == 0) ? 0 : __lg(r - l + 1); // 避免__lg(0)
        return max(mx[curr_k][l], mx[curr_k][r - (1 << curr_k) + 1]);
    }

    // 在区间 [l, r] 中查找第一个值 >= val_k 的索引
    // 返回对应的1-based索引，如果找不到则返回 -1
    int getNext(int l, int r, int val_k) {
        if (l > r || n == 0) return -1; // 空范围或稀疏表为空
        if (l < 1 || r > n) return -1; // 无效范围
        
        // 优化：如果当前区间的最大值都小于 val_k，则无需搜索
        if (getMax(l, r) < val_k) {
            return -1;
        }

        if(l == r) { // 基本情况：如果范围只剩一个元素
            if(in[l] >= val_k)
                return l;
            else
                return -1;
        } 
        
        int mid = l + (r - l) / 2; // 计算中间值，避免溢出
        // 优先在左半部分查找，确保找到的是第一个符合条件的索引
        if(getMax(l, mid) >= val_k) 
            return getNext(l, mid, val_k); 
        else // 如果左半部分不符合，则在右半部分查找
            return getNext(mid + 1, r, val_k); 
    }
};

void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<vector<Edge>> a(n+5); // 邻接表，存储图的边
    rep(i,1,m) {
        int u,v,c,l; cin >> u >> v >> c >> l;
        a[u].push_back({v,c,l});
        a[v].push_back({u,c,l});
    }
    vector<pair<int,int>> ti(k+5); // 时间点信息：ti[i].first: 成本类型, ti[i].second: 持续时间限制
    rep(i,1,k) cin >> ti[i].first >> ti[i].second;

    // 预处理：为不同成本类型（cost type）构建稀疏表
    // cost_to_indexed_durations: 映射 成本类型 -> {原始时间点索引, 持续时间限制} 列表
    map<int, vector<pair<int, int>>> cost_to_indexed_durations; 
    for (int i = 1; i <= k; ++i) {
        cost_to_indexed_durations[ti[i].first].push_back({i, ti[i].second});
    }

    // cost_to_st_map: 映射 成本类型 -> 稀疏表指针
    map<int, ST*> cost_to_st_map;
    // cost_to_original_indices_map: 映射 成本类型 -> 存储原始时间点索引的向量 (用于将ST的内部索引映射回原始ti的索引)
    map<int, vector<int>> cost_to_original_indices_map; 

    for (auto const& [cost_type, indexed_durations_vec] : cost_to_indexed_durations) {
        if (indexed_durations_vec.empty()) { // 如果该成本类型没有对应的时间点，则跳过
            continue; 
        }
        
        // current_original_indices_mapped 存储原始的 ti 索引，用于从 ST 的结果映射回来
        // 大小为 `indexed_durations_vec.size() + 1` 以支持1-indexed
        vector<int> current_original_indices_mapped(indexed_durations_vec.size() + 1); 
        ST* current_st = new ST(indexed_durations_vec.size()); // 创建稀疏表实例
        
        // 填充稀疏表的 in 数组和原始索引映射向量
        for (size_t i = 0; i < indexed_durations_vec.size(); ++i) {
            current_st->in[i+1] = indexed_durations_vec[i].second; // 存储持续时间限制
            current_original_indices_mapped[i+1] = indexed_durations_vec[i].first; // 存储原始时间点索引
        }
        current_st->init(); // 初始化稀疏表
        
        cost_to_st_map[cost_type] = current_st;
        cost_to_original_indices_map[cost_type] = current_original_indices_mapped;
    }
    
    priority_queue<State> q; // Dijkstra 的优先队列
    vector<pair<int,int>> dis(n+5); // dis[i]: 到达节点 i 的最短距离 (时间点索引, 累积长度)

    // 初始化所有节点的距离为“无穷大”
    rep(i,1,n) dis[i] = {k + 300, 0}; // k+300 作为一个足够大的时间点索引表示无穷大
    dis[1] = {1, 0}; // 起始节点1的距离：时间点1，累积长度0
    q.push({1, dis[1]});

    // Dijkstra 主循环
    while(!q.empty()) {
        auto cur = q.top();
        q.pop();
        
        // 如果当前取出的路径比已经记录的路径更长，则跳过 (处理优先队列中的陈旧条目)
        if(cur.dis > dis[cur.x]) 
            continue;

        int nowti = cur.dis.first;  // 当前路径所在的时间点索引
        int nowl = cur.dis.second;  // 当前时间点内累积的长度

        // 遍历当前节点 cur.x 的所有邻居
        for(auto [v,c,l] : a[cur.x]) { 
            // 场景1: 尝试在当前时间点内继续前进
            // 条件：边的成本类型 'c' 与当前时间点 'nowti' 的成本类型匹配
            //      且 当前累积长度 'nowl' 加上边长 'l' 不超过当前时间点 'nowti' 的持续时间限制
            if(c == ti[nowti].first && nowl + l <= ti[nowti].second) {
                auto ndis = make_pair(nowti, nowl + l); // 新距离：时间点不变，长度更新
                if(ndis < dis[v]) { // 如果这是一条更短的路径
                    dis[v] = ndis;
                    q.push({v, ndis});
                }
            } else {
                // 场景2: 无法在当前时间点内继续，需要寻找新的时间点
                int fnd = -1; // 找到的新时间点索引
                
                // 检查是否有对应成本类型的稀疏表
                if (cost_to_st_map.count(c)) { 
                    ST* st_ptr = cost_to_st_map[c];
                    const vector<int>& original_indices_mapped_vec = cost_to_original_indices_map[c];

                    // 使用 upper_bound 在原始索引映射向量中查找第一个大于 nowti 的索引
                    // original_indices_mapped_vec 是 1-indexed 的，所以从 begin() + 1 开始搜索
                    auto it = upper_bound(original_indices_mapped_vec.begin() + 1, original_indices_mapped_vec.end(), nowti);
                    
                    if (it != original_indices_mapped_vec.end()) {
                        // 找到的迭代器减去 begin() 得到在 vector 中的 0-based 索引，+1 得到 1-based 索引
                        int start_idx_in_st_in = it - original_indices_mapped_vec.begin(); 
                        
                        // 在稀疏表中使用 getNext 查找满足条件的下一个时间点
                        // 从 start_idx_in_st_in 开始搜索到稀疏表的末尾
                        int res_idx_in_st_in_array = st_ptr->getNext(start_idx_in_st_in, st_ptr->n, l);
                        
                        if (res_idx_in_st_in_array != -1) {
                            // 将稀疏表内部索引映射回原始的时间点索引
                            fnd = original_indices_mapped_vec[res_idx_in_st_in_array];
                        }
                    }
                }
                
                if(fnd == -1) // 如果没有找到合适的新的时间点，则跳过这条边
                    continue; 
                
                auto ndis = make_pair(fnd, l); // 新距离：新时间点，累积长度重置为边长 'l'
                if(ndis < dis[v]) { // 如果这是一条更短的路径
                    dis[v] = ndis;
                    q.push({v, ndis});
                }
            }
        }
    }

    // 输出结果：对于每个节点，如果可达则输出 1，否则输出 0
    rep(i,1,n) {
        if (dis[i].first < k + 300) { // 检查是否仍是“无穷大”
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << '\n';

    // 清理动态分配的稀疏表内存
    for (auto const& [cost_type, st_ptr] : cost_to_st_map) {
        delete st_ptr;
    }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭C++标准流与C标准流的同步
    cin.tie(nullptr); // 解除cin和cout的绑定，提高输入输出效率
    int t;
    cin >> t; // 读取测试用例数量
    while(t--)
        solve(); // 对每个测试用例执行 solve 函数
}