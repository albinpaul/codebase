#include <bits/stdc++.h> 
using namespace std;

vector <vector < int  > >v;
ostream & operator<<(ostream &out, vector <int> &vt){
    for(auto &it : vt){
        out<<it<<" ";
    }
    out<<endl;
    for(size_t i=0;i<vt.size();i++){
    	out<<i<<" ";
    }out<<endl;
    return out;
}
template<typename T>
class BITtree{
	
	public :
	vector <T> tree;
	size_t st;

	BITtree(vector<T> &input){
		this->tree.resize(input.size()+1);
		this->st=input.size();
		for(size_t i=0;i<input.size();i++){
			update(input[i],i);
		}
	}

	void update(T &n,size_t index){

		index+=1;
		while(index<=st){
			tree[index]+=n;
			index+=index&(-index);
		}
	}
	T rangedsum(size_t index){
		index+=1;
		T sum=0;

		while(index>0){
		
			sum+=this->tree[index];
			index-=(index&(-index));
		
		}
		return sum;
	}

};
int main(){
	vector <int> v{1,2,3,4};
	BITtree <int> b(v);
	cout<<b.tree<<endl;

	return 0;
}