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
#define clrg(i, l, r) for(int i=(int)(l);i<(int)(n);i++)vis[i]=0,v[i].clear();
int power(int x, unsigned int y) {int res = 1; while (y > 0) { if (y & 1) {res = res * x;} y = y >> 1; x = x * x;} return res;}
int powermod(int x, unsigned int y, int p) {int res = 1; x = x % p; while (y > 0) {if (y & 1) {res = (res * x) % p;} y = y >> 1; x = (x * x) % p;} return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<endl;
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		multiset<int,greater<>> o,e;
		rep(i,0,n){
			int t; cin>>t;
			if(t%2)o.insert(t);
			else e.insert(t);
		}
		int c=0,es=0,os=0;
		while(o.sz or e.sz){
			if(c%2==0){
				if(e.sz and o.sz){
					if(*e.begin()>*o.begin()){
						es+=*e.begin();
						e.erase(e.begin());
					}
					else{
						o.erase(o.begin());
					}
				}
				elif(e.sz){
					es+=*e.begin();
					e.erase(e.begin());
				}
				else o.erase(o.begin());
			}
			else{
				if(e.sz and o.sz){
					if(*o.begin()>*e.begin()){
						os+=*o.begin();
						o.erase(o.begin());
					}
					else{
						e.erase(e.begin());
					}
				}
				elif(o.sz){
					os+=*o.begin();
					o.erase(o.begin());
				}
				else e.erase(e.begin());
			}
			c++;
		}
		if(os==es)cout<<"Tie\n";
		elif(os>es)cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
}