/*
ID: wenzeli1
TASK: gift1
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int n;
map<string,int> mp;
map<int,string> ord;
int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    fin>>n;
    rep(i,1,n) {
        string name; fin>>name;
        mp[name]=0; ord[i]=name;
    }
    rep(i,1,n) {
        string s; fin>>s;
        int k,m; fin>>k>>m;
        if(!m) continue;
        int each=k/m;
        rep(j,1,m) {
            string ss; fin>>ss;
            mp[ss]+=each;
            mp[s]-=each;
        }
    }
    rep(i,1,n) 
        fout<<ord[i]<<' '<<mp[ord[i]]<<endl;
    return 0;
}