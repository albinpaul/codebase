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

const long int N = 1.1e3;
int n,m;
vector <string> a(N);
int visited[N][N],p1[N][N],p2[N][N],d1[N][N],d2[N][N];
vector <pair <string, pair<int,int>>> dirs {
  {"U",{-1,0}},
  {"D",{1,0}},
  {"L",{0,-1}},
  {"R",{0,1}},
};  
vector <array<int,2>> M,A;

bool c(int i, int j) {
  return 0<= i && i < n && 0 <=j && j <m && !visited[i][j] && a[i][j] == '.';
}
void show(int arrayd[N][N]) {
  range(i,n) {
    range(j,m) {
      cerr << arrayd[i][j] << " ";
    }cerr << '\n';
  }
  cerr << '\n';
}

void bfs(vector <array <int, 2>> &vv, int dist[N][N], int parent[N][N])
{
  
  memset(visited, 0, sizeof(visited));
  range(i,n) range(j,m) dist[i][j] = INF;
  queue <array <int, 2 >> q;
  for(auto v: vv) {
    q.push(v);
    visited[v[0]][v[1]] = 1;
    dist[v[0]][v[1]] = 0;
  }
  while(q.size()) {
    auto u = q.front();
    debug(u);
    q.pop();
    for(int i=0;i<4;i++) {
      auto d = dirs[i].second;
      int l = u[0] + d.first, r = u[1] + d.second;
      if (c(l,r)) {
        parent[l][r] = i;
        dist[l][r] = dist[u[0]][u[1]] + 1;
        visited[l][r] = 1;
        q.push({l,r});
      }
    }
  }
  // show(dist);
}
void init() { 
  cin >> n >> m;  
  range(i, n){
    cin >> a[i];
    range(j,m) {
      if (a[i][j] == 'A') {
        A.push_back({i,j});
        a[i][j] = '.';
      }
      if (a[i][j] == 'M') {
        M.push_back({i,j});
        a[i][j] = '.';
      }
    }
  }
  debug(A, M);
  bfs(A, d1, p1);
  bfs(M, d2, p2);
  array <int, 2> endpoint = {-1, -1};
  for(int i=0;i<n;++i) {
    if (d1[i][0] < d2[i][0] ){
      endpoint = {i,0};
    }
    if (d1[i][m-1] < d2[i][m-1] ) {
      endpoint = {i,m-1};
    }
  }

  for(int i=0;i<m;++i) {
    if (d1[0][i] < d2[0][i] ){
      endpoint = {0, i};
    }
    if (d1[n-1][i] < d2[n-1][i] ) {
      endpoint = {n-1,i};
    }
  }
  if (endpoint[0] == -1 && endpoint[1] == -1) {
    cout << "NO\n";return;
  }
  cout << "YES\n";
  string path = "";
  array <int,2> e = endpoint;
  debug(e);
  // show(p1);
  while(e != A[0]) {
    int i = p1[e[0]][e[1]];
    path += dirs[i].first;
    e[0] -= dirs[i].second.first;
    e[1] -= dirs[i].second.second;
  }
  reverse(all(path));
  cout << path.size() << '\n' << path;

}

void solve() {

}



int main(void) { 
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