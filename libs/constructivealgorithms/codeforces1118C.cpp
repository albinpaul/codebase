
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




const long int N = 2.1e5;
pair <ll,ll> a[N];
const long long MOD = 1000 * 1000 * 1000 + 7;
int result[20][20];
int n;
bool done = false;
void updatefour(int element) {
	if (done) return;
	static int counter = 0;
	int mid = n/2;
	int i=counter/mid,j=counter%mid;
	result[i][j] = element;
	result[n -1 -i][j] = element;
	result[i][n - 1-j] = element;
	result[n - 1 -i][n - 1 -j] = element;
	if (i == mid - 1 && j == mid - 1) {
		done = true;		
	}
	counter++;
}

int vertcounter = 1,horzcounter = 1;
bool updatediagonalfour(int element)
{
	int mid = n/2;
	if(mid - vertcounter<0 || mid - horzcounter <0) 
		return false;
	result[mid - vertcounter][mid] = element;
	result[mid + vertcounter][mid] = element;
	result[mid][mid - horzcounter] = element;
	result[mid][mid + horzcounter] = element;
	vertcounter++;
	horzcounter++;
	return true;
}
bool horizontalorvertical = false;
bool draw(map <int,int> &mymap) {
	vector <pair <int,int>> m;
	for(auto it:mymap) {
		m.push_back(it);
	}
	sort(m.begin(),m.end(),[](auto &a,auto &b) {
		if ((a.second %4) == (b.second %4)) {
			return a.second > b.second;
		}
		return (a.second %4) < (b.second % 4);
	});
	for(auto &it:m) {
		while(it.second >=4)
			if (!done){
				updatefour(it.first);
				it.second -=4;
			}else{
				if (!updatediagonalfour(it.first))
				{	
					return false;
				}
				it.second -= 4;
			}
		int mid = n/2;
		if (it.second == 1 && n%2== 1) {
			if (result[mid][mid] != 0)
				return false;
			result[mid][mid] = it.first;	
		}
		else if (it.second %4 == 2 && n%2 == 1) {
			if (horizontalorvertical) {
				if (mid - horzcounter <0) 
					return false;
				result[mid][mid - horzcounter] = it.first;
				result[mid][mid + horzcounter] = it.first;
				horzcounter++;
			}else {
				if (mid - vertcounter <0) 
					return false;
				
				result[mid - vertcounter][mid] = it.first;
				result[mid + vertcounter][mid] = it.first;
				vertcounter++;
			}
			horizontalorvertical ^= true;
		} else if (it.second %4 == 3 && n%2 == 1) {
			if (horizontalorvertical) {
				if (mid - horzcounter <0) 
					return false;
				result[mid][mid - horzcounter] = it.first;
				result[mid][mid + horzcounter] = it.first;
				horzcounter++;
			}else {
				if (mid - vertcounter <0) 
					return false;
				
				result[mid - vertcounter][mid] = it.first;
				result[mid + vertcounter][mid] = it.first;
				vertcounter++;
			}
			horizontalorvertical ^= true;
			if (result[mid][mid] != 0)
				return false;
			result[mid][mid] = it.first;

		}
		else if(it.second >1){
			return false;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (result[i][j] ==0) {
				return false;
			}
		}
	}
	return true;	
}
void solve(int testcase){
	cin >> n;
	map <int,int> m;
	for(int i=0;i<n * n;i++) {
		int temp;
		cin >> temp;
		m[temp]++;
	}
	
	if (draw(m))
	{
		cout << "YES\n";
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout << result[i][j] << ' ';
			}cout << '\n';
		}
	}else {
		cout << "NO\n";
	}
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
