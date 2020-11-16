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

multiset <int> answer;
ll n,s;

vector <ll> a;

bool check(int start, int target ,int k) {
  if (start == n || target < a[start]*k || target > (a.back()) *k)
    return false;

  debug(start,target,k,a[start], n);
  if (k == 2) {
    
    int lo = start, hi = n - 1;
    while (lo < hi) {
      int sum = a[lo] + a[hi];
      if (sum < target || (lo > start && a[lo] == a[lo - 1]))
          ++lo;
      else if (sum > target || (hi < n - 1 && a[hi] == a[hi + 1]))
          --hi;
      else {
        answer.insert(a[lo]);
        answer.insert(a[hi]);
        return true;
      }
    }
   
    return false;
  }
  
  for(int i=start;i<n;i++) {
     debug(i,start,k);
 
    if (i == start || a[i] != a[i - 1]) {
      debug(i,a[i],k);
      bool status = check(i + 1, target - a[i], k - 1);
      if (status) {
        answer.insert(a[i]);
        return status;
      }
    }
  }
  return false;
}

void init() { 
  cin >> n >> s;
  a.resize(n);  
  range(i,n) {
    cin >> a[i];
  }
  vector <ll> copy;
  copy = a;
  sort(all(a));
  bool status =check(0,s,4);
    debug(answer,a);
  
  if (status) {
    range(i,n) {
      if (!answer.empty()) {
        auto it = answer.find(copy[i]);
        if (it != answer.end()) {
          cout << i + 1 << " ";
          answer.erase(it);
        }
      }
    }
  }
  else
  cout << "IMPOSSIBLE\n";

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