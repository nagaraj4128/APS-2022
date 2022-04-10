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
   int vis[n][m]; clr(vis,0);
   vector<pi> vp;
   vector<pi> v[n+m+1];
   rep(i,0,n){
       rep(j,0,m){
            if(vis[i][j])continue;
            int r=i,c=j;
            while(r<n and c>=0){
                v[i+j].pub({r,c});
                vis[r][c]=1;
                r++,c--;
            }
       }
   }
   rep(i,0,(n+m)){
       reverse(all(v[i]));
   }
   vector<pi> v1,v2;
   int c=0;
   rep(i,0,n+m){
        rr(v[i]){
            if(c<(n*m)/2)v1.pub({val});
            else v2.pub({val});
            c++;
        }
   }
   reverse(all(v2));
   int l=0,r=0;
   while(l<v1.sz and r<v2.sz){
       vp.pub(v1[l++]);
       vp.pub(v2[r++]);
   }
   if(r<v2.sz)vp.pub({v2[r++]});
   if(l<v1.sz)vp.pub({v1[l++]});
   rr(vp)cout<<val.fi+1<<" "<<val.se+1<<"\n";
   return 0;
}