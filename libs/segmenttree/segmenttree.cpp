
template <class T>
struct Segtree {
	public:
		Segtree(int n, 
				function<T(T&, T&)> segmentTreeTypeFunction,
				function<T(T&, T&)> updateApplyFunction,
				T baseCase): 
			n(n), segmentTreeTypeFunction(segmentTreeTypeFunction),
			updateApplyFunction(updateApplyFunction), baseCase(baseCase)
		{
			tree = lazy = vector <T> (n << 2, baseCase);
		}
		
		void push_down(int idx, int start, int end) {
			if(lazy[idx] == baseCase) {
				return;
			}
			tree[idx] = segmentTreeTypeFunction(tree[idx], lazy[idx]);
			int LEFT = idx << 1;
			int RIGHT = LEFT | 1;
			if(start != end) {
				lazy[LEFT] = segmentTreeTypeFunction(lazy[LEFT], lazy[idx]);
				lazy[RIGHT] = segmentTreeTypeFunction(lazy[RIGHT], lazy[idx]);
			}
			lazy[idx] = baseCase;
		}
		void updateLazy(int idx, int start , int end, int l, int r, T& p) {
			push_down(idx, start, end);
			if(r < start || end < l) {
				return;
			}
			if(l <= start && end <= r) {
				lazy[idx] = segmentTreeTypeFunction(lazy[idx], p);
				push_down(idx, start, end);
				return;
			}
			int LEFT = idx << 1;
			int MID = (start + end) >> 1;
			int RIGHT = LEFT | 1;
			updateLazy(LEFT, start, MID, l, r, p);
			updateLazy(RIGHT, MID + 1, end, l, r, p);
			tree[idx] = segmentTreeTypeFunction(tree[LEFT], tree[RIGHT]);
		}

		T queryLazy(int idx, int start, int end, int l, int r) {
			push_down(idx, start, end);
			if(r < start || end < l) {
				return baseCase;
			}
			if(l <= start && end <= r) {
				return tree[idx];
			
			}
			int LEFT = idx << 1;
			int MID = (start + end) >> 1;
			int RIGHT = LEFT | 1;
			T leftValue = queryLazy(LEFT, start, MID, l, r); 
			T rightValue = queryLazy(RIGHT, MID + 1, end, l, r);
			return segmentTreeTypeFunction(
				leftValue, rightValue
			);
		}
		T queryLazy(int l, int r) {
			#ifdef LOCAL
				assert(0<=l && l<n);
				assert(0<=r && r<n);
			#endif
			return queryLazy(1, 1, n, l, r);
		}
		
		void updateLazy(int l, int r, T& p) {
			#ifdef LOCAL
				assert(0<=l && l<n);
				assert(0<=r && r<n);
			#endif
			updateLazy(1, 1, n, l, r, p);
		}
		

		//non-lazy version
		void update(int idx, int start, int end, int l, int r, T& p) {
			if(r < start || end < l) {
				return;
			}
			if(l <= start && end <= r) {
				tree[idx] = updateApplyFunction(tree[idx], p);
				return;
			}
			int LEFT = idx << 1;
			int MID = (start + end) >> 1;
			int RIGHT = LEFT | 1;
			update(LEFT, start, MID, l, r, p);
			update(RIGHT, MID + 1, end, l, r, p);
			tree[idx] = segmentTreeTypeFunction(tree[LEFT], tree[RIGHT]);
		}

		T query(int idx, int start, int end, int l, int r) {
			if(r < start || end < l) {
				return baseCase;
			}
			if(l <= start && end <= r) {
				return tree[idx];
			}
			int LEFT = idx << 1;
			int MID = (start + end) >> 1;
			int RIGHT = LEFT | 1;
			T leftValue = query(LEFT, start, MID, l, r); 
			T rightValue = query(RIGHT, MID + 1, end, l, r);
			return segmentTreeTypeFunction(
				leftValue, rightValue
			);
		}
		T query(int l, int r) {
			#ifdef LOCAL
				assert(1<=l && l<=n);
				assert(1<=r && r<=n);
			#endif
			return query(1, 1, n, l, r);
		}
		
		void update(int l, int r, T& p) {
			#ifdef LOCAL
				assert(1<=l && l<=n);
				assert(1<=r && r<=n);
			#endif
			update(1, 1, n, l, r, p);
		}


		void display(){
			cerr << "tree";
			for(T item: tree){
				cerr << item << ' ';
			} cerr << '\n';
			cerr << "lazy";
			for(T item: lazy){
				cerr << item << ' ';
			}cerr << '\n';
		}
	private:
		int n;
		vector <T> lazy, tree;
		function<T(T&, T&)> segmentTreeTypeFunction;
		function<T(T&, T&)> updateApplyFunction;
		T baseCase;
};

struct TreeNode{
	int a, b, c;
	bool operator==(TreeNode &item){
		return item.a == this->a && item.b == this->b && item.c == this->c;
	}
};

ostream& operator<< (ostream &out, const TreeNode &item){
	out << "{" << item.a << ","<< item.b << "," << item.c << "}";
	return out;
}

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	TreeNode base = {0, 0, 0};
	Segtree <TreeNode> segTree(n, [](TreeNode &l, TreeNode &r) -> TreeNode {
		TreeNode parent;
		int t = min(l.b, r.c);
		parent.a = l.a + r.a + t;
		parent.b = l.b + r.b - t;
		parent.c = l.c + r.c - t;
		return parent;
	},[](TreeNode &treeitem, TreeNode &value) -> TreeNode {
		return value;
	}, base);
	for(int i=1;i<=n;i++){
		TreeNode item = {0, 0, 0};
		if (s[i-1] == '('){
			item.b++;
		}else {
			item.c++;
		}
		segTree.update(i, i, item);
	}
	// segTree.display();
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int l, r;
		cin >> l >> r;
		TreeNode ans = segTree.query(l, r);
		cout << 2* ans.a << '\n';

	}
	
}
