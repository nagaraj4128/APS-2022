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
 vector<int> v1,v2;
 int n; 
 bool check1(int x){
    bool ok=1,ok2=0;
    rep(i,0,x){
        if(v2[i]>v1[n-x+i])ok=0;
        ok2=1;
    }
    return (ok and ok2);
 }
 bool check2(int x){
     bool ok=1,ok2=0;
     rep(i,x,n){
         if(v2[i]<v1[i-x])ok=0;
         ok2=1;
     }
     return (ok and ok2);
 }
int32_t main(){
   fastIO
   int T; cin>>T;
   while(T--){
     //GO BACK AND UNDERSTAND THE PROBLEM!!
      cin>>n;
      v1.clear();
      v2.clear();
      set<int> s;
      rep(i,0,2*n)s.insert(i+1);
      rep(i,0,n){
        int t; cin>>t;
        v1.pub(t);
        s.erase(t);
      }
      rr(s)v2.pub(val);
      int mn=0,mx=0,l=0,r=n;
      while(l<r){
          int mid=(l+r)/2;
          if(check2(mid))r=mid;
          else l=mid+1;
      }
      mn=l;
      l=0,r=n;
      while(l<r){
          int mid=(l+r+1)/2;
          if(check1(mid))l=mid;
          else r=mid-1;
      }
      mx=l;
      cout<<mx-mn+1<<"\n";
   }
   return 0;
}