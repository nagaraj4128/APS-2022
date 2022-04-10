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
const int MAX = 1e6+5;
vector<int> lp, primes;
void factor_sieve()
{
	lp.resize(MAX);
	lp[1] = 1;
	for (int i = 2; i < MAX; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			primes.emplace_back(i);
		}
		for (int j = 0; j < primes.size() && primes[j] <= lp[i]; ++j)
		{
			int x = i * primes[j];
			if (x >= MAX)
				break;
			lp[x] = primes[j];
		}
	}
}
int32_t main(){
   fastIO
   factor_sieve();
   int T; cin>>T;
   while(T--){
	 //GO BACK AND UNDERSTAND THE PROBLEM!!
	  int n; cin>>n;
	  vector<int> v;
	  map<int,int> mp;
	  rep(I,0,n){
		  int t; cin>>t;
		  int wh=1;
		  while(t!=1){
			  int sp=lp[t];
			  int po=0;
			  while(t%sp==0){
				t/=sp;
				po++;
			  }
			if(po&1)wh*=sp;
		  }
		  mp[wh]++;
	  }
	  int ans0=0,ans1=0;
	  rr(mp){
		ans0=max(ans0,val.se);
	  }
	  rr(mp){
		  if(val.fi==1)continue;
		  if(val.se%2==0){
			  mp[1]+=val.se;
			  val.se=0;
		  }
	  }
	  rr(mp)ans1=max(ans1,val.se);
	  int q; cin>>q;
	  while(q--){
		  int w; cin>>w;
		  if(w==0)cout<<ans0<<"\n";
		  else cout<<ans1<<"\n";
	  }
   }
   return 0;
}