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
vector<int> v[1001];
int32_t main(){
   int n; cin>>n;
   rep(i,0,n-1){
      int a,b; cin>>a>>b;
      v[a].pub(b);
      v[b].pub(a);
   }
   vector<int> leafs;
   vector<int> del(n+1),del2(n+1);
   rep(i,1,n+1){
      sort(all(v[i]));
      rr(v[i]){
         if(v[val].sz==1){
            leafs.pub(val);
            del[i]=val;
            break;
         }
      }
   }
   if(leafs.sz==1){
      rep(i,1,n+1){
         if(leafs[0]!=i and v[i].sz==1){
            leafs.pub(i);
            del2[v[i][0]]=i;
            break;
         }
      }
   }
   assert(leafs.sz-1<=n/2);
   int w;
   cout<<"? "<<leafs[0]<<" "<<leafs[1]<<endl;
   fflush(stdout);
   cin>>w;
   rep(i,2,leafs.sz){
      cout<<"? "<<w<<" "<<leafs[i]<<endl;
      fflush(stdout);
      cin>>w;
   }
   vector<int> vv;
   rep(i,0,v[w].sz){
      if(v[v[w][i]].sz==1 and v[w][i]!=del[w] and v[w][i]!=del2[w])vv.pub(v[w][i]);
   }
   if(vv.sz%2==1)vv.pub(w);
   if(vv.sz>=2)rep(i,0,vv.sz-1){
      int temp;
      cout<<"? "<<vv[i]<<" "<<vv[i+1]<<endl;
      fflush(stdout);
      cin>>temp;
      if(temp!=w){
         w=temp;
         break;
      }
      i++;
   }
   cout<<"! "<<w<<endl;
   return 0;
}