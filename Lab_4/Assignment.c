#include<stdio.h>
#include<limits.h>
#define Max 100

int costMatrix[Max][Max];
int n ;
int visited[Max];
int minCost = INT_MAX;

void cost(int task , int currentCost){
    if(task == n){
        if(currentCost < minCost){
            minCost = currentCost;
        }
        return;
    }

    for(int i = 0 ; i < n ; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            cost(task+1, currentCost + costMatrix[task][i]);
            visited[i] = 0;
        }
    }
}

void main(){
    printf("enter the number of tasks/worrkers : ");
    scanf("%d",&n);
    printf("Enter the cost matrix : \n");
    for(int i = 0 ; i < n ;i++){
        for( int j = 0 ; j < n ; j++){
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // making the visited array to 0
    for( int i = 0 ; i < n ; i++){
        visited[i] = 0; 
    }

    cost(0,0);
    printf("The minimum cost is : %d", minCost);

}