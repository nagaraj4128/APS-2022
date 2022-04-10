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
#define clrg(i, l, r) for(int i=(int)(l);i<(int)(r);i++)vis[i]=0,v[i].clear();
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
vector<int> v[100005],vis(100005);
bool ok;
void dfs(int node){
	vis[node]=1;
	rr(v[node]){
		if(vis[val]==0)dfs(val);
		elif(vis[val]==1)ok=1;
	}
	vis[node]=2;
}
int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		clrg(i,0,n+1);
		int c=0;
		rep(i,0,m){
			int a,b; cin>>a>>b;
			if(a==b){
				continue;
			}
			if(v[a].empty())v[a].pub(b);
			else v[b].pub(a);
			c++;
		}
		rep(i,1,n+1){
			ok=0;
			if(!vis[i])dfs(i);
			if(ok)c++;
		}
		cout<<c<<"\n";
		
	}
	return 0;
}