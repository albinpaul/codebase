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
using vi = vector <long>;
using ll = long long;
using vvi = vector <vector < long>>;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
// int a[N];
ll sqr(ll num) {
  return num * num;
}
const long N = 5.1e2; 
vvi dp(N,vi(N,INF));
long solve(int x,int y) {
  if (x > y) {
    swap(x,y);
  }
  if (dp[x][y] != INF)
    return dp[x][y];
  if (x <1 || y <1) return INF;
  // debug(x,y);
  // if (x <1 || y <1) return INF;
  
  for(int i=1;i<x;++i) {
    dp[x][y] = min(dp[x][y], solve(i,y) + solve(x-i,y) + 1); 
  }
  for(int i=1;i<y;++i) {
    dp[x][y] = min(dp[x][y], solve(x ,i) + solve(x,y-i) + 1); 
  }
  int m = min(x,y);
  
  // dp[x][y] = min(dp[x][y], solve(m,m) + solve(x - m , y) + 1); 
  // dp[x][y] = min(dp[x][y], solve(m,m) + solve(x , y - m) + 1);
  return dp[x][y];
}
void init() { 
  int a, b;
  cin >> a >> b;
  for(int i=1;i<=min(a,b);++i) {
    dp[i][i] = 0;
  }
  cout << solve(a,b);
  // for(int i=1;i<=a;++i) {
  //   for(int j=1;j<=b;++j) {
  //     cerr << dp[i][j] << " ";
  //   }cerr << '\n';
  // }
}


void solve() {

}



int main(void) { 
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