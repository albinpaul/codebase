#include <bits/stdc++.h>
using namespace std;



struct Suffixarray {
	struct myTuple {
		int originalIndex;
		int firstHalf;
		int secondHalf;
		bool operator < (myTuple T) {
			if (this->firstHalf == T.firstHalf) return this->secondHalf < T.secondHalf;
			else return this ->firstHalf < T.firstHalf; 
		}
	};
	string inputstring;
	vector <int> suffixarray;
	vector <int> lcp;
	Suffixarray (string input):inputstring(input) {
		int n = inputstring.size();
		suffixarray.resize(n);
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
			rank = newrank;
		}
		for(int i=0;i<n;i++){
			suffixarray[i] = L[i].originalIndex;
		}
	}
	void kasaiutil()
	{
		int n=inputstring.size(),k=0;
		lcp.resize(n);
		vector<int> rank(n,0);
		for(int i=0; i<n; i++) rank[suffixarray[i]]=i;
		for(int i=0; i<n; i++, k?k--:0)
		{
			if(rank[i]==n-1) {k=0; continue;}
			int j=suffixarray[rank[i]+1];
			while(i+k<n && j+k<n && inputstring[i+k]==inputstring[j+k]) k++;
			lcp[rank[i]]=k;
		}
	}
	vector <int> getlcparray() {
		kasaiutil();
		return lcp;
	}
	void suffixarrayoutput () {
		for(int i=0;i<suffixarray.size();i++){
			cerr << i << "->" << inputstring.substr(suffixarray[i]) << '\n';
		}
		cerr << '\n';
	}
	void lcparrayoutput(){
		for(int i=0;i<suffixarray.size();i++){
			cerr << i << "->" << lcp[i] <<" "<< inputstring.substr(suffixarray[i]) << '\n';
		}
		cerr << '\n';
	}
};