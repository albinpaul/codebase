using namespace std;
struct Suffixarray {
	struct myTuple {
		int originalIndex;
		int firstHalf;
		int secondHalf;
		bool operator < (myTuple T) {
			if (firstHalf == T.firstHalf) return secondHalf < T.secondHalf;
			else return firstHalf < T.firstHalf; 
		}
	};
	string inputstring;
	Suffixarray (string input):inputstring(input) {
	}
	vector <int> getSuffixArray () {
		int n = inputstring.size();
		vector <int> rank(n);
		for(int i=0 ; i < n ; i++){
			rank[i] = inputstring[i] - 'a';
		}
		myTuple L[n];
		for(int cnt = 1 ; cnt < n ; cnt *= 2) {
			for(int i = 0 ; i < n ; i++ ){
				L[i].firstHalf = rank[i];
				L[i].secondHalf = i + cnt < n ? rank[i + cnt] : -1 ;
				L[i].originalIndex = i; 
			}
			sort(L,L + n);
			vector <int> newrank(n);
			newrank[L[0].originalIndex] = 0;
			for(int i = 1,currRank = 0; i < n; ++i) {
				if (L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf ){
					++currRank;
				}
				newrank[L[i].originalIndex] = currRank;
			}
		}
		vector <int> result(n);
		for(int i=0;i<n;i++){
			result[i] = L[i].originalIndex;
		}
		return result;
	}
};