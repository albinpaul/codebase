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
#define range(i,n)  for(long i = 0  ; i < (long long)n ; ++i )
#define rrange(i,n) for(long i = (long long)n-1; i >= 0; --i )
#define all(x) x.begin(),x.end()
#define watch(x) cerr << #x << " is : " << x << " " ;
using pii = pair <int,int>;
using vi = vector <int>;
using ll = long long;
const long int N = 105;
const int INF = 0x3f3f3f3f;
int a[N][N];
void solve() {
  int n;
  cin >> n;
  range(i,n) {
    range(j,n) {
      cin >> a[i][j];
    }
  }
  ll answer = 0;
  rrange(i,n) {
    if (i == 0) {
      break;
    }
    debug (i);
    bool do_swap= false;
    for( int j = i; j >= 0 ; --j ){
      int x = i - j, y = i;
      debug(x,y,(x) * n + (y + 1),a[x][y]);
      do_swap |=( (x) * n + (y + 1) != a[x][y]);
    }
    debug(do_swap);
    if (do_swap) {
      for(int j=0;j<=i;j++) {
        for(int k=0;k<j;k++) {
          swap(a[j][k],a[k][j]);
        }
      }
    }
    answer += do_swap;
    
  }
  cout << answer << '\n';
  
}
int main(void) { 
  int t;
  cin >> t;
  for(int tt = 0 ; tt < t ; tt++ )  
    solve();
  return 0;

}