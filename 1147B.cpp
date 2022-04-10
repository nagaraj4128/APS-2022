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
int calc(int a,int b,int n){
    int o1=llabs(b-a);
    int o2=n-(o1);
    return min(o1,o2);
}
int32_t main(){
   fastIO
   int n,m; cin>>n>>m;
   vector<pi> vp;
   vector<int> mp[n+1];
   rep(i,0,m){
       int a,b; cin>>a>>b;
       mp[a].pub(calc(a,b,n));
       mp[b].pub(calc(a,b,n));
       vp.pub({a,b});
   }
   rep(i,1,n+1){
       sort(all(mp[i]));
   }
   vector<int> f;
   for(int i=1;i*i<=n;i++){
       if(n%i)continue;
       int f1=i,f2=n/i;
       if(f1==f2)f.pub(f1);
       else f.pub(f1),f.pub(f2);
   }
   sort(all(f));
   f.pop_back();
   rep(i,0,f.sz){
       bool ok=1;
       int d=f[i];
       rep(j,1,d+1){
           for(int k=j;k<=n;k+=d){
               if(mp[k]!=mp[j])ok=0;
           }
       }
       if(ok){
           cout<<"Yes\n";
           return 0;
       }
   }
   cout<<"No\n";
   return 0;
}