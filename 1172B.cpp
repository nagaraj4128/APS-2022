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
#define mod 998244353
#define elif else if
vector<int> v[200005],subt(200005),dp(200005,1),f(200005);
void dfs(int node,int par){
   rr(v[node]){
      if(val!=par){
         dfs(val,node);
         subt[node]+=subt[val];
      }
   }
   subt[node]++;
}
void dfs1(int node,int par){
   int c=0;
   rr(v[node]){
      if(val!=par){
         dfs1(val,node);
         dp[node]*=dp[val];
         dp[node]%=mod;
         c++;
      }
   }
   if(node>1)dp[node]*=(f[c]*(c+1))%mod;
   else dp[node]*=f[c];
   dp[node]%=mod;
}
int32_t main(){
   fastIO
   int n; cin>>n;
   rep(i,0,n-1){
      int a,b; cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
   }
   f[0]=1;
   rep(i,1,n+1){
      f[i]=(f[i-1]*i)%mod;
   }
   dfs(1,-1);
   dfs1(1,-1);
   //rep(i,1,n+1)cout<<dp[i]<<" ";
   cout<<(dp[1]*n)%mod<<"\n";
   return 0;
}