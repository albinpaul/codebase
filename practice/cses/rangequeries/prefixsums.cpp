
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string &s) {
  return '"' + s + '"';
}
 
string to_string(const char *s) {
  return to_string((string)s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
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
using orderedset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename D, typename V>
void add(D &data, V value) {
  data = (data + value)%MOD;
}
const long int N = 2.1e5; 


ll n, q;
int a[N];
struct node{
  ll ele, maxim;
} seg[1<<19];
void update(ll index, ll x, ll i=0, ll l=0, ll r=n-1) {
  if (l == r && r == index) {
    debug(l, x, index, i);
    seg[i].ele = x;
    seg[i].maxim = x;
    return;
  }
  if (index < l || r < index)
    return;
  // debug(index, x, i, l, r);
  ll mid = (l + r)/2;
  update(index, x, 2*i + 1, l, mid);
  update(index, x, 2*i + 2, mid + 1, r);
  seg[i].ele = seg[2*i + 1].ele + seg[2*i +2].ele;
  seg[i].maxim = max(seg[2*i + 1].ele + seg[2 * i+ 2].maxim, seg[2 *i + 1].maxim); 
}

ll limit= LLMIN;
ll answer = limit;
ll right_sum = 0;
void query(ll a,ll b, ll i=0, ll l=0, ll r=n-1) {
  if (a <=l && r<= b) {
    answer = max(answer, seg[i].maxim + right_sum);
    right_sum+= seg[i].ele; 
    debug(seg[i].maxim, i, l, r, seg[i].ele);
    return;
  }
  if (b<l || r<a) {
    return;
  }
  ll mid = (l + r)/2;
  query(a, b ,2*i + 1, l, mid );
  query(a, b ,2*i + 2, mid+1, r );
}
ll query1(ll a, ll i=0, ll l=0, ll r=n-1) {
  if (0<=l && r <=a) {
    return seg[i].ele;
  }
  if (a<l || r<a) {
    return 0LL;
  }
  ll mid = (l + r)/2;
  ll left = query1(a,2*i + 1, l, mid);
  ll right = query1(a,2*i + 2, mid+1, r);
  return left +  right;
}
void init(){
  cin >> n >> q;
  range(i, n) {
    cin >> a[i];
    update(i, a[i]);
  }
  debug(seg[0].ele, seg[0].maxim);
  range(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, u;
      cin >> k >> u;
      k--;
      update(k, u);
    } else {
      ll a, b;
      cin >> a >> b; --a, --b;
      answer = limit;
      right_sum = 0;
      query(a, b);
      cout << max(0LL,answer) << '\n';
    }
  }
}
void solve() {
}
 
int main(void) {
  #ifdef LOCAL
  freopen("in", "r", stdin); 
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  init();
  return 0;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
}