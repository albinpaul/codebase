#include<bits/stdc++.h>
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
	const int n = 1000001;
	//const int n=1001;
	bool ar[n+1];
	memset(ar,0,sizeof(bool) *( n+1));
	for(int  i=4;i<n; i+=2){
		ar[i]=1;
	}
	for (int i = 3; i <= sqrt(n); ++i)
	{	
		if(ar[i]==0){
			for(int j= 2 * i ;j<=n; j+=i){
				ar[j]=1;
			}
		}
	}
	//prime number sieve is done
	int count=0;
	for(int i =2;i<n;i++){
		if(ar[i]==0){
			int s=0;
			int t=i;

			while(t){
				s+=1;	
				t/=10;
			}
			t=i;
			int q=i;
			int flag=0;
			while(t){
				int p=q%10;
				q=pow(10,s-1)*p+q/10;	
				if(ar[q]==1){
					flag=1;
				}
				t/=10;
			}
			if(flag==0){
				cerr<<i<<endl;
				count+=1;
			}
		}
	}
	cout<<count<<endl;
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
