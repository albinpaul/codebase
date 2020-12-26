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
const ll LLMAX = numeric_limits<ll>::max()/2;
const ll LMAX = numeric_limits<long>::max();
const long int N = 1.1e5;

ll n, m, k;

using ele = array<ll, 2>;
using ele_v = vector<ele>;
using ele_vv = vector<vector<ele>>;
using ll_v = vector<ll>;
using ll_vv = vector<vector<ll>>;
using ll_s = stack<ll>;
using bool_v = vector<bool>;
using node = array<ll, 2>;
using node_pq = priority_queue<node, vector<node>, greater<node>>;

vector<array<ll,4>> dist(N);

vector <set<int>> parent(N);
ele_vv adj(N);
ele_vv adj_rev(N);
bool_v vis(N,false);

bool c(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}
template <typename D, typename V>
void add(D &data, V value) {
  data = (data + value)%MOD;
}
// void dfs(ll u) {
//   vis[u] = 1;
//   for(auto v: adj_rev[u]) {
//     debug(u, v[0]);
    
//     if (!vis[v[0]]) {
//       dfs(v[0]);
//     }
    
//     dist[u][1] += dist[v[0]][1];
    
//   }
// }
 
void dfs2(ll u) {
  vis[u] = 1;
  for(auto v: adj_rev[u]) {  
    if (!vis[v[0]]) {
      dfs2(v[0]);
    }
    add(dist[u][1] ,dist[v[0]][1]);
    dist[u][2] = min(dist[u][2], dist[v[0]][2] + 1);
    dist[u][3] = max(dist[u][3], dist[v[0]][3] + 1);
    
  }
  //  debug(dist[u][1], dist[u][2]);
}

void dijikstra() {
  node_pq pq;
  pq.push({0, 1});
  range(i, n+1) dist[i][2] = dist[i][0] = LLMAX;
  dist[1][1] = 1;
  dist[1][0] =  dist[1][2] = dist[1][3] = 0;
  while (pq.size()) {
    auto u = pq.top();
    pq.pop();
    if (u[0] > dist[u[1]][0])
      continue;
    for (auto v : adj[u[1]]) {
      if (dist[v[0]][0] > dist[u[1]][0] + v[1]) {
        dist[v[0]][0] = dist[u[1]][0] + v[1];
        pq.push({dist[v[0]][0], v[0]});
      } 
      
      
    }
  }
}



void init() {
  cin >> n >> m;
  debug(n, m);
  map <array<ll,2>, ll> edges;
  range(i, m) {
    long long a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  dijikstra();
  
  for(int i=1;i<=n;++i) {
    for(auto e: adj[i]) {
      if (dist[i][0] + e[1]== dist[e[0]][0])
        adj_rev[e[0]].push_back({i, e[1]});
    }
  }
  // for(int i=1;i<=n;++i) {
  //   if (!vis[i]) dfs(i);
  // }
  
  fill(all(vis), 0);
  for(int i=1;i<=n;++i) {
    if (!vis[i]) dfs2(i);
  }
  range(i, 4) cout << dist[n][i] << " ";
  // cerr << "\n";
  // range(i, n + 1) cerr << dist[i][1] << " ";
  
}

void solve() {
}

int main(void) {
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