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
      vector<int> v(4);
      cin>>v[0]>>v[1]>>v[2]>>v[3];
      bool ok=1;
      vector<int> ans,ans2;
      int ts=v[3];
      if(ts==0) goto here;
      if(v[2]<ts-1)ok=0;
      v[3]=0; 
      rep(i,0,ts-1)ans.pub(3),ans.pub(2);
      if(ts)ans.pub(3);
      v[2]-=max(0ll,ts-1);
      if(v[1] or v[0]){
         ans.pub(2);
         v[2]--;
         if(v[2]<0)ok=0;
      }
      here:
      if(v[0]>v[1])ok=0;
      ts=v[0];
      v[1]-=v[0];
      v[0]=0;
      rep(i,0,ts)ans.pub(1),ans.pub(0);
      if(v[2]>v[1]){
         int mn=v[1];
         v[2]-=mn;
         v[1]=0;
         rep(i,0,mn)ans2.pub(2),ans2.pub(1);
         ans2.pub(2);
         v[2]--;
      }
      else{
         int mn=v[2];
         v[1]-=mn;
         v[2]=0;
         rep(i,0,mn)ans2.pub(2),ans2.pub(1);
         if(v[1])ans.pub(1),v[1]--;
      }
      //print(v);
      rep(i,0,4)if(v[i])ok=0;
      reverse(all(ans2));
      if(ok){
         cout<<"YES\n";
         rep(i,0,ans2.sz)cout<<ans2[i]<<" ";
         print(ans);
      }
      else cout<<"NO\n";
   return 0;
}