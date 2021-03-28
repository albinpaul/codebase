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


vector <int> stree, vals;
int n, k;


void insert(int i, int val) {
  ++i;
  while(i <= n) {
    stree[i] += val;
    i += i & (-i);
  }
}

ll query(int i) {
  ++i;
  ll sum =0;
  while(i >0) {
    sum += stree[i];
    i -= i&(-i);
  }
  return sum;
}
ll query(int a, int b) {
  return query(b) - query(a - 1);
}

void solve() {
  cin >> n >> k;
  if (n == 1) {
    cout << 1;
    return;
  }
  stree.resize(n * 5, 0);
  vals.resize(n, 0);
  range(i, n) {
    insert(i, 1);
    vals[i] = 1;
  }
  k++;
  int init_k = k;
  debug(n, k);
  debug(vals);
  int pos = (k - 1 + n)%n;
  int total = n;
  range(j, n ){
    cout << pos + 1 << ' ';
    if (j == n-1)
      break;
    insert(pos, -1);
    vals[pos] -=1;
    ll right_sum = query(pos, n-1);
    
    total--;
    
    k = (init_k - 1 + total)%total + 1;
    if (right_sum == 0) {
      pos = -1;
      right_sum = total;
    }
    debug(pos, k, right_sum, total);
    debug(vals);
    if(k <=right_sum) {
      int left = pos, right = n - 1;
      int mid;
      while(left <= right) {
        mid = (left + right)/2;
        ll ele = query(pos + 1, mid);
        debug(ele, mid, left, right);
        if (ele == k && vals[mid] == 1) {
          break;
        } else if (ele < k) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      pos = mid;
    } 
    else {
      int kleft = k - right_sum;
      debug(kleft);
      int left = 0, right = pos;
      int mid;
      while(left <= right) {
        mid = (left + right)/2;
        ll ele = query(0, mid);
        debug(ele, mid, left, right);
        if (ele == kleft && vals[mid] == 1) {
          break;
        } else if (ele < kleft) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      pos = mid;
    }
  }
  // range(i, n) {
  //   if (vals[i] == 1) {
  //     cout << i + 1;
  //   }
  // }
 
}

int main(void) {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  range(i, t) {
    // cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}