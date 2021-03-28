#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>      // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define range(i, n) for (long i = 0; i < (long long)n; ++i)
#define rrange(i, n) for (long i = (long long)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define watch(x) cerr << #x << " is : " << x << " "
using pii = pair<long, long>;
using vi = vector<long>;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LLMAX = numeric_limits<ll>::max();
const ll LLMIN = numeric_limits<ll>::min();
const ll LMAX = numeric_limits<long>::max();

using ele = array<ll, 2>;
using ele_v = vector<ele>;
using ele_vv = vector<vector<ele>>;
using ll_v = vector<ll>;
using ll_vv = vector<vector<ll>>;
using ll_s = stack<ll>;
using bool_v = vector<bool>;

template <class T>
using orderedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
  int n;
  cin >> n;
  vector <array<int,3>> a(n);
  range(i, n) {
    cin >> a[i][0];
    a[i][2] = i;
  }
  range(i, n) {
    cin >> a[i][1];
  }
  sort(a.begin(), a.end());
  long currentpos = -1;
  long answer = 0;
  for(auto b: a){
    long pos = b[2];
    long increment = b[1];
    if (pos < currentpos) {
      long diff = (currentpos - pos);
      long times = ceil(diff/double(increment));
      currentpos = pos + increment * times;
      answer += times;
      assert(currentpos>= pos);
    } 
    else {
      currentpos = pos;
    }
    currentpos++;
  }
  cout << answer ;
  cout << '\n';
}

int main(void) {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  range(i, t) {
    // cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}