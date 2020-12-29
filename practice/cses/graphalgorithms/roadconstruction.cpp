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


const long int N = 1.1e5;
ll p[N], cc[N];

ll find(ll x) {
  if (x != p[x])
  {
    p[x] = find(p[x]);
    return p[x];
  } else {
    return x;
  }
}

bool join(ll x, ll y){
  if ((x=find(x)) ==( y=find(y)) )
    return 0;
  p[x] = y;
  cc[y] += cc[x];
  return 1;
}

void init() {
  ll n, m;
  cin >> n >> m;
  vector<array <ll, 2>> edges;
  range(i, m) {
    ll a, b;
    cin >> a >> b;
    edges.push_back({a, b});
  }
  iota(p, p + n, 0);
  fill(cc, cc + n , 1);
  ll vertex = 0, answer = 0;
  ll csize = 0, c_count = n;
  for(auto e: edges) {
    if (join(e[0],e[1])) {
      debug(cc[p[e[0]]], cc[p[e[1]]]);
      csize = max(csize, cc[p[e[1]]]);
      c_count--;
    }
    cout << c_count << " " << csize << '\n';
  }  
   
}
void solve() {
}

int main(void) {
  #ifdef LOCAL
  freopen("in", "r", stdin); 
  #endif
  // added the two lines below
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  init();
  return 0;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    // cout << "Case #" << tt + 1 << ": ";
    solve();
  }
  return 0;
}