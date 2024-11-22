#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a[20][20];
map<string,int> mp;
vector<vector<int>> ansv;
vector<int> ch;
int cnt[20]={7,7,9,7,5,7,13,9,11,9};
int mass[20]={89,133,132,121,75,105,149,119,146,147};
int m,n;
void print(vector<int> b)
{
    string ans[20];
    int maxn=0;
    for(auto it:b)maxn=max(maxn,cnt[it]);
    if(b.size()==1)
    {
        for(int i=0;i<maxn;i++)
        {
            ans[i]+=a[b.front()][i];
        }
    }
    else
    {
        for(int i=0;i<maxn;i++) //tou
        {
            if(i==2)ans[i]+=a[b.front()][i].substr(0,8);
            else ans[i]+=a[b.front()][i].substr(0,9);
        }
        ans[2]+="-";
        for(int j=1;j+1<b.size();j++)
        {
            for(int i=0;i<maxn;i++) //zhong
            {   
                if(i==2)ans[i]+=a[b[j]][i].substr(1,7);
                else ans[i]+=a[b[j]][i].substr(1,8);
            }
            ans[2]+="-";
        }
        for(int i=0;i<maxn;i++) //wei
        {
            ans[i]+=a[b.back()][i].substr(1,10);
        }
    }
    for(int i=0;i<maxn;i++)
        cout<<ans[i]<<'\n';
}
void dfs(int _i,vector<int> v,int _mass)
{
    // for(auto it:v)cout<<it<<' ';cout<<v.size()<<' '<<_mass<<'\n';
    if(_mass>n)return;
    if(_i==0)
    {
        for(auto it:ch)
        {
            if(_mass+mass[it]<=n)
            {
                v.push_back(it);
                dfs(_i+1,v,_mass+mass[it]);
                v.pop_back();
            }
        }
    }
    else
    {
        for(auto it:ch)
        {
            if(_mass+mass[it]-18<=n)
            {
                v.push_back(it);
                ansv.push_back(v);
                dfs(_i+1,v,_mass+mass[it]-18);
                v.pop_back();
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            a[i][j]="           ";
    mp["Ala"]=0;
    mp["Asp"]=1;
    mp["Asn"]=2;
    mp["Cys"]=3;
    mp["Gly"]=4;
    mp["Ser"]=5;
    mp["Met"]=6;
    mp["Thr"]=7;
    mp["Gln"]=8;
    mp["Glu"]=9;
    int f2[10]={};
    int t=0;
    for(auto it:mp)
    {
        f2[it.second]=t++;
    }
    a[0][0]="  H H O    ";
    a[0][1]="  | | ||   ",                        
    a[0][2]="H-N-C-C-O-H",                        
    a[0][3]="    |      ",                        
    a[0][4]="  H-C-H    ",                        
    a[0][5]="    |      ",                        
    a[0][6]="    H      ";

    a[1][0]="  H H O    ",
    a[1][1]="  | | ||   ",
    a[1][2]="H-N-C-C-O-H",
    a[1][3]="    |      ",
    a[1][4]="  H-C-H    ",
    a[1][5]="    |      ",
    a[1][6]="  O=C-O-H  ";

    a[2][0]="  H H O    ",
    a[2][1]="  | | ||   ",
    a[2][2]="H-N-C-C-O-H",
    a[2][3]="    |      ",
    a[2][4]="  H-C-H    ",
    a[2][5]="    |      ",
    a[2][6]="  O=C-N-H  ",
    a[2][7]="      |    ",
    a[2][8]="      H    ";

    a[3][0]="  H H O    ",
    a[3][1]="  | | ||   ",
    a[3][2]="H-N-C-C-O-H",
    a[3][3]="    |      ",
    a[3][4]="  H-C-S-H  ",
    a[3][5]="    |      ",
    a[3][6]="    H      ";

    a[4][0]="  H H O    ",
    a[4][1]="  | | ||   ",
    a[4][2]="H-N-C-C-O-H",
    a[4][3]="    |      ",
    a[4][4]="    H      ";

    a[5][0]="  H H O    ",
    a[5][1]="  | | ||   ",
    a[5][2]="H-N-C-C-O-H",
    a[5][3]="    |      ",
    a[5][4]="  H-C-O-H  ",
    a[5][5]="    |      ",
    a[5][6]="    H      ";

    a[6][0]="  H H O    ",
    a[6][1]="  | | ||   ",
    a[6][2]="H-N-C-C-O-H",
    a[6][3]="    |      ",
    a[6][4]="  H-C-H    ",
    a[6][5]="    |      ",
    a[6][6]="  H-C-H    ",
    a[6][7]="    |      ",
    a[6][8]="    S      ",
    a[6][9]="    |      ",
   a[6][10]="  H-C-H    ",
   a[6][11]="    |      ",
   a[6][12]="    H      ";

    a[7][0]="  H H O    ",
    a[7][1]="  | | ||   ",
    a[7][2]="H-N-C-C-O-H",
    a[7][3]="    |      ",
    a[7][4]="  H-C-O-H  ",
    a[7][5]="    |      ",
    a[7][6]="  H-C-H    ",
    a[7][7]="    |      ",
    a[7][8]="    H      ";

    a[8][0]="  H H O    ",
    a[8][1]="  | | ||   ",
    a[8][2]="H-N-C-C-O-H",
    a[8][3]="    |      ",
    a[8][4]="  H-C-H    ",
    a[8][5]="    |      ",
    a[8][6]="  H-C-H    ",
    a[8][7]="    |      ",
    a[8][8]="  O=C-N-H  ",
    a[8][9]="      |    ",
   a[8][10]="      H    ";

    a[9][0]="  H H O    ",
    a[9][1]="  | | ||   ",
    a[9][2]="H-N-C-C-O-H",
    a[9][3]="    |      ",
    a[9][4]="  H-C-H    ",
    a[9][5]="    |      ",
    a[9][6]="  H-C-H    ",
    a[9][7]="    |      ",
    a[9][8]="  O=C-O-H  ";

    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        ch.push_back(mp[s]);
    }
    vector<int> v;
    dfs(0,v,0);
    sort(ansv.begin(),ansv.end(),[f2](vector<int> a,vector<int> b)->bool
    {
        for(auto &x:a)x=f2[x];
        for(auto &x:b)x=f2[x];
        for(int i=0;i<min(a.size(),b.size());i++)
        {
            if(a[i]!=b[i])return a[i]<b[i];
        }
        return a.size()<b.size();
    });
    cout<<ansv.size()<<'\n';
    for(int i=0;i<ansv.size();i++)
    {
        print(ansv[i]);
        if(i!=ansv.size()-1)cout<<'\n';
    }
    return 0;
}