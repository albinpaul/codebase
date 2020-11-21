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
  ll n, k;
  cin >> n >> k;
  vector <ll> a(n);
  range(i, n) {
    cin >> a[i];
  }
  multiset <int> left_heap, right_heap;
  ll left_sum = 0, right_sum = 0;
  auto rebalance = [&] () {
    // leftheap == rightheap || leftheap == rightheap + 1
    while(left_heap.size() < right_heap.size()) {
      auto it = right_heap.begin();
      left_sum += *it;
      right_sum -= *it;
      left_heap.insert(*it);
      right_heap.erase(it);
    }

    while(! (right_heap.size() == left_heap.size() || 
             right_heap.size() + 1 == left_heap.size()) ) {
      auto it = prev(left_heap.end());
      left_sum -= *it;
      right_sum += *it;
      right_heap.insert(*it);
      left_heap.erase(it);
    }    
  };
  range(i,k) {
    right_heap.insert(a[i]);
    right_sum += a[i];
  }
  rebalance();
  debug(a,left_heap,right_heap,left_sum, right_sum);
  
  ll median =  *prev(left_heap.end()) ;
  cout <<( ((ll)left_heap.size() - (ll)right_heap.size()) * median - left_sum + right_sum ) << ' ';
  for(int i=k;i<n;i++) {
    if (left_heap.empty() || a[i] <= *prev(left_heap.end())) {
      left_heap.insert(a[i]); 
      left_sum += a[i];
    } else {
      right_heap.insert(a[i]);
      right_sum += a[i];
    }

    bool deleted = false;
    auto it = right_heap.find(a[i-k]);
    if (it!= right_heap.end()) {
      right_heap.erase(it);
      right_sum -= *it;
      deleted = true;
    }
    it = left_heap.find(a[i-k]);
    if (!deleted && it!= left_heap.end()) {
      left_heap.erase(it);
      left_sum -= *it;
      deleted = true;
    }
    assert(deleted);
    
    rebalance();
    debug(left_heap, right_heap, left_sum, right_sum);
    cout << ((ll)left_heap.size() - (ll)right_heap.size()) * *prev(left_heap.end()) - left_sum + right_sum  << ' ';

  }
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