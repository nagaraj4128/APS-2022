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
int binsearch(int a,int b,int n,int c){
   int l=a+b,r=a+2*b,ok=((1ll<<(c+1))>n);
   while(l<r){
      int mid=(l+r)/2;
      if(mid+(ok?0:(mid-a))>=n)r=mid;
      else l=mid+1;
   }
   return l;
}
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
      int n; cin>>n;
      if(n==4){
         cout<<2<<"\n"<<0<<" "<<0<<"\n";
         continue;
      }
      int a=1,b=1,c=0;
      vector<int> ans;
      while(a!=n){
         int wh=binsearch(a,b,n,++c);
         ans.pub(wh-a-b);
         b=wh-a;
         a=wh;
         //cout<<a<<" "<<b<<"\n";
         //if(ans.sz==10)break;
      }
      cout<<ans.sz<<"\n";
      print(ans);
   }
   return 0;
}