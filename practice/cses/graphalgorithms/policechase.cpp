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
const long int N = 503, M = 1000; 
ll graph[N][N], cgraph[N][N];
bool visited[N];
ll parent[N];
ll n, m;
ll in[N], out[N];
vector <array<ll,2>> ans;

bool bfs(ll start, ll end) {
  queue <int> q;
  q.push(start);
  memset(visited, 0, sizeof(visited));
  visited[start] = 1;
  while(q.size()) {
    ll u = q.front();
    q.pop();
    range(i, n) {
      // debug(u, i, visited[i], graph[u][i]);
        if (!visited[i] && graph[u][i]) {
        parent[i] = u;
        visited[i] = 1;
        q.push(i);
      }
    }
  }
  return visited[end];
}

void ford_fulkerson()
{
    ll max_flow = 0;
    while(bfs(0, n-1)) {
      ll path_flow = LLMAX;
      ll degrees = LLMAX;
      array<ll,2> cut;
      for(ll v= n-1 ; v!= 0; v=parent[v]) {
        ll u = parent[v];
        if (path_flow > graph[u][v]) {
          path_flow = graph[u][v];
        }
      }
      for(ll v= n-1 ; v!= 0; v=parent[v]) {
        ll u = parent[v];
        graph[u][v] -= path_flow;
        graph[v][u] += path_flow;
      }
      max_flow+= path_flow;
    }
    cout << max_flow << '\n';
}

void dfs(int u) {
  visited[u] = 1;
  for(int i=0;i<n;++i) {

    if(!visited[i] && graph[u][i]) {
      // debug(u, i, graph[u][i]);
      dfs(i);
    }
  }
}

void init() {
  cin >> n >> m;
  range(i, m) {
    ll a, b, c;
    cin >> a >> b;
    --a; --b;
    graph[a][b] +=1;cgraph[a][b] +=1;
    graph[b][a] +=1;cgraph[b][a] +=1;
  }
  ford_fulkerson();
  memset(visited, 0, sizeof(visited));
  dfs(0);
  range(i, n) {
    range(j, n) {
      if(visited[i] && !visited[j] && cgraph[i][j]) {
        cout << i + 1 << " " << j + 1 << '\n';
      }
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
    // cout << "Case #" << tt + 1 << ": ";
}