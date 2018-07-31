#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr<<(#x)<<" is "<<x<<" "
#define debug() cerr<<"the error is at line no"<<__LINE__<<" in the file "<<__FILE__<<endl
void solve();
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}
const long inputsize = 10000;
bool ar[inputsize];
vector <int> primes;
void dfs(vector <int> graph[],bool visited[] ,int primenumber,set<int> s){
    s.insert(primenumber);
    visited[primenumber]=1;
    
}
void customdfs(vector <int> graph[]){
    long primesize = primes.size();
    bool visited[primesize] ;
    memset(visited,0,sizeof(visited));
    set <int> s;
    for(int i =0;i<primesize;i++){
        if(visited[i]==0){
            dfs(graph,visited,s);
        }
    }
}




void solve(){
    ar[0]=1;
    ar[1]=1;
    for(long i =2;i<inputsize;i++){
        if(ar[i]==0){
            for(int j=2*i;j<inputsize;j+=i){
                ar[j]=1;
            }
        }
    }
    for(int i=0;i<inputsize;i++){
        if(ar[i]==0){
            primes.emplace_back(i);
        }
    }
    //debug();
    int numberofprimes = primes.size();
    vector <long> graph[numberofprimes];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<numberofprimes;i++){
        for(int j=0;j<i;j++){
            
            long temp = primes[i];

            long long a=primes[i],b=primes[j];
            while(temp){
                b=b*10+(temp%10);
                temp/=10;
            }

            temp =  primes[j];
            while(temp){
                a=a*10+(temp)%10;
                temp/=10;
            }
            // watch(primes[i]);watch(primes[j]);cout<<endl;
            // watch(a);watch(b);cout<<endl;
            if(a>=inputsize || b>=inputsize){
                continue;
            }

            if(ar[a]==0 && ar[b]==0){
                graph[primes[i]].push_back(primes[j]);
                graph[primes[j]].push_back(primes[i]);
            }

        }
    }

    
    for(int i =0;i<numberofprimes;i++){
        if(graph[i].size()>0){
            cout<<"i is "<<i<<" "; 
            for(int j=0;j<graph[i].size();j++){
                cout<<graph[i][j]<<" ";
            }cout<<endl;
        }
    }



}