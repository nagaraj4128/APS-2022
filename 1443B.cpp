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
     //GO BACK AND UNDERSTAND THE PROBLEM!!
      int n; 
      int a,b; cin>>a>>b;
      string s; cin>>s;
      n=s.ln;
      s+='0';
      int cur=1,ans=0;
      vector<int> v;
      rep(i,1,n+1){
        if(s[i]!=s[i-1]){
            if(s[i-1]=='1'){
                ans++;
            }
            else{
                if(ans>0)v.pub(cur);
            }
            cur=1;
        }
        else cur++;
      }
      int fans=ans*a;
      sort(all(v));
      rep(i,0,v.sz){
          if(b*v[i]>a)break;
          fans-=a;
          fans+=b*v[i];
      }
      cout<<fans<<"\n";
   }
   return 0;
}