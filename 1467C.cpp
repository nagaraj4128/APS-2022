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
int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
		int n1,n2,n3; cin>>n1>>n2>>n3;
		vector<int> v1[3];
		vector<int> v(3);
		rep(i,0,n1){
			int t; cin>>t;
			v1[0].pub(t);
			v[0]+=t;
		}
		rep(i,0,n2){
			int t; cin>>t;
			v1[1].pub(t);
			v[1]+=t;
		}
		rep(i,0,n3){
			int t; cin>>t;
			v1[2].pub(t);
			v[2]+=t;
		}
		int ans=0;
		rep(i,0,3){
			int sum=0,mnn=1e18;
			rep(j,0,3){
				if(j==i)continue;
				rr(v1[j])mnn=min(mnn,val),sum+=val;
			}
			int s0=0;
			sum-=mnn;
			rep(j,0,v1[i].sz)s0+=v1[i][j];
			s0-=*min_element(all(v1[i]));
			int wh=(sum-*min_element(all(v1[i])))+llabs(s0-mnn);
			ans=max(ans,wh);
		}
		cout<<ans<<"\n";

	return 0;
}