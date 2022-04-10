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
int d[2][200005],vis[200005];
vector<int> v[200005];
void bfs(int src,int i){
   queue<int> q;
   q.push(src);
   d[i][src]=0;
   clr(vis,0);
   vis[src]=1;
   while(!q.empty()){
      int node=q.front(); q.pop();
      rr(v[node]){
         if(!vis[val]){
            d[i][val]=d[i][node]+1;
            vis[val]=1;
            q.push(val);
         }
      }
   }
}
int32_t main(){
   fastIO
   int n,m,k; cin>>n>>m>>k;
   vector<int> sp;
   rep(i,0,k){
      int t; cin>>t;
      sp.pub(t);
   }
   rep(i,0,m){
      int a,b; cin>>a>>b;
      v[a].pub(b);
      v[b].pub(a);
   }
   bfs(1,0);
   bfs(n,1);
   vector<pi> vp;
   rep(i,0,k){
      vp.pub({d[0][sp[i]],d[1][sp[i]]});
   }
   sort(all(vp));
   int ans=0;
   rep(i,0,vp.sz-1){
      ans=max(ans,vp[i].fi+min(vp[i].se,vp[i+1].se+1));
   }
   ans=min(ans,d[0][n]);
   cout<<ans<<"\n";
   return 0;
}