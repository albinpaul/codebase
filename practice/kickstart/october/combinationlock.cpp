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
const long int N = 1.1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
// int a[N];
ll sqr(ll num) {
  return num * num;
}

void init() { 

}


void solve() {
  ll n, w;
  cin >> n >> w;
  vector <ll> a(n);
  range(i, n) {
    cin >> a[i];
  }
  sort(all(a));
 
  ll ca = 0, answer = numeric_limits<ll>::max();

  vector <ll> prefix{0};
  range(i,n){
    prefix.push_back(prefix[i] + a[i]);
  }
  debug(prefix);
  auto getSum = [&] (ll i, ll j) {
    return  prefix[j] - prefix[i - 1];
     
  };
  
  #ifdef LOCAL
  range(i,n) {
    cout << a[i] << " ";
  }
  cout << endl;
  #endif
  
  debug(n,w);
  for(int i=1;i<=n;++i) 
  {
    ll left = lower_bound(all(a), a[i-1] - w/2) - a.begin();
    ll right = upper_bound(all(a), a[i-1] + w/2) - a.begin() - 1;
    left++;right++;
    debug(i,left, right);
    ll current = 0;
    ll v = a[i-1];
    current += v * (i - left + 1) -( prefix[i] - prefix[left - 1]);
    debug(current);
    current += (prefix[right] - prefix[i - 1]) - v * ( right - i + 1);  
    debug(current, prefix[right] - prefix[i - 1] );
    current += (w + v) * (n - right) - (prefix[n] - prefix[right]);
    debug(current);
    current += prefix[left - 1] - (v - w) * (left - 1);
    debug(current);
    answer = min(current, answer);
  }
  cout << answer << '\n';
}



int main(void) { 
  int t;\
  init();
  // return 0;
  cin >> t;
  for(int tt = 0 ; tt < t ; tt++)  
  {
    cout << "Case #" << tt + 1 << ": ";
    solve();
  }
  return 0;

}