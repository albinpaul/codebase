
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

const long int N = 2.1e5;
pair <ll,ll> a[N];
const long long MOD = 1000 * 1000 * 1000 + 7;



void solve(int testcase){
	/**
		co-ordinate compression
	**/
	int n;
	cin >> n;
	vector <ll> cval;
	for(int i=0;i<n;i++) {
		cin >> a[i].first >> a[i].second;
		cval.push_back(a[i].first);
		cval.push_back(a[i].second + 1);
	}
	sort(a,a+n);
	sort(all(cval));
	cval.resize(unique(all(cval))-cval.begin());
	vector <int> cnt(n * 2,0);
	for(int i=0;i<n;i++) {
		long pos1 = lower_bound(all(cval),a[i].first) - cval.begin();
		long pos2 = lower_bound(all(cval),a[i].second + 1) - cval.begin();
		++cnt[pos1];
		--cnt[pos2];
	}	
	for(int i=1;i < 2 *n; ++i) {
		cnt[i] += cnt[i-1];
	}
	vector <ll> ans(n + 1);
	for(int i=1;i< 2 *  n;i++) {
		ans[cnt[i - 1]] += cval[i] -  cval[i - 1];
	}

	for(int i=1;i<=n;i++) {
		cout << ans[i] << ' ';
	}cout << '\n';
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
