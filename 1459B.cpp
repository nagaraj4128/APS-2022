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
int X[]={1,-1,0,0};
int Y[]={0,0,-1,1};
int mat[5001][5001];
void dfs(int i,int j, int ii,int jj,int k){
   if(k==0){
      mat[i][j]=1;
      return;
   }
   rep(l,0,4){
      int x=i+X[l],y=j+Y[l];
      if(x!=ii and y!=jj){
         if(mat[x][y]==0)dfs(x,y,i,j,k-1);
      }
   }
}
int32_t main(){
   fastIO
      clr(mat,0);
      int k; cin>>k;
         dfs(2500,2500,-1,-1,k);
         int ans=0;
         rep(k,0,5001){
            rep(j,0,5001){
               if(mat[k][j]==1)ans++;
            }
         }
         cout<<ans<<"\n";
   return 0;
}