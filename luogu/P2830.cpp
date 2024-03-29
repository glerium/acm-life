#include <bits/stdc++.h>
using namespace std;
string s1, s2;
struct Array {
    string name;
    int lim;
    vector<int> a;
};
map<string, Array> mp;
struct Variable {
    string name;
    int i;
};
Variable get_var_name(string s) {
    int ct = 0;
    for(auto i:s) ct+=i=='[';
    if(ct == 0) {
        int val = 0;
        for(auto i:s) 
            val = val * 10 + i - '0';
        return {"", val};
    }
    string name;
    int i = 0;
    while(s[i] != '[') {
        name += s[i];
        i++;
    }
    if(ct == 1) {
        i++;
        int idx = 0;
        while(s[i] != ']') {
            idx = idx * 10 + s[i] - '0';
            i++;
        }
        return {name, idx};
    }else{
        auto var = get_var_name(s.substr(i+1, s.size()-i-2));
        if(mp[var.name].lim <= var.i) {
            cout << -1 << endl;
            exit(0);
        }
        int idx = mp[var.name].a[var.i];
        return {name, idx};
    }
}
int get_var_value(Variable var) {
    if(var.name == "") return var.i;
    else return mp[var.name].a[var.i];
}
int main() {
    while(true) {
        cin >> s1 >> s2;
        if(cin.eof()) return 0;
        if(s1 == "int") {
            auto var = get_var_name(s2);
            mp[var.name] = {var.name, var.i, vector<int>(var.i)};
        }else if(s1 == "cout") {
            auto var = get_var_name(s2);
            if(mp[var.name].lim <= var.i) {
                cout << -1 << endl;
                return 0;
            }
            cout << mp[var.name].a[var.i] << endl;
        }else{
            auto var1 = get_var_name(s1),
                 var2 = get_var_name(s2);
            if(mp[var1.name].lim <= var1.i || var2.name != "" && mp[var2.name].lim <= var2.i) {
                cout << -1 << endl;
                return 0;
            }
            mp[var1.name].a[var1.i] = get_var_value(var2);
        }
    }
    return 0;
}