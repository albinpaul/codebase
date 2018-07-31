#include <bits/stdc++.h>
#include <unordered_map>
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
	int summ=0;
	int fact=1;
	int ar[10];
	ar[0]=1;
	for(int i =1;i<=9;i++){
		
		fact*=i;
		ar[i]=fact;
		summ+=fact;

	}	
	
	int ss=0;
	for(int i =3;i<summ;i++){
		int t=i;
		int s=0;
		while(t){
			int p=t%10;
			s+=ar[p];
			t/=10;
		}
		if(s==i){
			cerr << s<<" "<<i<<endl;
			ss+=i;
		}
	}
	cout<<ss<<endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	foo();

	return 0;
}