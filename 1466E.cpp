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
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		vector<int> v,bits(64);
		rep(i,0,n){
			int t; cin>>t;
			v.pub(t);
			rep(j,0,64){
				if((1ll<<j)&t)bits[j]++;
			}
		}
		int ans=0;
		rep(i,0,n){
			int ans1=0,ans2=0;
			vector<int> b;
			b.assign(all(bits));
			rep(j,0,64){
				if((1ll<<j)&v[i])b[j]--;
			}
			rep(j,0,64){
				if((1ll<<j)&v[i]){
					ans1+=((b[j]+1)*((1ll<<j)%mod))%mod;
					ans1%=mod;
				}
				else ans2+=(b[j]*((1ll<<j)%mod))%mod;
				ans2%=mod;
			}
			ans2+=((v[i]%mod)*n)%mod;
			ans+=(ans1*ans2)%mod;
			ans%=mod;
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}