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

const long int N = 2505;
long n,m,q;
ll dist[N];
vector <array<ll,3>> edges;
bool visited[N], visited2[N];
vector <int> adj[N], adj2[N];
ll answer;
bool c(int i, int j) {
  return 0<= i && i < n && 0 <=j && j <m;
}

void dfs(int u) {
  visited[u] = 1;
  for(auto v: adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}
void dfs2(int u) {
  debug(u);
  visited2[u] = 1;
  for(auto v: adj2[u]) {
    if (!visited2[v]) {
      dfs2(v);
    }
  }
}


void init() { 
  cin >> n >> m;  
  memset(dist, 0x3f, sizeof(dist));
  debug(n, m);
  // range(i,N) range(j,N) dist[i][j] = INF;
  range(i, m){
    long long  a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a,b,-c});
    
    adj[b].push_back(a);  
    adj2[a].push_back(b);
  }
  dist[1] = 0;
  for(int i=0;i<n-1;++i) {
    for(auto e: edges) {
      long f = e[0], t = e[1], c = e[2]; 
      if (dist[f] + c < dist[t]) {
        dist[t] = dist[f] + c;
      }
    }
  }
  dfs(n);
  dfs2(1);
  for(auto e: edges) {
    long f = e[0], t = e[1], c = e[2]; 
    bool vis = visited[f] && visited[t] && visited2[t] && visited2[f];
    if (dist[t] > dist[f] + c && vis) {
      answer = -1;
      break;
    }
  }
  if (answer == -1) {
    cout << -1 << '\n';
  } else {
    cout << -dist[n] << "\n";  
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