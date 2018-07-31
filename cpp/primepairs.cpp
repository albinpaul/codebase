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
const long inputsize = 1000000;
bool ar[inputsize];
vector <int> primes;
const ostream & operator << (const ostream & out,set<int>&s){

    for(auto &it : s){
        cout<<primes[it]<<" ";
    }cout<<endl;

} 
long mm=0;
void dfs(set <long> graph[],bool visited[] ,int index,set<int> &s){
    if(!s.empty()){
        for(auto it = s.begin();it!=s.end();it++){
            if(graph[index].find(*it)==graph[index].end()){
                return;
            }
        }
    }
   
    s.insert(index);
    if(s.size()>mm){
        mm=s.size();
        cout<<"THe set is "<<endl;
        cout<<s;
    }
    visited[index]=1;
   // watch(index);cout<<endl;
    for(auto it = graph[index].begin();it!=graph[index].end();it++){

        if(visited[*it]==0){
           // watch(graph[index][i]);
            dfs(graph,visited,*it,s);
        }
    }
    //visited[index]=0;
    
    s.erase(index);
}
void customdfs(set <long> graph[]){
    bool visited[primes.size()] ;
    memset(visited,0,sizeof(visited));
    set <int> s;
    for(int i =0;i<primes.size();i++){    
        if(graph[i].size()>0 ){
            dfs(graph,visited,i,s);
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
    
    int numberofprimes = primes.size();
    set <long> graph[numberofprimes];

    for(int i=0;i<numberofprimes;i++){
        
        for(int j=i+1;j<numberofprimes;j++){
            
            long long a=primes[i],b=primes[j];
            stack <int> s1;
            stack <int> s2;
            long long temp = primes[i];
            while(temp){
                s1.push(temp%10);
                temp/=10;
            }
            temp=primes[j];
            while(temp){
                s2.push(temp%10);
                temp/=10;
            }
            
            
            while(!s1.empty()){
                b=b*10+(s1.top())%10;
                s1.pop();
            }

            while(!s2.empty()){
                a=a*10+(s2.top())%10;
                s2.pop();
            }
           
            if(a>=inputsize  || b>=inputsize){
                continue;
            }
           
            if(ar[a]==0 && ar[b]==0){
                
                assert(primes[i]<inputsize && primes[j]<inputsize);
                
                graph[i].insert(j);
                graph[j].insert(i);
                //watch(a);watch(b);
            }

        }
    }

  
  

    customdfs(graph);

}