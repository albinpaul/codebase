template <typename T=int>
class SparseTable {
	public:
		SparseTable(const std::vector <T> &data, std::function <T(T&, T&)> f):
			f(f), data(data)
		{
			n = data.size();
			for (logSize = 1; (1 << logSize) <= n; logSize++)
				;
			sTable.resize(n, vector <T>(logSize, 0));
			for (int i = 0; i < n; i++)
			{ 	
				sTable[i][0] = data[i];
			}
			for (int j = 1; (1 << j) <= n; j++) {
				for (int i = 0; (i + (1 << j) - 1) < n; i++) {
					sTable[i][j] = f(sTable[i][j - 1], 
						sTable[i + (1 << (j - 1))][j - 1]);
				}
			}
		}	
		
		void display(){
			for(int i=0; i < n; i++){
				for(int k=0; k<logSize; k++){
					cout << sTable[i][k] << " ";
				} cout << '\n';
			}
		}

		T query(int L, int R){
			#ifdef LOCAL
				assert(0<= L && L < n);
				assert(0<= R && R < n && L <= R);
			#endif
			int j = (int)log2(R - L + 1);
			return f(sTable[L][j], sTable[R - (1 << j) + 1][j]);
		}

		static void example(){
			vector <T> d {6, 5, 4, 3, 2, 1};
			SparseTable s(d, [](T &a, T &b) -> T { 
				return min(a, b);
			});
			s.display();
			assert(s.query(1, 2) == 4);
		}

	private:
		int logSize;
		int n;
		std::function <T(T&, T&)> f;
		std::vector<std::vector<T>> sTable;
		std::vector <T> data;
	
};
