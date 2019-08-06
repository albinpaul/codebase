
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
#define watch(x) cerr << #x << " is " << x << ' '

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

struct Suffixarray
{
	struct myTuple
	{
		int originalIndex;
		int firstHalf;
		int secondHalf;
		bool operator<(myTuple T)
		{
			if (this->firstHalf == T.firstHalf)
				return this->secondHalf < T.secondHalf;
			else
				return this->firstHalf < T.firstHalf;
		}
	};
	string inputstring;
	vector<int> suffixarray;
	Suffixarray(string input) : inputstring(input)
	{
	}
	vector<int> getSuffixArray()
	{
		int n = inputstring.size();
		vector<int> rank(n);
		for (int i = 0; i < n; i++)
		{
			rank[i] = inputstring[i] - 'a';
		}
		myTuple L[n];
		for (int cnt = 1; cnt < n; cnt *= 2)
		{
			for (int i = 0; i < n; i++)
			{
				L[i].firstHalf = rank[i];
				L[i].secondHalf = i + cnt < n ? rank[i + cnt] : -1;
				L[i].originalIndex = i;
			}
			sort(L, L + n);
			vector<int> newrank(n);
			newrank[L[0].originalIndex] = 0;
			for (int i = 1, currRank = 0; i < n; ++i)
			{
				if (L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf)
				{
					++currRank;
				}
				newrank[L[i].originalIndex] = currRank;
			}
			rank = newrank;
		}
		vector<int> result(n);
		for (int i = 0; i < n; i++)
		{
			result[i] = L[i].originalIndex;
		}
		return result;
	}
	vector<int> kasaiutil(vector<int> sa)
	{
		int n = inputstring.size(), k = 0;
		vector<int> lcp(n, 0);
		vector<int> rank(n, 0);

		for (int i = 0; i < n; i++)
			rank[sa[i]] = i;

		for (int i = 0; i < n; i++, k ? k-- : 0)
		{
			if (rank[i] == n - 1)
			{
				k = 0;
				continue;
			}
			int j = sa[rank[i] + 1];
			while (i + k < n && j + k < n && inputstring[i + k] == inputstring[j + k])
				k++;
			lcp[rank[i]] = k;
		}
		return lcp;
	}
	vector<int> getlcparray()
	{
		suffixarray = getSuffixArray();
		return kasaiutil(suffixarray);
	}
	void output()
	{
		for (int i = 0; i < suffixarray.size(); i++)
		{
			cerr << i << ' ' << inputstring.substr(suffixarray[i]) << '\n';
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}
