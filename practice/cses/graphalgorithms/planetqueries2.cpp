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
ll parent[N], root[N], position[N], cycle_root[N], depth[N], cycle_size[N];
ll start[N], finish[N], timer = 0;
bool visited[N];
ll_v adj[N];
ll n, q;

void dfs(ll u) {
  start[u] = ++timer;
  for(auto v: adj[u]) {
    if (root[v] != v) {
      debug(u, v);
      root[v] = root[u];
      cycle_root[v] = cycle_root[u];
      depth[v] = depth[u] + 1;
      dfs(v);
    }  
  }
  finish[u] = ++timer;
}


void init() {
  cin >> n >> q;
  range(i, n) {
    cin >> parent[i];
    --parent[i];
    adj[parent[i]].push_back(i);
  }
  vector <ll> cycle;
  memset(root, -1, sizeof(root));
  range(i,n) {
    if (root[i] != -1)
      continue;
    ll u = i;
    while(!visited[u]) {
      visited[u] = 1;
      u = parent[u];
    }
    while(!cycle.size() || u ^ cycle[0]) {
      position[u] = cycle.size();
      cycle.push_back(u);
      cycle_root[u] = i;
      root[u] = u;
      u = parent[u];
    }
    debug(cycle);
    for(ll c: cycle) {
      timer = 0, dfs(c), cycle_size[c] = cycle.size();
    } 
    cycle.clear();
  }
  range(j, q) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ll answer = -1;
    if (cycle_root[a] == cycle_root[b]) {
      debug(cycle_root[a], cycle_root[b]);
      if (root[b] == b) {
        answer = depth[a];
        a = root[a];
        answer += (position[b] - position[a] + cycle_size[a] )% cycle_size[a];
      } else {
        debug(start[a], start[b], finish[a], finish[b]);
      
        if (root[a] == root[b] && start[b] <= start[a] && finish[a] <= finish[b]){
          answer = depth[a] - depth[b];
        }
      }
    }
    cout << answer << '\n';
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