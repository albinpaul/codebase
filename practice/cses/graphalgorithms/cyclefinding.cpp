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
ll dist1[N];
int parent[N];
// vector <array<int, 2>> adj1[N];
ll answer;
bool c(int i, int j) {
  return 0<= i && i < n && 0 <=j && j <m;
}

void init() { 
  cin >> n >> m;  
  memset(dist1, 0x3f, sizeof(dist1));
  memset(parent, 0, sizeof(parent));
  debug(n, m);
  // range(i,N) range(j,N) dist[i][j] = INF;
  vector <array<ll, 3>> edges;
  range(i, m){
    long long  a, b, c;
    cin >> a >> b >> c;
    // adj1[a].push_back({b, c});
    edges.push_back({a, b, c});
  }
  int S;
  for(int i=0;i<n;++i) {
    S = -1;
    for(auto e: edges) {
      ll u = e[0], v = e[1], c = e[2];
      if (dist1[v] > dist1[u] + c) {
        dist1[v] = dist1[u] + c;
        parent[v] = u;
        S = v;
      }
    }
  }
  if (S!= -1) {
    for(int i=0;i<n;i++)
      S = parent[S];  
    vector<int> cycle;
    for (int v = S;; v = parent[v]) {
        // debug(v);
        cycle.push_back(v);
        if (v == S && cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle)
        cout << v << ' ';
    // cout << endl;
  } else {
    cout << "NO\n";
  }


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