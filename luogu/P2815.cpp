#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main() {
    string s; cin >> s;
    for(int i=0;i<8;i++) v.push_back(s.substr(5*i, 4));
    bool used=false;
    for(int i=0;i<8;i++) {
        if(used) continue;
        else {
            if(v[i] == "0000") {
                used = true;
                v[i] = "";
                while(i+1<8 && v[i+1] == "0000") {
                    i++;
                    v[i] = "";
                }
            }
        }
    }
    for(auto &i:v) {
        bool ok=false;
        string ans;
        for(auto &j:i) {
            if(ok) ans+=j;
            else if(j!='0') {
                ok=true;
                ans+=j;
            }
        }
        i = ans;
    }
    bool first = true;
    for(int i=0;i<8;i++) {
        if(v[i] != "") {
            cout << v[i];
            if(i!=7 && v[i+1]!="") cout << ":";
        }else{
            if(first) {
                first = false;
                cout << "::";
            }
        }
    }
}