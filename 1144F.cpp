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
void dfs(int node,int col,vector<vector<int>>& adj,vector<int>& vis,bool &ok){
    vis[node]=col+1;
    for(auto& child: adj[node]){
        if(vis[child]){
            if(vis[child]==vis[node])ok=0;
        }
        else dfs(child,col^1,adj,vis,ok);
    }
}
int32_t main(){
    fastIO
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1);
    vector<pi> edges;
    rep(i,0,m){
        int a,b; cin>>a>>b;
        adj[a].pub(b);
        adj[b].pub(a);
        edges.pub({a,b});
    }
    bool ok=1;
    dfs(1,0,adj,vis,ok);
    string ans="";
    for(auto& [u,v]:edges){
        if(vis[u]<vis[v])ans+='0';
        elif(vis[u]>vis[v]) ans+='1';
       // else ok=0;
    }
    if(!ok){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<ans<<"\n";
   return 0;
}