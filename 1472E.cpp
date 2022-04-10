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
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<"\n";
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
	 //GO BACK AND UNDERSTAND THE PROBLEM!!
	 int n; cin>>n;
	vector<pair<pi,int>> vp;
	rep(i,0,n){
		int a,b; cin>>a>>b;
		vp.pub({{min(a,b),max(a,b)},i});
	}
	sort(all(vp));
	  vector<int> ans(n,-1);
	  set<int> s,temp;
	  map<int,int> idx,tm;
	  rep(i,0,vp.sz){
		int ts=vp[i].fi.se;
		if(s.empty() or *s.begin()>=ts)int nothing;
		else ans[vp[i].se]=idx[*s.begin()]+1;
		temp.insert(ts);
		tm[ts]=vp[i].se;
		if(i<n-1 and vp[i].fi.fi!=vp[i+1].fi.fi){
			rr(temp)s.insert(val);
			rr(tm)idx[val.fi]=val.se;
			temp.clear(); tm.clear();
		}
	  }
	  print(ans);
   }
   return 0;
}