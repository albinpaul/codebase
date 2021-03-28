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
  int n, m;
  cin >> n >> m;
  vector <array<int, 2>> a(n + 1);
  vector <int> orig(n);
  a[0][0] = -1;
   a[0][1] =  n + 5;
  for(int i=1;i<=n;++i) {
    cin >> a[i][0];
    orig[i-1] = a[i][0];
    a[i][1] = i;
  }
  sort(a.begin(), a.end());
  
  long answer = 0;
  vector <int> status(n + 1);
  for(int i=1; i <= n;++i) {
    status[i] = a[i-1][1] > a[i][1] ;
    answer += status[i];
  }

  debug(status);
  debug(a);
  debug(orig);
  
  range(i, m) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    swap(orig[l], orig[r]);
    swap(a[orig[l]][1], a[orig[r]][1]);
    int left = orig[l];
    int right = orig[r];
    debug(orig);
    debug(a);
    debug(l, r);
    debug(status);
    debug(left, right);
    auto check_change = [&] (int index) {
      if (index == 0 || index == n + 1) 
        return;
      int changed = a[index - 1][1] > a[index][1];
      answer += changed - status[index];
      status[index] = changed;  
    };
    check_change(left - 1);
    check_change(left);
    check_change(left + 1);
    check_change(right - 1);
    check_change(right);
    check_change(right + 1);
    debug(status);
    cout << answer << '\n'; 
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