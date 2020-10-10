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
// int a[N];
ll sqr(ll num) {
  return num * num;
}

void init() {
  int n;
  cin >> n;
  long long s = (n  * ( n + 1 ))/2;
  if (s%2 != 0) {
    cout << "NO\n";
  } 
   else 
  {
    cout << "YES\n";
    vector <int> v1,v2;
    ll sum1 = 0,sum2 = 0;
    if (n%4 == 0) {
      for(int i=1;i<=n;i+=4) {
        v1.push_back(i);
        v1.push_back(i + 3);
        v2.push_back(i + 1);
        v2.push_back(i + 2); 
      }
    }
    else if ((n  + 1)%4 == 0){
      v1 = {1,2},v2 = {3};
      for(int i=4;i<=n;i+=4) {
        v1.push_back(i);
        v1.push_back(i + 3);
        v2.push_back(i + 1);
        v2.push_back(i + 2); 
      }
    }
    // assert(sum1,sum2);
    // sum1= accumulate(all(v1),0);sum2 = accumulate(all(v2),0);
    // debug(sum1,sum2);
    
    cout << v1.size() << '\n';
    for(auto v:v1) {
      cout << v << ' ';
    }
    cout << '\n';
    cout << v2.size() << '\n';
    for(auto v:v2) {
      cout << v << ' ';
    }
  }
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