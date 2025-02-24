#include <stdio.h>

#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n ;
int stack[MAX];
int top = -1;

void dfs(int v ){
    visited[v] = 1;
    for(int i = 0 ; i < n ;i++ ){
        if(adj[v][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }

    stack[++top]  = v;
}

void topologicalSort(){
    for(int i = 0 ; i < n ; i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }
}


void main(){
    int i , j ;
    printf("Enter the number of vertices : ");
    scanf("%d" , &n);
    
    printf("Enter the adjacency matrix : \n");
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d" , &adj[i][j]);
        }
    }

    for(i = 0 ; i < n ; i++){
        visited[i] = 0;
    }

    topologicalSort();

    printf("The topological order is : ");
    for(i = top ; i >= 0 ; i--){
        printf("%d " , stack[i]);
    }
}