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




int n;
vector <int> tree;

void update(int index, int val) {
  ++index;
  while(index <= n) {
    tree[index] += val;
    index += index & (-index);
  }
}

ll get(int index) {
  ++index;
  ll sum = 0;
  while(index > 0) {
    sum += tree[index];
    index -= (index &(-index));
  } 
  return sum;
}
ll get(int a, int b) {
  return get(b) - get(a - 1); 
}

void solve() {
  cin >> n;
  if (n == 1) {
    cout << 1;
    return;
  }
  tree.resize(n + 1);
  vector <int> input(n);
  vector <int> next(n), previous(n);
  vector <bool> visited(n, false);
  range(i,  n) {
   input[i] = i + 1;
   next[i] = (i + 1)%n;
   previous[i] = (i - 1 + n)%n;
  }
  int current_index = 1;
  range(i, n) {
    visited[current_index] = true;
    cout << input[current_index] << ' ';
    next[previous[current_index]] = next[current_index];
    previous[next[current_index]] = previous[current_index];
    current_index = next[next[current_index]];
  }




}
int main(void) {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  // cin >> t;
  range(i, 1) {
    // cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}