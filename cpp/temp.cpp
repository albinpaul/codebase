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
const long long N=(long long )7000000;
//const long N = (long)  2000;
bool ar[N];
vector <int> primes;
vector <int> degrees;
unordered_map <int,int> um;
vector<set<int>> graph;
vector <int> isdisabled;
const int degree =4; 

ostream & operator << (ostream & out , set <int> &s){
    out<<"{ ";
    for(auto it =s.begin();it!=s.end();it++){
        out<<primes[*it]<<" ";
    }out<<"} ";
    return out;
}


void show(){
    //helper function
    cerr<<"current graph"<<endl;    
    for(int i=0;i<graph.size();i++){
        if(graph[i].size()>0){
            watch(degrees[i]);
            watch(primes[i]);
            cerr<<graph[i]<<endl;
            
        }
    }
    
}
void modifiedshow(){
    cerr<<"modified graph"<<endl;
    for(int i =0;i<graph.size();i++){
        if(degrees[i]>=degree){
            watch(degrees[i]);
            watch(primes[i]);
            cerr<<graph[i]<<endl;
        }
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
    for(int i =2;i<N;i++){
        if(ar[i]==0){
            primes.emplace_back(i);
            um.insert({i,primes.size()-1});
            isdisabled.emplace_back(0);
           
        }
    }

    graph.resize(primes.size());
    degrees.resize(primes.size(),0);
    cerr<<"primes found - constructing graph "<<endl;
    watch(degree);cerr<<endl;
    for(int i=0;i<primes.size();i++){
        long long a =primes[i],b=0L;
        long poweroften =1;
        while(a){
            b=b+((a%10)* poweroften);
             a/=10;
            poweroften*=10;
          
           
            if(a<N && b<N && ar[a]==0 && ar[b]==0){
            
                auto it1=um.find(a);
                auto it2=um.find(b);    
                
                if(it1!=um.end() && it2!=um.end() && graph[it1->second].find(it2->second)==graph[it1->second].end())
                {
                    
                    long long tempa = a,tempb=b;
                    stack <short> s;
                    int index=0;
                    while(tempa){
                        index++;
                        tempa/=10;
                    }
                    tempb=tempb*(pow(10,index));
                    tempb+=a;
                    
                    if(tempb < N && ar[tempb]==0){
                       
                        
                        if(it1->second <degrees.size() && it2->second<degrees.size()){
                             watch(primes[i]);
                            watch(tempb);watch(a);watch(b);cerr<<endl;
                            graph[it1->second].insert(it2->second);
                            graph[it2->second].insert(it1->second);
                            degrees[it1->second]++;
                            degrees[it2->second]++;
                        }else{
                            cerr<<"error in degree vector"<<endl;
                        }
                    }
                    
                }

                
            }
           ;
            
        } 
    }
    
   

}
void clean()
{
    int changed = 0;
    do{
        changed=0;
        for(int i=0;i<graph.size();i++){

            if(  graph[i].size()<degree && isdisabled[i]==0){
                degrees[i]=0;
                isdisabled[i]=1;
                changed=1;
                for(auto it = graph[i].begin();it!=graph[i].end();it++){
                    if(isdisabled[*it]==0)
                        degrees[*it]--;
                }
            }
        }
    }while(changed==1);
}
set <int>  setunion(set <int > &a,set <int> &b )
{
    set <int> result ;
    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(result,result.begin()));
    return result;
}
set <int>  setdifference(set <int > &a,set <int> &b )
{
    set <int> result ;
    set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(result,result.begin()));
    return result;
}
set <int>  setintersection(set <int > &a,set <int> &b )
{
    set <int> result ;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(result,result.begin()));
    return result;
}



void fiveloops(){
    int a[5];
    for( a[0]=0;a[0]<primes.size();a[0]++)
    {
        if(degrees[a[0]]>=degree){
            for( a[1]=a[0]+1;a[1]<primes.size();a[1]++)
            {
                if(degrees[a[1]]>=degree){
                    for( a[2]=a[1]+1;a[2]<primes.size();a[2]++){
                        
                        if(degrees[a[2]]>=degree){
                            for( a[3]=a[2]+1;a[3]<primes.size();a[3]++){
                                
                                if(degrees[a[3]]>=degree)
                                for( a[4]=a[3]+1;a[4]<primes.size();a[4]++){
                                    
                                    if(degrees[a[4]]>=degree){
                                        int condition =1;
                                        for(int i=0;i<5;i++){
                                            for(int j=0;j<5;j++){
                                                if(i==j){
                                                    continue;
                                                }
                                                condition = condition && (graph[a[i]].find(a[j])!=graph[a[i]].end());
                                                if(condition==0){
                                                    break;
                                                }
                                            }
                                            if(condition==0){
                                                break;
                                            }
                                        }
                                        //cerr<<primes[a[0]]<<" "<<primes[a[1]]<<" "<<primes[a[2]]<<" "<<primes[a[3]]<<" "<<primes[a[4]]<<" "<<endl;
                                        if(condition==1)
                                        {
                                            for(int i =0;i<5;i++){
                                                cout<<primes[a[i]]<<" ";
                                            }cout<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void dumpprimes(){
    fstream f;
    f.open("primes.txt",ios::out|ios::in|ios::trunc);
    for(int i=0;i<primes.size();i++){
        f<<primes[i]<<"\n";
    }
    f.close();
}

void solve(){
    init();
    dumpprimes();
    show();
    clean();
    modifiedshow();
    fiveloops();

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
