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
      int n,k; cin>>n>>k;
      vector<int> v(k,1),ans(k);
      int c=k*(k+1)/2;
      int prev=0;
      rep(i,0,k){
         int l=prev+1,r=2*prev;
         if(i==0)r=n;
         while(l<r){
            int mid=(l+r+1)/2;
            if(c+(k-i)*(mid-prev-1)<=n)l=mid;
            else r=mid-1;
         }
         c+=((l-prev-1)*(k-i));
         prev=l;
         ans[i]=l;
      }
      bool ok=1;
      int sum=0;
      rep(i,0,k)sum+=ans[i];
      if(sum!=n){
         cout<<"No\n";
         return 0;
      }
      cout<<"Yes\n";
      print(ans);
   return 0;
}