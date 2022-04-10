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
      //the 1...1 and 0...0 strings do not contribute anything
      // only 0..1 and 1..0 are "connectors" and can connect two 
      //different characters. these must exist and be balanced.
      //if they dont exist, everything must be balanced beforehand.
      int n; cin>>n;
      vector<string> v;
      set<int> s[2];
      map<string,int> mp;
      int oc=0,zc=0;
      rep(i,0,n){
         string st; cin>>st;
         mp[st]=i+1;
         v.pub(st);
         if(st[0]=='1' and st.back()=='0')s[1].insert(i);
         if(st[0]=='0' and st.back()=='1')s[0].insert(i);
          zc+=st[0]=='0';
          oc+=st.back()=='1';
          oc+=st[0]=='1';
          zc+=st.back()=='0';
      }
      if(zc and oc and !s[0].sz and !s[1].sz){
         cout<<-1<<"\n";
         continue;
      }
      vector<int> ans;
      while(s[0].sz>s[1].sz+1){
         int i=*s[0].begin();
         string temp=v[i];
         reverse(all(temp));
         if(mp[temp]){
            s[0].erase(i);
            s[1].erase(mp[temp]-1);
         }
         else{
            ans.pub(i+1);
            s[0].erase(i);
            s[1].insert(i);
         }
      }
      while(s[1].sz>s[0].sz+1){
         int i=*s[1].begin();
         string temp=v[i];
         reverse(all(temp));
         if(mp[temp]){
            s[1].erase(i);
            s[0].erase(mp[temp]-1);
         }
         else{
            ans.pub(i+1);
            s[1].erase(i);
            s[0].insert(i);
         }
      }
      cout<<ans.sz<<"\n";
      print(ans);
   }
   return 0;
}