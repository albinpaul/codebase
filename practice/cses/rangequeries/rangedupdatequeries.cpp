#include <bits/stdc++.h>
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
const ll LMAX = numeric_limits<long>::max();
 
 
using ele = array<ll, 2>;
using ele_v = vector<ele>;
using ele_vv = vector<vector<ele>>;
using ll_v = vector<ll>;
using ll_vv = vector<vector<ll>>;
using ll_s = stack<ll>;
using bool_v = vector<bool>;
 
template <typename D, typename V>
void add(D &data, V value) {
  data = (data + value)%MOD;
}
const long int N = 2.1e5; 
ll n, q;
ll x[N];

struct node{
  ll ele, lazy;
} seg[1<<19];

void update(array<ll, 2> updateindex, ll x, array<ll,2> segment = {0, n-1}, ll i=0) {  
  if (segment[1] < updateindex[0] ||  updateindex[1] < segment[0] 
    || segment[0] > segment[1]) {
    return;
  }
  if (seg[i].lazy) {
    seg[i].ele += (segment[1] - segment[0] + 1) * seg[i].lazy;
    if (segment[0] != segment[1]) {
      seg[2 *i + 1].lazy += seg[i].lazy;
      seg[2 *i + 2].lazy += seg[i].lazy;
    }
    seg[i].lazy = 0;
  }
  // debug(i, updateindex, segment, x);
  if ( updateindex[0] <= segment[0] && segment[1] <= updateindex[1])
  {

    seg[i].ele += (segment[1] - segment[0] + 1) * x;
    if (segment[0] != segment[1]) {
      seg[2 *i + 1].lazy += x;
      seg[2 *i + 2].lazy += x;
    }
    return;
  }
  ll mid = (segment[0] + segment[1])/2;
  update(updateindex, x, {segment[0], mid}, 2*i + 1);
  update(updateindex, x, {mid + 1, segment[1] }, 2*i + 2);
  seg[i].ele = seg[2*i + 1].ele + seg[2*i +2].ele;
}


ll query(ll a, ll b, ll i=0, ll l=0, ll r=n-1) {
  if (seg[i].lazy) {
    seg[i].ele += (r - l + 1) * seg[i].lazy;
    if (l != r) {
      seg[2 *i + 1].lazy += seg[i].lazy;
      seg[2 *i + 2].lazy += seg[i].lazy;
    }
    seg[i].lazy = 0;
  }
  
  if (a <=l && r<= b) {
    return seg[i].ele;
  }
  if (b<l || r<a) {
    return 0;
  }
  ll mid = (l + r)/2;
  ll left = query(a, b ,2*i + 1, l, mid);
  ll right = query(a, b ,2*i + 2, mid+1, r);
  return left + right;
}

void init() {
  cin >> n >> q;
  range(i, n) {
    cin >> x[i];
    update({i, i}, x[i]);
    debug(i);
  }
  range(i, q){
    ll c;
    cin >> c ;
    debug(c);
    if (c == 1){
      ll a, b, u;
      cin >> a >> b >> u;
      --a; --b;
      update({a, b}, u);
    }
    else
    { 
      ll k;
      cin >> k;
      --k;
      cout << query(k, k) << '\n';
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