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

    void fun()
    {
        string source;
        cin >> source ;
        string t="hello";
        int j=0;
        for(int i =0;i<source.size();i++){
            if(source[i]==t[j]){
                j++;
            }
            if(j == t.size()){
                break;
            }
        }
        if(j==t.size()){
            cout<<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }
void foo(){
    string t;
    cin >> t; 
    int flag=0;
    for(int i =0;i < t.size() ; i++){
        if (t[i] == 'H' || t[i] == 'Q' || t[i] == '9')
        {
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}

    int main(int argc, char const *argv[])
    {
        ios::sync_with_stdio(false);

        std::cin.tie(0);

        foo();

        return 0;
    }