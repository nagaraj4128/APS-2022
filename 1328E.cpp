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
vector<int> v[200005],parent(200005),in(200005),out(200005);
int t=0;
void dfs(int node,int par){
    in[node]=++t;
    rr(v[node]){
        if(val!=par){
            parent[val]=node;
            dfs(val,node);
        }
    }
    out[node]=t;
}
int32_t main(){
   fastIO
   int n,q; cin>>n>>q;
   rep(i,0,n-1){
       int a,b; cin>>a>>b;
       v[a].pub(b);
       v[b].pub(a);
   }
   dfs(1,-1);
   parent[1]=1;
   while(q--){
       int siz; cin>>siz;
       vector<int> inp;
       vector<pi> vp;
       rep(i,0,siz){
           int t; cin>>t;
           vp.pub({in[parent[t]],out[parent[t]]});
       }
       sort(all(vp));   
        repd(i,vp.sz-1,0)inp.pub(vp[i].se);
        if(is_sorted(all(inp)))cout<<"Yes\n";
        else cout<<"No\n";
   }
   return 0;
}