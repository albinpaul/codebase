#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;

void foo();
void fun();
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	foo();
	return 0;
}
ll search(ll strengths[], ll n,ll currentstrength){
	ll a=0;
	ll begin=0,end=n-1,mid;
	ll index,flag=0;
	while(end-begin!=1){
		mid=(begin+end)>>1;
		
		if (strengths[mid] == currentstrength){
			flag=1;
			break;
		}else if(strengths[mid] >= currentstrength){
			end = mid ;
			
		}else{
			begin = mid;
		}
		
	}
	if(flag==1){
		index = mid;
	}else{
		index = begin;
	
	}
	return index;
}
void fun(){
	ll ar[]={1,3,6,9,12,15,18,21};
	ll siz= (sizeof(ar)/sizeof(ar[0]));
	cout <<search(ar,siz,16);
}
void foo()
{
	
	ll n,q;
	cin >> n>>q;
	ll strengths[n],arrows[q];
	for(ll i =0;i<n;i++){
		cin>>strengths[i];
	}
	for(ll i =0;i<q;i++){
		cin>>arrows[i];
	}
	for (ll i = 1; i < n; i++)
	{
		strengths[i]+=strengths[i-1];
	}
	ll currentstrength=0;


	for(ll i =0;i<q;i++){
		currentstrength=currentstrength+arrows[i];
		//watch(currentstrength);
		if (currentstrength >= strengths[n - 1] )
		{
			currentstrength=0;
			int a = n;
			cout <<a <<endl;
		}else{
			
			
			long long index =search(strengths,n,currentstrength);
			long long a; 
			if (strengths[index] <= currentstrength)
			{
				 a = n - index-1;
			}else{
				a = n - index ;
			}
				

				cout << a << endl;
		}
	}
}
