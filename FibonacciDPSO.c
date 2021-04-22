#include<stdio.h>
int fibBUSO(int n); 
int main(){
    int ans, n=7;
    ans=fibBUSO(n);
    printf("FIB(%d)=%d", n, ans);
    return 0;
 }
// We have not used an array to store the previous two values to be added here instead we're only 
//working with primary focus i.e., the previous two values.
 int fibBUSO(int n){
     int a,b,c;
     if(n==0 || n==1){
         return n;
     }
     a=0;
     b=1;
     for(int i=2; i<n; i++){
         c=a+b;
         a=b;
         b=c;
     }
     return c;
 }