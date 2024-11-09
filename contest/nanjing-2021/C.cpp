#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
const long double PI = acosl(-1);
struct Point {
    long double x, y;
    long double angle;
    bool operator<(const Point& rhs) const {
        return angle < rhs.angle;
    }
};
void solve() {
    int n; cin >> n;
    Point a[n+5];
    rep(i,1,n) {
        int x, y; cin >> x >> y;
        a[i].x = x;
        a[i].y = y;
    }
    
    if(n <= 2) {
        cout << 0 << endl;
        return;
    }
    rep(i,1,n+5) {
        if(a[i].y == 0) {
            if(a[i].x > 0) a[i].angle = 0;
            else a[i].angle = PI;
        }else if(a[i].x == 0) {
            if(a[i].y > 0) a[i].angle = PI / 2;
            else a[i].angle = PI * 1.5;
        }else if(a[i].x > 0 && a[i].y > 0)
            a[i].angle = atan(a[i].y / a[i].x);
        else if(a[i].x < 0 && a[i].y > 0)
            a[i].angle = PI - atan(abs(a[i].y / a[i].x));
        else if(a[i].x < 0 && a[i].y < 0)
            a[i].angle = PI + atan(abs(a[i].y / a[i].x));
        else if(a[i].x > 0 && a[i].y < 0)
            a[i].angle = 2 * PI - atan(abs(a[i].y / a[i].x));
    }
    sort(a+1, a+1+n);
    deque<int> q;
    // bool inq[n+5] = {};
    q.push_back(1);
    // inq[1] = true;
    for(int i=2;i<=n;i++) {
        if(a[i].angle - a[1].angle < PI) {
            q.push_back(i);
        //     inq[i] = true;
        }
    }
    int ans = int(q.size()) - 1;
    for(int i=1;i<=n;i++) {
        if(q.empty()) {
            cout << 0 << endl;
            return;
        }
        q.pop_front();
        // inq[q.front()] = false;
        if(q.empty()) {
            cout << 0 << endl;
            return;
        }
        int fidx = q.front();
        int j = q.back()+1;
        while(true) {
            // if(inq[j]) break;
            if(j > n) j = j % n;
            if(j == fidx) break;
            long double delta = a[j].angle - a[fidx].angle;
            if(delta < 0) delta += 2 * PI;
            if(delta < PI) {
                q.push_back(j);
                // inq[j] = true;
            }
            else break;
            ans = min(ans, int(q.size()) - 1);
            j++;
        }
    }
    cout << max(ans, 0) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
