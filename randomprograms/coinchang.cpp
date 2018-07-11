#include <bits/stdc++.h>
using  namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i,n) for(int i =0;i<n;i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
const double PI=3.141592;
const int inf =(int) 1.01e9;
const double eps =(1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;
void foo(){
	int ar[]={1,2,5,10,20,50,100,200};
	//int ar[]={1,2,3};
	int n=sizeof(ar)/sizeof(ar[0]);
	int C=200;
	long long dp[C+1][n+1];
	
	memset(dp,0,sizeof(long long) *(C+1)*(n+1) );
	for(int i =0;i<=n;i++){
		dp[0][i]=1;
	}
	for(int i =1;i<=C;i++){
		for(int j=1;j<=n;j++){
			if(i-ar[j-1]>=0){
				dp[i][j]=dp[i][j-1]+dp[i-ar[j-1]][j];
			}else{
				dp[i][j]=dp[i][j-1];
			}
		}
	}
		cerr<<"    ";
	for(int i =1;i<=n;i++){
		cerr<<ar[i-1]<<" ";
	}cerr<<endl;
	for(int i =0;i<=C;i++){
		cerr<<i<<" ";
		for(int j=0;j<n;j++){
			cerr<<dp[i][j]<<" ";
		}cerr<<endl;
	}
	cout<<dp[C][n];

}
int fun(){
	
	return 0;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	#ifdef debug
	freopen("input.txt","r",stdin);	
	#endif
	foo();

	return 0;
}
