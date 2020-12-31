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
ll_v adj[N], adj2[N];
ll labels[N];
bool visited[N];
vector <ll> st, st2;


void dfs1(ll u) {
  visited[u] =1;
  for(auto v: adj[u]) {
    if(!visited[v]) {
      dfs1(v);
    }
  }
  st.push_back(u);
}



void dfs2(ll u,ll root) {
  visited[u] = 0;
  labels[u] = root;
  for(auto v: adj2[u]) {
    if(visited[v]) {
      debug(u, v);
      dfs2(v, root);
    }
  }
}

void init() {
  ll n, m;
  cin >> m >> n;
  range(i, m) {
    ll a, b;
    char ca, cb;
    cin >> ca >>  a >> cb >>  b; a--; b--;
    a<<=1; b<<=1;
    if (ca == '-')
      a^=1;
    if (cb == '-')
      b^=1;
    adj[a^1].push_back(b);
    adj[b^1].push_back(a);
    // adj[b].push_back(a^1);
    // adj[b^1].push_back(a);
  }
  for(ll i=0;i<2*n;++i)
    for(auto neigh: adj[i]) {
      adj2[neigh].push_back(i);
    }  
  for(ll i=0;i<2*n;++i) {
    if (!visited[i]) {
      dfs1(i);
    }
  }
  for(ll i=2*n-1, root = 0;i>=0;--i) {
    if (visited[st[i]]) {
      dfs2(st[i], root++);
    }
  }
  debug("inputted");
  vector <bool> answer;
  for(long i=0;i<2*n;i+=2) {
    debug(i + 1, labels[i], labels[i+1]);
    if (labels[i] == labels[i+1]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    answer.push_back(labels[i] > labels[i+1]);
  }
  for(auto a: answer) {
    cout <<( a ? '+': '-') << " ";
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