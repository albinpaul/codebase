
 //~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct Suffixarray {
	struct myTuple {
		int originalIndex;
		int firstHalf;
		int secondHalf;
		bool operator < (myTuple T) {
			if (firstHalf == T.firstHalf) return secondHalf < T.secondHalf;
			else return firstHalf < T.firstHalf; 
		}
	};
	string inputstring;
	Suffixarray (string input):inputstring(input) {
	}
	vector <int> getSuffixArray () {
		int n = inputstring.size();
		vector <int> rank(n);
		for(int i=0 ; i < n ; i++){
			rank[i] = inputstring[i] - 'a';
		}
		myTuple L[n];
		for(int cnt = 1 ; cnt < n ; cnt *= 2) {
			for(int i = 0 ; i < n ; i++ ){
				L[i].firstHalf = rank[i];
				L[i].secondHalf = i + cnt < n ? rank[i + cnt] : -1 ;
				L[i].originalIndex = i; 
			}
			sort(L,L + n);
			vector <int> newrank(n);
			newrank[L[0].originalIndex] = 0;
			for(int i = 1,currRank = 0; i < n; ++i) {
				if (L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf ){
					++currRank;
				}
				newrank[L[i].originalIndex] = currRank;
			}
		}
		vector <int> result(n);
		for(int i=0;i<n;i++){
			result[i] = L[i].originalIndex;
		}
		return result;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Suffixarray test("aaab");
	cout << test.getSuffixArray();
	return 0;
}
