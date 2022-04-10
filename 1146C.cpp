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
#define print(v) for (const auto itr : v){cout<<itr<<' ';}
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
void pri(int n,int p,vector<int>& v){
    int j=0;
    vector<int> v1,v2;
    while(j<n){
        rep(i,0,(1ll<<p)){
            v1.pub(v[j++]);
            if(j>=n)break;
        }
        if(j>=n)break;
        rep(i,0,(1ll<<p)){
            v2.pub(v[j++]);
            if(j>=n)break;
        }
        if(j>=n)break;
    }
    cout<<v1.sz<<" "<<v2.sz<<" "; print(v1); print(v2);
    cout<<endl;
    fflush(stdout);
}
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
      int n; cin>>n;
      vector<int> v,u;
      rep(i,0,n)v.pub(i+1);
      int ans=0;
      rep(i,0,9){
        if((1ll<<i)>=n)break;
        pri(n,i,v);
        int t; cin>>t;
        ans=max(ans,t);
      }
      cout<<-1<<" "<<ans<<endl;
   }
   return 0;
}