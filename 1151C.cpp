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
int pref(int l,int r,int p){
   l%=mod,r%=mod;
   if(p){
      int ans=(r*r)%mod-(l*l)%mod;
      if(ans<0)ans+=mod;
      return ans;
   }
   else{
      int ans=(r*(r+1)%mod)-(l*(l+1)%mod);
      if(ans<0)ans+=mod;
      return ans;
   }
}
int calc(int l){
   int ne=0,no=0,po=1,p=1,ans=0;
   while(ne+no+po<=l){
      if(p){
         if(no+po>l)break;
      }
      else{
         if(ne+po>l)break;
      }
      if(p)no+=po;
      else ne+=po;
      if(!p)ans+=pref(ne-po,ne,p);
      else ans+=pref(no-po,no,p);
      ans%=mod;
      p^=1;
      po*=2;
   }
   po/=2;
   if(p)ans+=pref(no,max(l-ne,no),p);
   else ans+=pref(ne,max(l-no,ne),p);
   ans%=mod;
   return ans;
}
int32_t main(){
   fastIO
   int l,r; cin>>l>>r;
   int ans=calc(r)-calc(l-1);
   if(ans<0)ans+=mod;
   cout<<ans<<"\n";
   return 0;
}