#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
int t, n, s1, s2, r[maxn], s[maxn], ss[maxn];
struct item{
    int id;
    int r;
    bool operator<(const item& rhs)const{
        return r>rhs.r;
    }
}a[maxn];
vector<int> ans1, ans2;
vector<int> ans11, ans22;
int main() {
    cin>>t;
    while(t--){
        cin>>n>>s1>>s2;
        for(int i=1;i<=n;i++){
            cin>>r[i];
            a[i] = (item){i, r[i]};
        } 
        sort(a+1,a+1+n);
        // ll ans=LLONG_MAX;
        ans1.clear();
        ans2.clear();
        // ll sm1=0, sm2=0;
        for(int i=1;i<=n;i++){
            if((ans1.size()+1)*s1<(ans2.size()+1)*s2) {
                ans1.push_back(a[i].id);
                // sm1+=a[i].r * ans1.size();
            } else {
                ans2.push_back(a[i].id);
                // sm2+=a[i].r * ans2.size();
            }
            // printf(",,,%d %d %d %d",ans1.size(),ans2.size(),s1,s2);
        }
        // ans = s1*sm1+s2*sm2;

        // ll anss=LLONG_MAX;
        // ans11.clear();
        // ans22.clear();
        // sm1=0, sm2=0;
        // for(int i=1;i<=n;i++){
        //     if(ans11.size()*s1>ans22.size()*s2) {
        //         ans22.push_back(a[i].id);
        //         sm2+=a[i].r * ans22.size();
        //     } else {
        //         ans11.push_back(a[i].id);
        //         sm1+=a[i].r * ans11.size();
        //     }
        //     printf(",,,%d %d %d %d",ans11.size(),ans22.size(),s1,s2);
        // }
        // anss = s1*sm1+s2*sm2;
        
        // if(ans > anss) {
        //     ans1 = ans11;
        //     ans2 = ans22;
        //     ans = anss;
        // }
        cout<<ans1.size()<<' ';
        for(auto i : ans1) cout<<i<<' ';
        cout<<endl;
        cout<<ans2.size()<<' ';
        for(auto i : ans2) cout<<i<<' ';
        cout<<endl;
        // cout<<ans<<":"<<anss<<endl;
    }

}