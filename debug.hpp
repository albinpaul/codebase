#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream & operator<<(ostream &out,vector <T> v){
	for(auto it:v){
		out<<it<<" ";
	}out<<endl;
	return out;
}

template <typename T1,typename T2>
ostream & operator<<(ostream &out, pair < T1,T2 > v){
	out<<"{"<<v.first<<","<<v.second<<"}";
	return out;
}

template <typename T1>
ostream & operator<<(ostream &out, unordered_set < T1 > v){
	for(auto it:v){
		out << it << " ";
	}
	return out;
}





