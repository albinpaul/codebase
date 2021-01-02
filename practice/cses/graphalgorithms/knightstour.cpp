#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char *s) {
  return to_string((string)s);
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

#define range(i, n) for (long i = 0; i < (long long)n; ++i)
#define rrange(i, n) for (long i = (long long)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define watch(x) cerr << #x << " is : " << x << " "
using pii = pair<long, long>;
using vi = vector<long>;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LLMAX = numeric_limits<ll>::max();
const ll LMAX = numeric_limits<long>::max();


using ele = array<ll, 2>;
using ele_v = vector<ele>;
using ele_vv = vector<vector<ele>>;
using ll_v = vector<ll>;
using ll_vv = vector<vector<ll>>;
using ll_s = stack<ll>;
using bool_v = vector<bool>;

template <typename D, typename V>
void add(D &data, V value) {
  data = (data + value)%MOD;
}
const long int N = 8; 
ll a[N][N];
ll x, y;
vector <array<ll, 2>> moves{
  {1,2},
  {2,1},
  {-1,2},
  {-2,1},
  {1,-2},
  {2,-1},
  {-1,-2},
  {-2,-1}
};

bool c(ll i, ll j) {
  return 0<=i && i< N && 0<=j && j<N && !a[i][j];
}
bool isvisitable(ll cx, ll cy) {
  range(i, N) {
    range(j, N) {
      if (a[i][i] == 0) {
        ll valid = false;
        for(auto move: moves) {
          ll i2 = i + move[0], j2= j + move[1];
          if (c(i2, j2) || (i + move[0] == cx && i + move[1] == cy) ) {
            valid = true;
          }
        }
        if (!valid) {
          return 0;
        }
  
      }
    }
  }
  return 1;
}
ll degree(ll i, ll j) {
  ll d = 0;
  for(auto move: moves) {
    ll i2 = i + move[0], j2 = j + move[1];
    if (c(i2, j2)) {
      d++;
    }
  }
  return d;
}

void dfs(ll i, ll j, ll depth = 1) {
  a[i][j] = depth;
  if (depth == N * N) {
    range(i, N) {
      range(j,N) {
        cout << a[i][j] << " ";
      }
      cout << '\n';
    }
    exit(0);
  }
  // debug(i, j, depth);
  vector <array<ll,2>> points;
  for(auto move: moves) {
    ll i2 = i + move[0], j2 = j + move[1];
    if (c(i2, j2)) {
      points.push_back({i2, j2});
    }
  }
  sort(all(points), [] (auto a, auto b) {
    return degree(a[0], a[1]) < degree(b[0], b[1]);
  });
  for(auto point: points) {
    dfs(point[0], point[1], depth + 1);
  }
  
  a[i][j] = 0;
}

void init() {
  cin >> x >> y ;
  x--;y--;
  swap(x, y);
  dfs(x, y);
}

void solve() {

}

int main(void) {
  #ifdef LOCAL
  freopen("in", "r", stdin); 
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  init();
  return 0;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
    // cout << "Case #" << tt + 1 << ": ";
}