#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define pi pair<int,int>
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for(int i=(int)(l);i<(int)(r);i++)
#define repd(i, l, r) for (int i=(int)(l);i>=(int)(r);i--)
#define clrg(i, l, r) for(int i=(int)(l);i<(int)(n);i++)vis[i]=0,v[i].clear();
int power(int x, unsigned int y) {int res = 1; while (y > 0) { if (y & 1) {res = res * x;} y = y >> 1; x = x * x;} return res;}
int powermod(int x, unsigned int y, int p) {int res = 1; x = x % p; while (y > 0) {if (y & 1) {res = (res * x) % p;} y = y >> 1; x = (x * x) % p;} return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<endl;
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
vector<int> v[200005],u[2],vis(200005);
void dfs(int node,int par,int odd){
	vis[node]=1;
	u[odd].pub(node);
	rr(v[node]){
		if(!vis[val]){
			dfs(val,node,(odd^1));
		}
	}
}
int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		rep(i,0,n+1)v[i].clear(),vis[i]=0;
		u[0].clear();
		u[1].clear();
		rep(i,0,m){
			int a,b; cin>>a>>b;
			v[a].pub(b);
			v[b].pub(a);
		}
		dfs(1,-1,0);
		if(u[0].sz<u[1].sz){
			cout<<u[0].sz<<"\n";
			print(u[0]);
		}
		else{
			cout<<u[1].sz<<"\n";
			print(u[1]);
		}
	}
	return 0;
}