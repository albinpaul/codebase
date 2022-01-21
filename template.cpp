#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define range(i, end) for (int32_t i = 0; i < (int32_t)end; ++i)
#define range2(i,start, end) for (int32_t i = start; i < (int32_t)end; i=i + (start < end)?1:-1)
#define all(x) x.begin(), x.end()
 
#ifdef LOCAL
	#define profile(x) ScopedTimer timer(x);
#else
	#define profile(x) 
#endif

const int INF = 0x3f3f3f3f;
const int64_t LINF = 2e18;
const int MOD = 1000*1000*1000 + 7;  

int64_t mod(int64_t num){
	assert(num >= 0LL);
	return num%MOD; 
}



void solve(int32_t i){
	
}

int main(void) {
	profile("main");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	range(i, t){
		// cout << "Case #"<<(i+1)<<": ";
		solve(i);
	}
	
	return 0;
}


