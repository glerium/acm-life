#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int _,t,n,q;
char s1[maxn],s2[maxn];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> que;
int main() {
	cin>>_;
	while(_--) {
		cin>>s1+1>>s2+1>>t>>q;
		while(!que.empty()) que.pop();
		int ans=0;
		int n=strlen(s1+1);
		for(int i=1;i<=n;i++) ans+=s1[i]!=s2[i];
		
		for(int i=1;i<=q;i++) {
			//printf(":%d %d %s %s\n",i,ans,s1+1,s2+1);
			if(!que.empty()) {
				auto x = que.top();
				//printf("Got %d\n",x.first);
				if(i-x.first>=t) {
					ans+=s1[x.second]!=s2[x.second];
					que.pop();
				}
			}
			int op; cin>>op;
			if(op==1) {
				int x; cin>>x;
				int cont = s1[x]!=s2[x];
				ans-=cont;
				que.push(make_pair(i,x));
			}else if(op==2) {
				int a,b,x,y; cin>>a>>x>>b>>y;
				int con1 = (s1[x]!=s2[x])+(s1[y]!=s2[y]);
				if(a==1&&b==1) swap(s1[x],s1[y]);
				else if(a==2&&b==2) swap(s2[x],s2[y]);
				else if(a==1&&b==2) swap(s1[x],s2[y]);
				else swap(s2[x],s1[y]);
				int con2 = (s1[x]!=s2[x])+(s1[y]!=s2[y]);
				ans+=con2-con1;
			}else if(op==3) {
				puts(ans==0?"YES":"NO");
			}
		}
	}
	return 0;
}