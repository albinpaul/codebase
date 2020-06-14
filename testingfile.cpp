
 //~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#ifdef DEBUG
#include "debug.hpp"
#endif
#define range(i,n) for(int i=0;i<n; ++i)
#define all(i) i.begin(),i.end()
#define watch(x) cerr << #x << " is " << x << " " ;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
template <typename T> void uniq(vector <T> &v) {v.resize(unique(all(v))-v.begin());}


const long int N = 5.1e5;
const long long MOD = 1000 * 1000 * 1000 ;
long long a[N];
long long n;

void solve(int testcase){
	cin >> n;
	assert(n < N);
	range(i,n) {
		cin >> a[i];
	}
	sort(a,a+n);	
	long long answer = 0;
	long long answercount = 0;
	long long minv = -1,secondminv = -1;
	long long possum = 0,poscount = 0;
	long long abssum = 0LL;
	range(i,n) {
		abssum += abs(a[i]);
		if (a[i] < 0) {
			answer -= a[i];
			answercount ++;
		}
		else {
			if (minv == -1) 
			{
				minv = a[i];
				continue;
			}
			if (secondminv == -1) 
			{
				secondminv = a[i];
				continue;
			}
			possum += a[i];
			poscount ++;
		}
	}
	if(minv == -1 && answercount > 1){
		cout << answer - 1 << '\n';
		return;
	}
	if(minv == -1 && answercount == 1){
		cout <<  -answer << '\n';
		return;
	}
	if (answercount	 > 0)
	{	
		
		cout << abssum << '\n';
	}
	else {
		if (secondminv == -1)
		{
			cout << (possum + minv) << '\n';
			return ;
		}
		long long answer1 = secondminv - (minv - possum);
		cout <<  answer1 << '\n';
	}
}





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve(0);
	return 0;
	int t;
	cin >> t;
	for(int tt = 1 ;tt <= t;tt++ ) {
		solve(tt);
	}

	return 0;
}
