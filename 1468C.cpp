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
   int q; cin>>q;
   multiset<pi> p,m;
   int c=0,served=0;
   vector<int> ans(q+1);
   rep(i,0,q){
    int ch; cin>>ch;
    if(ch==1){
        int money; cin>>money;
        p.insert({-money,c});
        m.insert({c,money});
        c++;
    }
    elif(ch==2){
        int cus=m.begin()->first;
        int mon=m.begin()->second;
       cout<<cus+1<<" ";
        m.erase(m.begin());
        p.erase(p.find({-mon,cus}));
    }
    else{
        int mon=-p.begin()->first;
        int cus=p.begin()->second;
        cout<<cus+1<<" ";
        p.erase(p.begin());
        m.erase(m.find({cus,mon}));
    }
   }
   return 0;
}