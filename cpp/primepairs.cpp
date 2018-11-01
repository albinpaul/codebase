#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr<<(#x)<<" is "<<x<<" "
#define debug() cerr<<"the error is at line no"<<__LINE__<<" in the file "<<__FILE__<<endl


const long n = 100000;
ostream & operator << ( ostream & out,set<long>&s){
    out<<"{ ";
    for(auto &it : s){
        out<<it<<" ";
    }out<<" }"<<endl;
    return out;
}
template <typename T>
ostream & operator << ( ostream & out,vector<T>&s){
    out<<"[ ";
    for(auto &it : s){
        out<<it<<" ";
    }out<<" ]"<<endl;
    return out;
} 

void solve(){
    
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}