#include <iostream>
#include <queue>
using namespace std;
struct Task {
    int qnum;
    int time;
    int period;
    bool operator<(const Task& rhs) const {
        if (time != rhs.time)
            return time > rhs.time;
        return qnum > rhs.qnum;
    }
};
int main() {
    priority_queue<Task> q;
    string str;
    cin >> str;
    while(str == "Register") {
        int x, y; cin >> x >> y;
        q.push({x, y, y});
        cin >> str;
    }
    int k; cin >> k;
    int ct = 0;
    while(true) {
        Task now = q.top(); q.pop();
        cout << now.qnum << endl;
        ct++;
        if(ct == k)
            break;
        q.push({now.qnum, now.time + now.period, now.period});
    }
    return 0;
}