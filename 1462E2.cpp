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
const int N=2e5+5;
vector<int> fact(N+1),inv(N+1);
void pre(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i%mod);
    }
    inv[0]=1;
    for(int i=1;i<N;i++){
        inv[i]=powermod(fact[i],mod-2,mod);
    }
}
int ncr(int n,int r,int m){
    if(n==r or r==0)return 1;
    if(r>n or r<0)return 0;
    return ((fact[n]*inv[r]%m)*inv[n-r]%m);
}
int32_t main(){
   fastIO
   pre();
   int T; cin>>T;
   while(T--){
     //GO BACK AND UNDERSTAND THE PROBLEM!!
      int n,m,k; cin>>n>>m>>k;
      vector<int> v;
      map<int,int>mp,mp2;
      set<int> sett;
      rep(i,0,n){
          int t; cin>>t;
          mp[t]++;
          sett.insert(t);
          v.pub(t);
      }
      int prev=0,s=0,ans=0;
      rr(sett){
        rep(i,prev,val+k+1){
            s+=mp[i];
        }
        s-=mp[val];
       rep(j,1,m+1){
           ans+=(ncr(mp[val],j,mod)*ncr(s,m-j,mod)%mod); ans%=mod;
       }
        prev=val+k+1;
      }
      cout<<ans<<"\n";
   }
   return 0;
}