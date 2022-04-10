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
vector<int> v[2];
int n,x;
int dp[300005][2][2][2];
int solve(int i,int t,int j, int st){
   if(i==n){
      return 0;
   }
   if(dp[i][j][t][st]!=-1e18)return dp[i][j][t][st];
   int ans=0;
   int val=max(0ll,v[j][i]);
   if(!st)val=v[j][i];
   ans=val;
   ans=max(ans,val+solve(i+1,t,j,val>0?0:st));
   ans=max(ans,val+solve(i+1,t,0,val>0?0:st));
   if(t and j==0)ans=max(ans,val+solve(i+1,0,1,val>0?0:st));
   return dp[i][j][t][st]=ans;
}
int32_t main(){
      fastIO
       cin>>n>>x;
      rep(i,0,n+1)rep(j,0,2)rep(k,0,2)dp[i][j][k][0]=-1e18,dp[i][j][k][1]=-1e18;
      rep(i,0,n){
         int t; cin>>t;
         v[0].pub(t);
         v[1].pub(x*t);
      }
      cout<<max(solve(0,1,0,1),solve(0,0,1,1))<<"\n";
   return 0;
}