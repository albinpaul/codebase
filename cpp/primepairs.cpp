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
const ostream & operator << (const ostream & out,set<int>&s){

    for(auto &it : s){
        cout<<it<<" ";
    }cout<<endl;

} 
long mm=0;
void dfs(set <long> graph[],bool visited[] ,int primenumber,set<int> &s){
    if(!s.empty()){
        for(auto it = s.begin();it!=s.end();it++){
            int flag=0;
            for(int j=0;j<graph[primenumber].size();j++){
                if (graph[primenumber][j]==*it){
                    flag=1;
                }
            }
            if(flag==0){
                return;
            }
        }
    }
   
    s.insert(primenumber);
    if(s.size()>mm){
        mm=s.size();
        cout<<"THe set is "<<endl;
        cout<<s;
    }
    visited[primenumber]=1;
   // watch(primenumber);cout<<endl;
    for(auto it = graph[primenumber].begin();it!=graph[primenumber];it++){

        if(visited[*it]==0){
           // watch(graph[primenumber][i]);
            dfs(graph,visited,*it,s);
        }
    }
    //visited[primenumber]=0;
    
    s.erase(primenumber);
}
void customdfs(set <long> graph[]){
    bool visited[inputsize] ;
    memset(visited,0,sizeof(visited));
    set <int> s;
    for(int i =0;i<primes.size();i++){    
        if(graph[primes[i]].size()>0 && ar[primes[i]]==0){
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
    set <long> graph[inputsize];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<numberofprimes;i++){
        for(int j=i+1;j<numberofprimes;j++){
  
            long long a=primes[i],b=primes[j];
            long long temp = primes[i];
            stack <int> s1;
            stack <int> s2;

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
            // watch(primes[i]);watch(primes[j]);cout<<endl;
            //watch(a);watch(b);cout<<endl;
            
            if(a>=inputsize || b>=inputsize){
                continue;
            }
           
            if(ar[a]==0 && ar[b]==0){
                
                graph[primes[i]].insert(primes[j]);
                graph[primes[j]].insert(primes[i]);
            }

        }
    }

    
    // for(int i =0;i<inputsize;i++){
    //     if(graph[i].size()>0){
    //         cout<<"i is "<<i<<" "; 
    //         for(int j=0;j<graph[i].size();j++){
    //             cout<<graph[i][j]<<" ";
    //         }cout<<endl;
    //     }
    // }

    customdfs(graph);

}