
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
template <class T>
void logd(T x) {
	#ifdef DEBUG
		cerr << x<< endl;
	#endif
}

const long int N = 1.1e6,M=1.1e3;
const long long MOD = 1000 * 1000 * 1000 ;

pair <ll,ll> parse(string s) {
	long count = 0,index = 0;
	string substring = "";
	ll number = 0;
	pair <ll,ll> point;
	point.first = 0;
	point.second = 0;

	while(index < (long)s.size()) {
		if (s[index] == '(') {
			count++;
			index++;
			while(count > 0 && index < (long)s.size()) {
				if (s[index] == '(') count++;
				else if (s[index] == ')') count--;
				if (count == 0) 
					break;
				
				substring += s[index];
				index++;
			}
			pair <ll,ll> subpoint = parse(substring);
			
			point.first += ((number)%MOD * (subpoint.first)%MOD)%MOD;
			point.second += ((number)%MOD * (subpoint.second)%MOD)%MOD;
			substring =  "";
			number = 0;
		} else if (s[index] >= '0' && s[index] <= '9') {
			number = number * 10 + (s[index] - '0');
		}else if(s[index] == 'N') {
			point.first = (point.first - 1 + MOD)%MOD ;
		}else if(s[index] == 'S') {
			point.first = (point.first + 1 + MOD)%MOD;
		}else if(s[index] == 'E') {
			point.second = (point.second + 1 + MOD)%MOD  ;
		}else if (s[index] == 'W') 
			point.second = (point.second - 1 + MOD)%MOD;
		else 
			assert(false);
		index++;

	}
	return point;
}
void solve(int testcase){
	cout << "Case #" << testcase << ": ";
	string s;
	cin >> s;
	pair <ll,ll> point = parse(s);
	cout << ((point.second + MOD)%MOD + 1)<< " " << ((point.first + MOD)%MOD + 1)<< endl;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// solve(0);
	// return 0;
	int t;
	cin >> t;
	for(int tt = 1 ;tt <= t;tt++ ) {
		solve(tt);
	}

	return 0;
}
