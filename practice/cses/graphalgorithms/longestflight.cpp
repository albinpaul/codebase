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
using pii = pair <long,long>;
using vi = vector <long>;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LLMAX = numeric_limits<ll>::max();
const long int N = 1.1e5;


ll n, m, k;
ll answer;

vector <ll> adj1[N];
ll dist[N], parent[N];

bool c(int i, int j) {
  return 0<= i && i < n && 0 <=j && j <m;
}

void init() { 
  cin >> n >> m;  
  debug(n, m);
  range(i, m){
    long long  a, b;
    cin >> a >> b;
    adj1[a].push_back(b);
  }
  using ele = array <ll, 2>;
  priority_queue <ele, vector <ele>, greater<ele>> pq;
  pq.push({1,1});
  while(pq.size()) {
    auto t = pq.top();
    ll u = t[1],d = t[0];
    pq.pop();
    if (d < dist[u]) continue;
    for(auto n: adj1[u]) {
      if (dist[u] + 1 > dist[n]) {
        pq.push({dist[u] + 1, n});
        dist[n] = dist[u] + 1;
    
        parent[n] = u;
      }
    }
  }
  if (dist[n] == 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector <ll> path{n};
    ll start = n;
    while(start ^ 1) {
      start = parent[start];
      path.push_back(start);
    }
    reverse(all(path));
    cout << path.size() << "\n";
    for(auto p: path) {
      cout << p << " ";
    } cout << '\n';
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