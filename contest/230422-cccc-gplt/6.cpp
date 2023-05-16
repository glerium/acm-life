#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int main(){
    cin>>s;
    int k; cin>>k;
    while(k--) {
        int x,y; cin>>x>>y; x--,y--;
        string s1,s2; cin>>s1>>s2;
        string cut;
        string newstr;
        for(int i=x;i<=y;i++) cut+=s[i];
        for(int i=0;i<x;i++) newstr+=s[i];
        for(int i=y+1;i<s.size();i++) newstr+=s[i];

        string all=s1+s2;
        int ind=newstr.find(all);
        string new2;
        if(ind!=-1){
            for(int i=0;i<ind+s1.size();i++) new2+=newstr[i];
            new2+=cut;
            for(int i=ind+s1.size();i<newstr.size();i++) new2+=newstr[i];
        }else{
            new2=newstr+cut;
        }
        s=new2;
        //cout<<s<<endl;
    }
    cout<<s<<endl;
    return 0;
}
