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
typedef vector<long> vi;
void init();
void solve();
void recursive();
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
const long N=(long)100;
bool ar[N];
vector <int> primes;
vector<vector <int>> graph;

void solve(){
    init();   
}
void recursive(int index,vector <int > current){
    
    for(int j=0;j<current.size();j++){
        vector <int> vertexes;
        for(int k=0;k<graph[j].size();k++){
            vertexes.push_back(graph[j][k]);
        }
        recursive(index+1,vertexes);
    }
}

void init(){
    ar[0]=1;
    ar[1]=1;
    for(int i =2;i*i<N;i++){
        if(ar[i]==0){
            for(int j=2*i;j<N;j+=i){
                ar[j]=1;
            }
        }
    }
    for(int i =0;i<N;i++){
        if(ar[i]==0){
            primes.emplace_back(i);
        }
    }
    graph.resize(primes.size());
    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            stack <short> s1;
            stack <short> s2;
            long long a = primes[i];long long b=primes[j];
            while(a){
                s1.push(a%10);
                a/=10;
            }
            while(b){
                s2.push(b%10);
                b/=10;
            }
            a = primes[i];b=primes[j];
            while(!s2.empty()){
                a=10*a+s2.top();
                s2.pop();
            }
            while(!s1.empty()){
                b=10*b+s1.top();
                s1.pop();
            }
            if(a>N || b>N){
                continue;
            }
            if(ar[a]==0 && ar[b]==0){
                graph[i].push_back(j);
                graph[j].push_back(i);
                
            }
        }
    }
}