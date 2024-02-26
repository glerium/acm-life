#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin>>n;
    char c; cin>>c;
    map<string,int> mp;
    for(int i=1;i<=2*n;i++) {
        string s; cin>>s;
        mp[s]++;
    }
    auto card = [] (char suit, int rank) -> string {
        return string() + char('0' + rank) + suit;
    };
    const char suits[] = {'C', 'D', 'H', 'S'};
    struct Result{
        string x,y;
        bool del = false;
    };
    int ct_trump=0, ct_non=0;
    for(char i:suits) {
        for(int j=2;j<=9;j++) {
            if(!mp.count(card(i,j))) continue;
            if(i==c) ct_trump += mp[card(i,j)];
            else ct_non += mp[card(i,j)];
        }
    }
    if((ct_trump - ct_non) % 2 != 0) {
        puts("IMPOSSIBLE");
        return;
    }
    vector<string> non_remain,trump_remain;
    vector<array<string,2>> non_used,trump_used;
    for(char i:suits) {
        if(i==c) continue;
        for(int j=2;j<=9;j++) {
            if(!mp.count(card(i,j))) continue;
            for(int k=j+1;k<=9;k++) {
                if(!mp.count(card(i,k))) continue;
                int del = min(mp[card(i,k)],mp[card(i,j)]);
                for(int tt=1;tt<=del;tt++) 
                    non_used.push_back({card(i,j), card(i,k)});
                mp[card(i,k)]-=del; mp[card(i,j)]-=del;
            }
        }
        for(int j=2;j<=9;j++) {
            if(!mp.count(card(i,j))) continue;
            for(int k=1;k<=mp[card(i,j)];k++) non_remain.push_back(card(i,j));
        }
    }
    if(non_remain.size() > ct_trump) {
        puts("IMPOSSIBLE");
        return;
    }
    for(int i=2;i<=9;i++) {
        if(!mp.count(card(c,i))) continue;
        for(int j=i+1;j<=9;j++) {
            if(!mp.count(card(c,j))) continue;
            int del=min(mp[card(c,i)],mp[card(c,j)]);
            for(int tt=1;tt<=del;tt++) 
                trump_used.push_back({card(c,i), card(c,j)});
            mp[card(c,i)]-=del; mp[card(c,j)]-=del;
        }
    }
    for(int i=2;i<=9;i++) {
        if(!mp.count(card(c,i))) continue;
        for(int j=1;j<=mp[card(c,i)];j++)
            trump_remain.push_back(card(c,i));
    }
    if(trump_remain.size() > 0) {
        for(auto i:trump_remain) {
            auto j=non_remain.begin();
            if(j!=non_remain.end()) {
                trump_used.push_back({*j,i});
                non_remain.erase(j);
            }else{
                puts("IMPOSSIBLE");
                return;
            }
        }
    }
    if(non_remain.size() > 0) {
        if(non_remain.size() % 2 != 0) {
            puts("IMPOSSIBLE");
            return;
        }
        for(int i=0;i<non_remain.size();i+=2) {
            auto j = trump_used.begin();
            if(j==trump_used.end()) {
                puts("IMPOSSIBLE");
                return;
            }
            trump_used.erase(j);
            non_used.push_back({non_remain[i],(*j)[0]});
            non_used.push_back({non_remain[i+1],(*j)[1]});
        }
    }
    for(auto [x,y]:non_used) cout<<x<<' '<<y<<endl;
    for(auto [x,y]:trump_used) cout<<x<<' '<<y<<endl;
}
int main() {
    int t; cin>>t;
    while(t--) solve();
    return 0;
}