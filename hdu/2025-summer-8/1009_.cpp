#include <bits/stdc++.h>
using namespace std;

long long simulate(const vector<int>& arr, int w) {
    vector<int> people = arr;
    long long total = 0;
    while (true) {
        long long sum = 0;
        for (int v : people) sum += v;
        total += sum;
        if ((int)people.size() < w) break;
        vector<int> next;
        for (int i = 0; i < (int)people.size(); i++) {
            if ((i + 1) % w != 0) next.push_back(people[i]);
        }
        people.swap(next);
    }
    return total;
}

long long brute_force(int n, int w) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1); // 1..n
    long long best = 0;
    do {
        best = max(best, simulate(arr, w));
    } while (next_permutation(arr.begin(), arr.end()));
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, w;
        cin >> n >> w;
        cout << brute_force(n, w) << "\n";
    }
    return 0;
}
