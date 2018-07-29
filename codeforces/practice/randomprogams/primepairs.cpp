#include <bits/stdc++.h>
const long N = (long) 1.1e6 ;
bool ar[N];
vector <int> primes;
int dp[N];
int main(){

    ar[0]=1;ar[1]=1;
    for(long i=2;i*i<N;i++){
        if(ar[i]==0){

            for (long j=2*i;j<N;j+=i)
            {
                ar[j]=1;   
            }
        }
    }
    for(int i=0;i<N;i++){
        if(ar[i]==0){
            primes.emplace_back(i);
        }
    }


    for(int i =0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            int a = primes[i];
            int b= primes[j];
            int c=a;
            int d=b;
            stack <int> s1;
            while(c){
                s1.push(c%10);
                c/=10;
            }
            stack <int> s2;
            while(d){
                s2.push(d%10);
                d/=10;
            }

            while(!s1.empty()){
                int t=s1.top();
                b = 10*b+t;
                s1.pop();
            }
            while(!s2.empty()){
                int t=s2.top();
                a = 10*a+t;
                s2.pop();
            }

            if(b>=N || a>=N){
                cout << "extend the prime number array "<<endl;
                //return 0;
                continue;
            }

            

            
            
        }
    }


    return 0;
}