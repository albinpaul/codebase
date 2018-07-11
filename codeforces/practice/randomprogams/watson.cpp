#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) <<" "
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;
void solve();
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifdef _DEBUG
    int tt = clock();
#endif
    solve();
#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif
}
int n;
const int N=(int)1.1e5;
long long  ar[N];
long long forsumdp[N];
vector <long long > temp;
vector <long long > dp[N];
namespace seg {
    template <typename T>
    class segtree {
        vector <T> inputvector;
        vector <T> segmenttreevector;
        
        size_t sizes;
        T (*reqfunction)(T,T);
    public:
        void createtree(vector < T > input,T (*func)(T,T)){

            this->sizes=input.size();
            inputvector=input;
            reqfunction=func;
            segmenttreevector.resize((sizes+1)*log(sizes+1));
            this->build(0,0,this->sizes-1);
        }
        void build(T node ,T start ,T end){
            if(start == end ){
                segmenttreevector[node]=inputvector[start];
            }else{
                size_t mid = (start +end) /2 ;
                this->build(2* node +1,start ,mid);
                this->build(2*node+2,mid+1,end);
                segmenttreevector[node]=(*reqfunction)(segmenttreevector[2*node],segmenttreevector[2*node+1]);
            }
        }
        void update(size_t node , size_t start,size_t end , size_t idx , T val){
            if(start == end ){
                inputvector[idx]+=val;
                segmenttreevector[node]+=val;
            }else{
                size_t mid = (start +end)/2;
                if(start <= idx && idx <= end){
                    update(2* node ,start , mid,idx ,val);
                }else{
                    update(2*node+1,mid+1,end,idx,val);
                }
                segmenttreevector[node] = (*reqfunction)(segmenttreevector[2*node],segmenttreevector[2*node+1]);
            }
        }

        T query (size_t node , size_t start,size_t end , size_t l ,size_t r){
            if(r<start || end < l){
               return 0;
                
            }

            if(l<=start && end <=r){
                return segmenttreevector[node];
            }
            T mid = (start +end )/2;
            T p1= query(2*node,start ,mid,l,r);
            T p2= query(2*node,mid+1 ,end,l,r);
            return (*reqfunction)(p1,p2);
        }
    };
}

void solve()
{
    
    cin>>n;
    int summ=0;
    for(int i =0;i<n;i++){
        cin>>ar[i];
        summ+=ar[i];
    }
    forsumdp[0]=0;
    for(int i =0;i<n;i++){
        forsumdp[i+1]=forsumdp[i+1+n]=forsumdp[i]+ar[i];
        forsumdp[i+1+n]+summ;
    }
    
    int m;
    cin >>m;
    temp.resize(2*n);
    for(int i =0;i<2*n;i++){
        temp[i]=forsumdp[i];
        cout<<forsumdp[i]<<" ";
    }cout<<endl;
    //for(int i =0;i;)
    seg::segtree <long long>s;
    s.createtree(temp,[](long long a,long long b){
        return max(a,b);
    });
    for(int i =0;i<m;i++){
        long q;
        cin >>q;
        if(q==1){
            long x,w;
            cin >>x>>w;
        
        }
        if(q==2){
            
        }

    }   

}