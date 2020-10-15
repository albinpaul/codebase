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
const long int N = 2.1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
// int a[N];
ll sqr(ll num) {
  return num * num;
}
const ll n = 7;
bool vis[n][n];
string s;
long long answer = 0;
bool exists(int i, int j)
{
  return 0 <= i && i< n && 0<= j && j < n && vis[i][j] == 0;
}
void recurse(int i, int j,int a = 0) {
  
  if (i == 6 && j == 0 ) {
    if (a == 48 ) {
      answer++;
    }
    return;
  }
  // debug(i,j);
  vis[i][j] = 1;
  if (s[a] == '?' || s[a] == 'L') {
    if ( j &&  !vis [i][j - 1] && 
      !(!exists(i,j - 2) && exists(i + 1,j - 1) && exists(i - 1,j - 1)) 
     )
    {
      recurse(i,j - 1,a + 1);
    }
  }
  if (s[a] == '?' || s[a] == 'R') {
    if (j + 1 < 7 &&  !vis [i][j + 1]  && 
      !(!exists(i,j + 2) && exists(i + 1,j + 1) && exists(i - 1,j + 1)) )
    {
      recurse(i,j + 1,a + 1);
    }
  }
   if (s[a] == '?' || s[a] == 'U') {
    if ( i && !vis [i - 1][j]  && !(!exists(i - 2,j) && exists(i - 1,j - 1 ) && exists(i - 1,j + 1)) )
    {
      recurse( i - 1,j,a + 1);
    }
  }
  if (s[a] == '?' || s[a] == 'D') {
    if ( i + 1 < 7 && !vis [i + 1][j]  && !(!exists(i + 2,j) && exists(i + 1,j -1) && exists(i + 1,j + 1)) )
    {
      recurse( i + 1,j,a + 1);
    }
  } 
  
  vis[i][j] = 0;
  
}
void init() { 
  cin >> s;
  memset(vis,0,sizeof(vis));
  recurse(0,0);
  cout <<answer << '\n';

}


void solve() {
  ll x,y;
  cin >> x >> y;

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