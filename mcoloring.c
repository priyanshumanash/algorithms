#include<stdio.h>
int x[50][50], y[50];

void next_color(int k){
   int i,j;
   y[k]=1; 
   for(i=0;i<k;i++){ 
     if(x[i][k]!=0 && y[k]==y[i])  
       y[k]=y[i]+1;  
   }
}

int main(){
	int i, j, v, e, p, q;
	printf("Enter the no. of vertices: ");
	scanf("%d", &v);
	printf("Enter the no. of edges: ");
	scanf("%d", &e);

	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			x[i][j]=0;
		}
	}

	printf("Enter the indices of which value is 1->");
	for(i=0; i<e; i++){		
	scanf("%d %d", &p, &q);
	x[p][q]=1;
	x[q][p]=1;
	}
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			printf("\n%d",x[i][j]);
		}
	}
	
	for(i=0; i<v; i++){		
		next_color(i);
	}
	printf("\nThe color of vertices are:\n");
	for(i=0; i<v; i++){		
		printf("Vertex[%d] : %d\n",i+1,y[i]);
	}
	return 0;
}
