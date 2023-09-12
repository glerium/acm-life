#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int ttt,n,a[maxn];
struct Treap{
	const static int maxn=1e5+10;
	int idx,w[maxn],val[maxn],son[maxn][2],sz[maxn],ct[maxn];
	int root=0;
	void update(int x){
		sz[x]=sz[son[x][0]]+sz[son[x][1]]+ct[x];
	}
	void rotate(int &x,int k){
		int y=son[x][k^1];
		son[x][k^1]=son[y][k];
		son[y][k]=x;
		update(x);
		update(y);
		x=y;
	}
	void insert(int &x,int k){
		if(!x){
			x=++idx;
			sz[x]=ct[x]=1;
			val[x]=k;
			w[x]=rand();
		}else if(val[x]==k){
			ct[x]++;
			sz[x]++;
		}else{
			int t=k>val[x];
			insert(son[x][t],k);
			if(w[x]<w[son[x][t]]) rotate(x,t^1);
			update(x);
		}
	}
	void del(int &x,int k){
		if(!x) return;
		if(k<val[x]) del(son[x][0],k);
		else if(k>val[x]) del(son[x][1],k);
		else{	//k==val[x]
			if(!son[x][0]&&!son[x][1]){
				ct[x]--; sz[x]--;
				if(!sz[x]) x=0;
			}else if(son[x][0]&&!son[x][1]){
				rotate(x,1);
				del(son[x][1],k);
			}else if(!son[x][0]&&son[x][1]){
				rotate(x,0);
				del(son[x][0],k);
			}else{
				int t=son[x][0]>son[x][1];
				rotate(x,t);
				del(son[x][t],k);
			}
		}
		update(x);
	}
	int rank(int x,int k){
		if(!x) return 0;
		if(k<val[x]) return rank(son[x][0],k);
		else if(k>val[x]) return sz[son[x][0]]+ct[x]+rank(son[x][1],k);
		else return sz[son[x][0]]+1;
	}
	int xrank(int x,int k){
		if(!x) return 0;
		if(k<=sz[son[x][0]]) return xrank(son[x][0],k);
		else if(k>sz[son[x][0]]+ct[x]) return xrank(son[x][1],k-ct[x]-sz[son[x][0]]);
		else return val[x];
	}
}t;
int main() {
    ios::sync_with_stdio(false);
    cin>>ttt;
    while(ttt--) {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) {
            vector<int> cur;
            for(int j=i;j<=n;j++) {
                int id = j-i+1;
                cout<<":"<<i<<' '<<j<<' '<<t.rank(t.root,a[i])+1<<endl;
                if(id!=t.rank(t.root,a[i])+1) ans++,cout<<"yes"<<endl;
                t.insert(t.root,a[i]);
                cur.push_back(a[i]);
            }
            for(auto i:cur) t.del(t.root,i);
        }
        cout<<ans<<endl;
    }
}