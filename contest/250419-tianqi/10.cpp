#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
struct Point {
    int x;
    int y;
    bool operator<(const Point& rhs) const{
        return y < rhs.y;
    };
};
struct Answer {
    vector<Point> pt;
    Answer(Point x, Point y, Point z) {
        pt = {x, y, z};
    }
    Answer(int x, int y, int z) {
        pt = {{x, 0}, {y, 1}, {z, 2}};
    }
    bool operator<(const Answer& rhs) const {
        if (pt[1].x != rhs.pt[1].x) {
            return pt[1].x < rhs.pt[1].x;
        } else {
            return pt[0].x < rhs.pt[0].x;
        }
    };
    Point& operator[](const int i) {
        return pt[i];
    }
    void sort() {
        std::sort(pt.begin(), pt.end());
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_set<int> Point;
    unordered_set<int> a[3] = {};
    set<Answer> ans;
    rep(i,1,n) {
        int x, y; cin >> x >> y;
        a[y].insert(x);
    }
    if(a[2].size() >= a[0].size() && a[2].size() >= a[1].size()) {
        for(auto &i0 : a[0]) {
            for(auto &i1 : a[1]) {
                if(a[2].count(2*i1 - i0)) {
                    Answer now(i0, i1, 2*i1 - i0);
                    now.sort();
                    ans.insert(now);
                }
            }
        }
    }else if(a[0].size() >= a[1].size() && a[0].size() >= a[2].size()) {
        for(auto &i2 : a[2]) {
            for(auto &i1 : a[1]) {
                if(a[0].count(2*i1 - i2)) {
                    Answer now(2*i1 - i2, i1, i2);
                    now.sort();
                    ans.insert(now);
                }
            }
        }
    }else{
        for(auto &i0 : a[0]) {
            for(auto &i2 : a[2]) {
                if((i0 + i2) % 2 != 0) continue;
                if(a[1].count((i0 + i2) / 2)) {
                    Answer now(i0, (i0+i2)/2, i2);
                    now.sort();
                    ans.insert(now);
                }
            }
        }
    }
    if(ans.size() > 0) {
        for(auto i : ans) {
            printf("[%d, %d] [%d, %d] [%d, %d]\n", i[0].x, i[0].y, i[1].x, i[1].y, i[2].x, i[2].y);
        }
    }else{
        cout << -1 << endl;
    }
}