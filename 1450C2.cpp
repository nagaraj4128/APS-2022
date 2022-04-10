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
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		char arr[n+1][n+1];
		int k=0;
		map<int,int> mpx,mpo;
		rep(i,0,n){
			rep(j,0,n){
				cin>>arr[i][j];
				if(arr[i][j]=='X')mpx[(i+j)%3]++,k++;
				if(arr[i][j]=='O')mpo[(i+j)%3]++,k++;
			}
		}
		char ch='X',ch0='O',mo=-1,mx=-1;
        rep(i,0,3){
            rep(j,0,3){
                if(i==j)continue;
                if(mpo[i]+mpx[j]<=(k/3)){
                    mo=j,ch0='O';
                    mx=i,ch='X';
                    break;
                }
                if(mpx[i]+mpo[j]<=(k/3)){
                    mo=j,ch0='X';
                    mx=i,ch='O';
                    break;
                }
            }
        }
		rep(i,0,n){
			rep(j,0,n){
				if(arr[i][j]=='.'){
					cout<<arr[i][j];
				}
				elif((i+j)%3==mo){
					cout<<ch0;
				}
                elif((i+j)%3==mx){
                    cout<<ch;
                }
				else{
					cout<<arr[i][j];
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}