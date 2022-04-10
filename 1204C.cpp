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
     //GO BACK AND UNDERSTAND THE PROBLEM!!
      int n; cin>>n;
      string s[n+1];
      rep(i,0,n)cin>>s[i];
      int d[n+1][n+1];
      rep(i,0,n)rep(j,0,n)d[i][j]=(s[i][j]=='1'?1:1e18);
      rep(i,0,n)d[i][i]=0;
      for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
              }
          }
      }
      int m; cin>>m;
      vector<int> p;
      rep(i,0,m){
        int t; cin>>t;
        p.pub(t);
      }
      vector<int> ans;
      ans.pub(p[0]);
      int prev=0;
      rep(i,1,p.sz){
        if(d[ans.back()-1][p[i]-1]<(i-prev))ans.pub(p[i-1]),prev=i-1;
      }
      ans.pub(p.back());
      cout<<ans.sz<<"\n";
      print(ans);
   return 0;
}