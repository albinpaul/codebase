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
const long N = 1.1e5; 
vvi dp(N,vi(103,0));
vi a(N,0);
int n,m;
 
void init() { 
  cin >> n >> m;
  range(i,n) {
    cin >> a[i];
  }
  if (a[0] != 0) {
    dp[0][a[0]] = 1;
  }
  else {
    for(int k=1;k<=m;k++) {
      dp[0][k] = 1;
    }
  }
  range(i,n) {
    if (!i) continue; 
    int start, end;
    if (a[i] != 0) {
      start = a[i],end = a[i];
    } else {
      start = 1,end = m;
    }
    for(int k=start;k<=end;k++) {
      for(int j=max(k - 1,1);j <= min(k + 1,m);j++) 
      {
        dp[i][k] = (dp[i][k] + dp[i-1][j] )%MOD;
      }
    }
  }
  ll answer = 0;
  for(int k = 1;k<=m;k++) {
    answer = (answer + dp[n-1][k])%MOD;
  }
  // range(i,n)
  // {  for(int k = 1;k<=m;k++) {
  //     cerr << dp[i][k] << ' ';
  //   }
  //   cerr << '\n';
  // } 
  
  cout << answer;
  
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