#include <bits/stdc++.h>
using namespace std;
int t,n,k,x;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k>>x;
        if(x!=1) {
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for(int i=1;i<=n;i++) cout<<1<<' ';
            cout<<endl;
        }
        else {
            if(n==1||k==1) cout<<"NO"<<endl;
            else if(k==2&&n%2!=0) cout<<"NO"<<endl;
            else {
                cout<<"YES"<<endl;
                vector<int> vec;
                while(n>3) {
                    n-=2;
                    vec.push_back(2);
                }
                if(n==2) vec.push_back(2);
                else vec.push_back(3);
                cout<<vec.size()<<endl;
                for(auto i:vec) cout<<i<<' ';
                cout<<endl;
            }
        }
    }
    return 0;
}