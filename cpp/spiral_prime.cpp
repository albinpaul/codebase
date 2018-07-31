#include <bits/stdc++.h>

using namespace std;
const long N =(long)1.1e9;
bool ar[N];
long foo(long n,long i){
    i-=1;
    return n + (n-1)*i +(((i+1)*i)/2)*8;  
}
int main(){
    
    ar[0]=1;ar[1]=1;
    for(long i =2;i*i<N;i++){
        if(ar[i]==0){
            for(long j=2*i;j<N;j+=i){
                ar[j]=1;
            }
        }
    }   
    long count=1,prime=0;
    for(long i=1;i<1000000;i++){
        long long a =foo(3,i);
        long long b =foo(5,i);
        long long c =foo(7,i);
        long long d =foo(9,i);
        if(a>=N || b>=N || c>=N || d>=N  ){
            cout<<"Increase the size man"<<endl;
            break;
        }
        count+=4;
        if(ar[a]==0){
            prime+=1;
        }
        if(ar[b]==0){
            prime+=1;
        }
        if(ar[c]==0){
            prime+=1;
        }
        if(ar[d]==0){
            prime+=1;
        }
        if(prime/(count*1.0) <0.1){
            cout<<"The answer is "<<2*i+1<<endl;
            break;
        }
    }

    return 0;
}