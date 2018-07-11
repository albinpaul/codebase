#include <stdio.h>
#include <string.h>
int main(){
    // this program only considers lowercase strings 
    char *s = "india is my country";
    int lengthofstring =  sizeof(s)/sizeof(s[0]);
    int buff[26];
    memset(buff,0,sizeof(int)*26);
    for(int i =0;i<lengthofstring;i++){
        buff[s[i]-'a']+=1;
    }
    for(int i =0 ; i<26; i++){
        if(buff[i] >=2){
            printf("%c %d\n",(char)(i+'a'),buff[i]);
        }
    }

    return 0;
}