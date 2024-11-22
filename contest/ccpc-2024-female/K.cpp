#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4+10;
typedef long long ll;
int n,m,p,q;
struct stu
{
    string name;
    int z1,d1,t1,z2,d2,t2,zc,zc1,zc2,jx,zy;
    int zyrank1,zyrank2;
    bool bzy11,bzy12,bzy13,bzy21,bzy22,bzy23;
    friend istream& operator>>(istream& in,stu& p)
    {
        in>>p.name>>p.z1>>p.d1>>p.t1>>p.z2>>p.d2>>p.t2;
        return in;
    }
    void print()
    {
        cout<<"name:"<<name<<" zc1:"<<zc1<<" zc2:"<<zc2<<" jx:"<<jx<<'\n';
    }
}s[maxn];
bool cmpzcpm1(stu s1,stu s2)//zong ce pai ming
{
    if(s1.zc1!=s2.zc1) return s1.zc1>s2.zc1;
    if(s1.z1!=s2.z1) return s1.z1>s1.z1;
    return s1.name<s2.name;
}
bool cmpzcpm2(stu s1,stu s2)//zong ce pai ming
{
    if(s1.zc2!=s2.zc2) return s1.zc2>s2.zc2;
    if(s1.z1!=s2.z2) return s1.z2>s1.z2;
    return s1.name<s2.name;
}
bool cmpzy1(stu s1,stu s2)//zhi yu
{
    return s1.z1>s2.z1;
}
bool cmpzy2(stu s1,stu s2)//zhi yu
{
    return s1.z2>s2.z2;
}
bool cmpszf(stu s1,stu s2)
{
    if(s1.jx!=s2.jx) return s1.jx>s2.jx;
    if(s1.zc!=s2.zc) return s1.zc>s2.zc;
    if(s1.zy!=s2.zy) return s1.zy>s2.zy;
    return s1.name<s2.name;
}
void init()
{
    for(int i=0;i<n;i++)
    {
        s[i].zc1=s[i].z1+s[i].d1+s[i].t1;
        s[i].zc2=s[i].z2+s[i].d2+s[i].t2;
        s[i].zc=s[i].z1+s[i].d1+s[i].z1+s[i].z2+s[i].d2+s[i].z2;
        s[i].zy=s[i].z1+s[i].z2;
        s[i].jx=0;
    }
}
void init1()
{
    sort(s,s+n,cmpzy1);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp[s[i].z1]==0)
        {
            mp[s[i].z1]=i+1;
        }
        s[i].zyrank1=mp[s[i].z1];
        s[i].bzy11=(100*s[i].zyrank1<=n*25);
        s[i].bzy12=(100*s[i].zyrank1<=n*45);
        s[i].bzy13=(100*s[i].zyrank1<=n*75);
    }
}
void init2()
{
    sort(s,s+n,cmpzy2);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp[s[i].z2]==0)
        {
            mp[s[i].z2]=i+1;
        }
        s[i].zyrank2=mp[s[i].z2];
        s[i].bzy21=(100*s[i].zyrank2<=n*25);
        s[i].bzy22=(100*s[i].zyrank2<=n*45);
        s[i].bzy23=(100*s[i].zyrank2<=n*75);
    }
}
void solve() {
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    cin>>m>>p>>q;
    int ans=1e9;
    int zhkzy1,zhkzy2;
    for(int i=0;i<n;i++)
    {
        if(s[i].name=="crazyzhk")
        {
            zhkzy1=s[i].z1;
            zhkzy2=s[i].z2;
        }
    }
    init();init1();init2();
    // for(int i=0;i<n;i++)s[i].print();
    for(int ip=zhkzy1;ip<=100;ip++)
    {
        // int ip=zhkzy1,iq=zhkzy2;
        for(int iq=zhkzy2;iq<=100;iq++)
        {
            int jxj11=15*n/100;
            int jxj12=25*n/100;
            int jxj13=35*n/100;
            int jxj21=15*n/100;
            int jxj22=25*n/100;
            int jxj23=35*n/100;
            for(int i=0;i<n;i++)
            {
                if(s[i].name=="crazyzhk")
                {
                    s[i].z1=ip;
                    s[i].z2=iq;
                    init();
                    init1();
                    init2();
                }
            }
            sort(s,s+n,cmpzcpm1);
            for(int i=0;i<n;i++)
            {
                if(s[i].bzy11&&jxj11)
                {
                    jxj11--;
                    s[i].jx+=15;
                    continue;
                }
                if(s[i].bzy12&&jxj12)
                {
                    jxj12--;
                    s[i].jx+=10;
                    continue;
                }
                if(s[i].bzy13&&jxj13)
                {
                    jxj13--;
                    s[i].jx+=5;
                    continue;
                }
            }
            sort(s,s+n,cmpzcpm2);
            for(int i=0;i<n;i++)
            {
                if(s[i].bzy21&&jxj21)
                {
                    jxj21--;
                    s[i].jx+=15;
                    continue;
                }
                if(s[i].bzy22&&jxj22)
                {
                    jxj22--;
                    s[i].jx+=10;
                    continue;
                }
                if(s[i].bzy23&&jxj23)
                {
                    jxj23--;
                    s[i].jx+=5;
                    continue;
                }
            }
            sort(s,s+n,cmpszf);
            for(int i=0;i<n;i++)
            {
                // s[i].print();
                if(s[i].name=="crazyzhk")
                {
                    if(i+1<=m)
                    {
                        // for(int j=0;j<n;j++)s[j].print();
                        ans=min(ans,(ip-zhkzy1)*p+(iq-zhkzy2)*q);
                    }
                }
            }
        }
    }
    if(ans==1e9)
    {
        cout<<"Surely next time";
    }
    else
    {
        cout<<ans;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}