#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;

void swap(char &s, char &t){
    char m = s;
    s=t;
    t=m;
}
void foo()
{
    string s;
    cin>>s;

    stack <char> st;
    if (s.length()%2==0){
        for(int i =0 ;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                swap(s[i],s[j]);
               // st.clear();
                for(int k=0;k<s.length();k++){
                    
                }
                swap(s[j],s[i]);    
            }
        }
    }else{
        cout<< -1 <<endl;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    foo();
    return 0;
}