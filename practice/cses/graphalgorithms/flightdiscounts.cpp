#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
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

#define range(i,n)  for(long i = 0; i < (long long)n ; ++i )
#define rrange(i,n) for(long i = (long long)n-1; i >= 0; --i )
#define all(x) x.begin(),x.end()
#define watch(x) cerr << #x << " is : " << x << " " 
using pii = pair <int,int>;
using vi = vector <int>;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

const long int N = 1.1e5;
long n,m;
ll dist1[N], dist2[N];
vector <array<int, 2>> adj1[N], adj2[N];
ll answer;
bool c(int i, int j) {
  return 0<= i && i < n && 0 <=j && j <m;
}

void dfs(int start, ll dist[N], vector <array<int, 2>> adj[N]) {
  using ele = array <ll, 2>; 
  priority_queue <ele, vector <ele>, greater<ele>> pq;
  dist[start] = 0;
  pq.push({0, start});
  while(pq.size()) {
    auto e = pq.top();
    ll c = e[0], u = e[1];
    pq.pop();
    debug(u, c);
    if (c > dist[u]) continue;
    for(auto ad: adj[u]) {
      ll v = ad[0], c2 = ad[1];
      if (dist[u] + c2 < dist[v]) {
        dist[v] = c2 + dist[u];
        pq.push({dist[v], v});
      }
    }
  }
}

void init() { 
  cin >> n >> m;  
  memset(dist1, 0x3f, sizeof(dist1));
  memset(dist2, 0x3f, sizeof(dist2));
  debug(n, m);
  // range(i,N) range(j,N) dist[i][j] = INF;
  range(i, m){
    long long  a, b, c;
    cin >> a >> b >> c;
    adj1[a].push_back({b, c});  
    adj2[b].push_back({a, c});
  }
  dfs(1, dist1, adj1);
  dfs(n, dist2, adj2);
  ll answer = numeric_limits<ll>::max();
  for(int i=1;i<=n;++i) {
    for(auto e: adj1[i]) {
      answer = min(answer , dist1[i] + dist2[e[0]] + e[1]/2);
    }
  } 
  cout << answer;
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
  for(int tt = 0 ; tt < t ; tt++)  
  {
    // cout << "Case #" << tt + 1 << ": ";
    solve();
  }
  return 0;

} 