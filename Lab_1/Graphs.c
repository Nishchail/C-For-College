#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];

void initializeMatrix(int vertices){
    for(int i = 0 ; i < vertices ; i++){
        for(int j = 0 ; j < vertices ; j++){
            adj[i][j] = 0;
        }
    }
}

void printMatrix(int vertices){
    for(int i = 1 ; i <= vertices ; i++){
        for(int j = 1 ; j <= vertices ; j++){
            printf("%d " , adj[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int vertices , edges ;

    printf("enter the number of vertices ");
    scanf("%d" , &vertices );

    printf("enter the number of edges ");
    scanf("%d" , &edges );

    initializeMatrix(vertices);

    for(int i = 0 ; i < edges ; i++){
        int source , destination ;
        printf("enter the source and destination of edge %d " , i+1);
        scanf("%d %d" , &source , &destination);
        adj[source][destination] = 1;
    }

    printMatrix(vertices);

}