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
   int n; cin>>n;
   string s; cin>>s;
   string t; cin>>t;
   vector<int> a(n),b(n);
   rep(i,0,n){
      a[i]=s[i]-'a';
      b[i]=t[i]-'a';
   } 
   //Generated 26 base numbers now add and divide by two
   int sum=0;
   repd(i,n-1,0){
       sum=a[i]+b[i];
      a[i]=sum%26;
      if(i){
         a[i-1]+=sum/26;
      }
      else sum=sum/26;
   }
   a[0]+=(sum%2)*26;
   rep(i,0,n){
      int rem=a[i]%2;
      a[i]/=2;
      if(i+1<n){
         a[i+1]+=rem*26;
      }
   }
   rep(i,0,n){
      cout<<char('a'+a[i]);
   }
   cout<<"\n";
   return 0;
}