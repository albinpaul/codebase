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

void solve();



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


const long int N=10000000;
long long ar[N+1];
void insert(long index){
    while(index<=N){
        ar[index]+=1;
        //watch(index);
        index+=(index&(-index));
    }
}
long query(long index){
    long sum=0;
    while(index>0){
        sum+=ar[index];
        index-=(index&(-index));
    }
    return sum;
}
void solve()
{ 
   
 int t;
 cin >>t;
 while(t--){
    long n;
    memset(ar,0,sizeof(ar));
    cin>>n;
//watch  (n);
    long long  count=0;
    for(long  i=0;i<n;i++){
        long temp;
        cin >>temp;
        insert(temp);
       count+=i+1-query(temp); 
    }
    cout<<count<<endl;
 }

}
