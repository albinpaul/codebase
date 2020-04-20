
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
const long int N = 1.1e5;
vector <pair <ll ,ll>> a;

void solve(int testcase){
	ll n,d;
	cin >> n >> d;
	a.resize(n);
	for(int i=0;i<n;i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));
	int left = 0,right = 0;
	ll runningsum = 0,answer = 0;
	while(left < n) {
		while(right < n && a[right].first < a[left].first +  d) {
			runningsum += a[right].second;
			right++;
		}
		answer = max(answer,runningsum);
		runningsum -= a[left].second;
		left++;
	}
	cout << answer << '\n';
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve(0);
	return 0;
	int t;
	cin >> t;
	for(int tt = 0 ;tt < t;tt++ ) {
		solve(tt);
	}

	return 0;
}
