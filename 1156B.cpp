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
   int T; cin>>T;
   while(T--){
      string s; cin>>s;
      map<char,int> mp;
      rep(i,0,s.ln)mp[s[i]]++;
      vector<char> v;
      rr(mp){
         v.pub(val.fi);
      }
      bool ok1=1,ok2=1;
      int m=(v.sz-1)/2;
      vector<char> ord1,ord2;
      ord1.pub(v[m]);
      ord2.pub(v[m]);
      //print(v);
         int l=0,r=v.sz-1;
         while(l<m and r>m){
            ord1.pub(v[l]);
            ord1.pub(v[r]);
            ord2.pub(v[r--]);
            ord2.pub(v[l++]);
         }
         if(l<m)ord1.pub(v[l]),ord2.pub(v[l]);
         if(r>m)ord1.pub(v[r]),ord2.pub(v[r]);
         rep(i,1,ord1.sz){
            if(ord1[i]==(ord1[i-1]+1) or ord1[i]==(ord1[i-1]-1))ok1=0;
            if(ord2[i]==(ord2[i-1]+1) or ord2[i]==(ord2[i-1]-1))ok2=0;
         }
         if(!ok1 and !ok2){
            cout<<"No answer\n";
            continue;
         }
         if(ok1)rr(ord1){
            rep(i,0,mp[val])cout<<val;
         }
         else rr(ord2){
            rep(i,0,mp[val])cout<<val;
         }
         cout<<"\n";
   }
   return 0;
}