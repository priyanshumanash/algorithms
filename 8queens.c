#include<stdio.h>
#include<stdbool.h>
#define N 8

bool possible(int a[][50], int, int);
bool solveNqueen(int a[][50], int);
void printQueens(int a[][50]){
    int r,c;
    char l;
    for(r=0; r<N; r++){
        for(c=0; c<N; c++){
            printf("%d (%d,%d)  ",a[r][c], r, c);
        }
        printf("\n");
    }
}

bool solveNqueen(int a[][50], int c){
    int r;
    if(c>=N){
        return true;
    }
   for(r=0; r<N; r++){
            if(possible(a, r, c)){
                a[r][c]=1;
                if(solveNqueen(a, c+1)){
                    return true;
                }
                a[r][c]=0;
            }
    }
    return false;
}



int main(){
    int a[50][50];
    int i,j,r, c;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            a[i][j]=0;
        }
    }
    printf("Given positions\n");
    for(r=0; r<N; r++){
        for(c=0; c<N; c++){
            printf("%d (%d,%d)  ",a[r][c], r, c);
        }
        printf("\n");
    }
    printf("Solved queens positions\n");
    if(solveNqueen(a, 0)){
            printQueens(a);
        }
        else
        {
            printf("Not possible here\n");
        }
        return 0;
}
    // for(c=0; c<N; c++){
    //     if(solveNqueen(a, c)){
    //         printQueens(a);
    //     }
    //     else
    //     {
    //         printf("Not possible here\n");
    //     }
        
    // }
    //  for(r=0; r<N; r++){
    //         a[r][0]=1;
    //         if(solveNqueen(a, 1)){
    //         printQueens(a);
    //         }
    //         else
    //         {
    //             printf("Not possible here\n");
    //         }
    //         a[r][0]=0;
    //     }
    

bool possible(int a[][50], int r, int c){
    int i, j;
    for(i=0; i<N; i++){
        if(a[r][i]==1){
            return false;
            }
    }
    for(i=0; i<N; i++){
        if(a[i][c]==1){
            return false;}
    }
    i=r, j=c;
    while(i>=0 && j>=0){
        if (a[i][j]==1){
            return false;}
        i-=1;
        j-=1;}
    i=r, j=c;
    while(i<N && j>=0){
        if (a[i][j]==1){
            return false;}
        i+=1;
        j-=1;}
        return true;
}
    // i=r, j=c;
    // while(i>=0 && j<N){
    //     if(a[i][j]==1){
    //         return false;}
    //     i-=1;
    //     j+=1;}
    // i=r, j=c;
    // while(i<N && j<N){
    //     if (a[i][j]==1){
    //         return false;}
    //     i+=1;
    //     j+=1;}
    