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
   int n,m; cin>>n>>m;
   vector<int> v,u;
   multiset<pi> boys;
   int ans=0;
   set<int> s;
   rep(i,0,n){
      int t; cin>>t;
      v.pub(t);
      s.insert(t);
      ans+=t*m;
      boys.insert({t,m});
   }
   bool ok=1;
   rep(i,0,m){
      int t; cin>>t;
      if(*prev(s.end())>t)ok=0;
      u.pub(t);
   }
   sort(all(v));
   sort(all(u)); reverse(all(u));
   rep(i,0,m){
      int girl_needs=u[i];
      if(girl_needs==*prev(s.end()))continue;
      auto it=*prev(boys.end());
      boys.erase(prev(boys.end()));
      ans+=(girl_needs-it.fi);
      it.se--;
      if(it.se>1)boys.insert({it.fi,it.se});
   }
   if(!ok)ans=-1;
   cout<<ans<<"\n";
   return 0;
}