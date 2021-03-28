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
  int q;
  cin >> q;
  range(i,  q) {
    long long k;
    cin >> k;
    long long product = 9, length = 1, calc = 0;
    while( k > product * length) {
      k -= product * length;
      calc += product;
      product *= 10;
      length++;
    }
    long long nthno = k/length , rem = k%length;
    debug(k, length, nthno, rem);
    long long number = calc + nthno + ((rem == 0)? 0: 1);
    rem = (rem + length - 1)%length;
    debug(number, rem, length);
    vector <int> digits;
    while(number) {
      digits.push_back(number%10);
      number /=10;
    }
    reverse(digits.begin(), digits.end());
    debug(digits);
    cout << digits[rem] << '\n';
    
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