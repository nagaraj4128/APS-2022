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
int calc(int a,int b,int g){
   int wh=(b+g-1)/g;
   int k=wh*g-b;
   return ((a+k)*(b+k)/g);
}
int32_t main(){
   fastIO
   int a,b; cin>>a>>b;
   if(a<b)swap(a,b);
   if(a==b){
      cout<<0<<"\n";
      return 0;
   }
   int g=llabs(a-b),ans=2e18,fans=0;
   for(int i=1;i*i<=g;i++){
      if(g%i)continue;
      int f1=i,f2=g/i;
      int o1=calc(a,b,f1);
      if(o1<ans){
         ans=o1;
         fans=f1;
      }
      int o2=calc(a,b,f2);
      if(o2<ans){
         ans=o2;
         fans=f2;
      }
   }
   int wh=(b+fans-1)/fans;
   int k=wh*fans-b;
   cout<<k<<"\n";
   return 0;
}