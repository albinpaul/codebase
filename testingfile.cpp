#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#ifdef DEBUG
#include "debug.hpp"
#endif
#define watch(x) cerr << #x << " is " << x << ' '

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
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
			cerr << i << " -> " << suffixarray[i] << " " << inputstring.substr(suffixarray[i]) << '\n';
		}
		cerr << '\n';
	}
	void lcparrayoutput(){
		for(int i=0;i<suffixarray.size();i++){
			cerr << i << " -> " << lcp[i] <<" "<< inputstring.substr(suffixarray[i]) << '\n';
		}
		cerr << '\n';
	}
};

int length,a,b;
string input;
vector <int> reverseindex;
vector <int> dp;
int getx(const Suffixarray &sr,int index) {
	return (index == 0) ? 0 : (sr.suffixarray[index -1] - sr.suffixarray[index] >=1) ? min( sr.lcp[index - 1] , sr.suffixarray[index -1] - sr.suffixarray[index] ) : 0 ;
}
int getvalue(const Suffixarray &sr, int index) {


	int x = getx(sr,index);
	if (index != 0) {
		int lcpx = sr.lcp[index - 1];
		int xindex = index;
		while(xindex >= 1 && sr.lcp[xindex - 1] >= lcpx) {
			x = max( x,(sr.suffixarray[xindex - 1] - sr.suffixarray[index] >= 1)? min(sr.lcp[index - 1] , sr.suffixarray[xindex - 1] - sr.suffixarray[index] ) : 0) ;
			xindex--;
		} 
	}
	int y = (index >= length - 1) ? 0 : (sr.suffixarray[index + 1] - sr.suffixarray[index] >=1) ? min( sr.lcp[index] , sr.suffixarray[index + 1] - sr.suffixarray[index] ) : 0  ;
	
	return  max(x,y) ;	
}
int getstring(const Suffixarray &sr, int index) {
	if (index < length) {
		if (dp[index] != -1) {
			return dp[index];
		}
		int rindex = reverseindex[index];
		int lcpvalue = getvalue(sr,rindex);
		int answer = numeric_limits <int> :: max();
		for(int i=1 ; i<=lcpvalue ; i++ ) {
			answer = min(answer , b + getstring(sr,index + i) );
		}
		if (lcpvalue == 0 || a < b) {
			answer = min(answer , a + getstring(sr,index + 1) );
		}
		
		watch(rindex);watch(index);watch(lcpvalue);watch(answer);watch(sr.inputstring[index]);cerr << endl;
	
		dp[index] = answer ;
		return answer ;
	} else {
		return 0;
	}
}


void solve(int testcase){
	cin >> length >> a >> b;
	cin >> input;
	// cerr << input << endl;
	reverse(input.begin(),input.end());
	Suffixarray sr(input);
	sr.kasaiutil();
	sr.suffixarrayoutput();
	sr.lcparrayoutput();
	vector <int> reverseind(length);
	for(int i=0;i<sr.suffixarray.size();i++) {
		reverseind[sr.suffixarray[i]] = i;
	}
	reverseindex = reverseind;
	dp.resize(length);
	fill(dp.begin(),dp.end(),-1);
	cout << getstring(sr,0) << '\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt ;
	cin >> tt;
	tt =1;
	for(int t=0;t < tt;t++ ) {
		solve(t);
	}
	
	return 0;
}
