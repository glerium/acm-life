#include <bits/stdc++.h>
using namespace std;
int n;
struct Person {
    string name;
    int k;
    int diff;
    double avg;
    bool operator<(const Person& rhs) const {
        if(diff != rhs.diff) return diff>rhs.diff;
        else return avg < rhs.avg;
    }
}a[107];
set<int> st;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        st.clear();
        cin>>a[i].name>>a[i].k;
        int tmp;
        for(int j=1;j<=a[i].k;j++){
            cin>>tmp;
            st.insert(tmp);
        }
        a[i].diff = st.size();
        a[i].avg = 1.0*a[i].k/a[i].diff;
//        printf("diff: %d, avg: %.2f\n",a[i].diff,a[i].avg);
    }
    sort(a+1, a+1+n);
    if(n==1) cout << a[1].name << " - -";
    else if(n==2) cout<<a[1].name<<' ' <<a[2].name<<" -";
    else cout<<a[1].name<<' '<<a[2].name<<' '<<a[3].name;
    return 0;
}
