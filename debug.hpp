#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream & operator<<(ostream &out,vector <T> v){
	int i=0;
	for(auto it:v){
		out<<(i++)<<" -> "<<it<<"\n";
	}out<< endl;
	return out;
}

template <typename T1,typename T2>
ostream & operator<<(ostream &out, pair < T1,T2 > v){
	out<<"{"<<v.first<<","<<v.second<<"}";
	return out;
}

// template <typename T1>
// ostream & operator<<(ostream &out, unordered_set < T1 > v){
// 	for(auto it:v){
// 		out << it << " ";
// 	}
// 	return out;
// }



// template <typename T1>
// ostream & operator<<(ostream &out, set< T1 > v){
// 	for(auto it:v){
// 		out << it << " ";
// 	}
// 	return out;
// }


// template <typename T1,typename T2>
// ostream & operator<<(ostream &out, unordered_map < T1,T2 > v){
// 	for(auto it:v){
// 		out <<"{"<< it.first << " " << it.second << "}\n";
// 	}
// 	return out;
// }

