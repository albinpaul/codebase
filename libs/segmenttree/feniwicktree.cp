template <typename T = uint64_t>
class fenwicktree {
 public:
  void debugTree() {
    for (auto it : tree) {
      cout << it << " ";
    }
    cout << endl;
  }
  fenwicktree(int num) : n(num + 1) {
    tree.resize(n, 0);
  }
  
  void insert(T i, T delta) {
    #ifdef LOCAL
      assert(1<= i && i<=n);
    #endif
    for (; i <= n; i += i&-i) {
      tree[i] += delta;
    }
  }
  
  T get(int i) {
    T sum = 0;
    #ifdef LOCAL
      assert(1<= i && i<=n);
    #endif
    for (; i > 0; i -= i&-i) {
      sum += tree[i];
    }
    return sum;
  }
  
  T get(int l, int r) {
    return get(r) - get(l - 1);
  }
  
  private:
    vector<T> tree;
    int n;

};


