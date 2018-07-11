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
	const int n=100000;
	int ar[n+1];
	memset(ar,0,sizeof(int) *(n+1));
	for(int i =0;i<=n;i++){
		int t=i;
		while(t){
			int p=t%10;
			ar[i]|=(1<<p);
			t=t/10;
		}
	}
	// for(int i =0;i<=n;i++){
	// 	cerr<<i<<" "<<bitset<10>(ar[i])<<endl;
	// }
	int s=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sqrt(i);j++){
			if(i%j==0){

				if( (ar[i/j] | ar[j] | ar[i]) == ((1<<10)-1-1)  ){
					int flag=0;
					for(int k=1;k<=9;k++){
						if(((ar[i] &(1<<k))+(ar[i/j] &(1<<k))+(ar[j] & (1<<k))) / (1<<k)!= 1){
							flag=1;
						}
						int t=i;
						int temp=0;
						while(t){
							int p=t%10;
							if (p==0){
								flag=1;
							}
							if((temp&(1<<p)) >0){
								flag=1;
								break;
							}
							temp|=(1<<p);
							t/=10;
						}
						t=i/j;
						temp=0;
						while(t){
							int p=t%10;
							if (p==0){
								flag=1;
							}
							if((temp&(1<<p)) >0){
								flag=1;
								break;
							}
							temp|=(1<<p);
							t/=10;
						}
						t=j;
						temp=0;
						while(t){
							int p=t%10;
							if (p==0){
								flag=1;
							}
							if((temp&(1<<p)) >0){
								flag=1;
								break;
							}
							temp|=(1<<p);
							t/=10;
						}
					}

					if(flag==0){
					cerr<<j<<" "<<i/j<<" "<<  i<< endl;
					
					s+=i;
				}
				}
			}
		}
	}
	cout<<s<<endl;
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