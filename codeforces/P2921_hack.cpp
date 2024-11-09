#include <iostream>
using namespace std;
int main() {
    freopen("in.txt", "w", stdout);
    int n = 1e5;
    cout << n << endl;
    cout << n << " ";
    for(int i=1;i<=n-1;i++)
        cout << i << " ";
    cout << endl;
    return 0;
}