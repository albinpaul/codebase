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
// prefix function for the knuth morris patt matching algorithm
vector <int > prefix_function(string s){
    size_t stringlength= s.size();
    vector <int> pre(stringlength,0);
    pre[0]=0;
    int j=0;
    for(int i =1;i<stringlength;i++){
        while(j>=0 && s[j]!=s[i]){
            if(j>=1){
                j=pre[j-1];
            }else{
                j=-1;
            }
        }
        j++;
        pre[i]=j;
    }
    return pre;
}


void solve()
{ 
    string s;    
    cin >>s ;
    int flag=1;
    vector <int> p = prefix_function(s);
    int n = s.size();
    if(p[n-1]==0){
        cout<<"Just a legend"<<endl;
        return ;
    }  
    int ans = 0;
 
    for(int i =0;i<n-1;i++){
        if(p[i]==p[n-1]){
            ans=1;
        }

    }
    if(ans==1){
        for(int i =0;i<p[n-1];i++){
            cout<<s[i];
        }cout<<endl;
        return ;
    }


    // if(p[p[n-1]]==0){
    //      cout<<"Just a legend"<<endl;
    //     return ;
    // }



}
