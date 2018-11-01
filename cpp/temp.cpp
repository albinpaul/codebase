#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (long i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x)<<" "
#define debug() cerr << "running till line " << __LINE__ << " in function " << __func__ << endl
const double PI = 3.141592;
const long inf = (long)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;
const long long N=(long long )10000;
vector <int> polygonal[6];
unordered_map <int,vector<int>> um[6];
unordered_map <int,int> rememberingindex[6];

int fun1(int a){
    return (a*(a+1))/2;
}
int fun2(int a){
    return (a*a);
}
int fun3(int a){
    return (a*(3*a-1))/2;
}
int fun4(int a){
    return a*(2*a-1);
}
int fun5(int a){
    return (a*(5*a-3))/2;
}
int fun6(int a){
    return (a*(3*a-2));
}

ostream & operator<< (ostream & out,vector <int> &vec){
    out<<"[";
    for(auto it =vec.begin();it!=vec.end();it++){
        out<<*it;
        if((it+1)!=vec.end()){
            out<<",";
        }
    }
    out<<"]";
    return out;
}

ostream & operator<< (ostream & out,vector <pair<int,int>> &vec){
    out<<"[";
    for(auto it =vec.begin();it!=vec.end();it++){
        out<<"["<<it->first<<","<<it->second<<"]";

        if((it+1)!=vec.end()){
            out<<",";
        }
    }
    out<<"]";
    return out;
}
void init(){
    
}

void solve(){
    init();
    
}


 

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    #ifdef _DEBUG
        long tt = clock();
    #endif
        solve();
    #ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
    #endif
}
