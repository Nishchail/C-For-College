#include <stdio.h>
#include <limits.h>

#define Max 10

int n ;
int minCost = INT_MAX;
int cost[Max][Max];
int visited[Max];

void tsp(int city, int count , int Currcost , int startCity){
    if(count == n && cost[city][startCity] > 0){
        Currcost += cost[city][startCity];
        if(Currcost < minCost){
            minCost = Currcost;
        }
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(cost[city][i] > 0 && visited[i] == 0 ){
            visited[i] = 1 ;
            tsp(i , count +1 , Currcost + cost[city][i] , startCity );
            visited[i] = 0 ; 
        }
    }
}

int main() {
    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start the TSP from city 0
    visited[0] = 1;
    tsp(0, 1, 0, 0);

    // Print the result
    printf("The minimum cost of the TSP is: %d\n", minCost);

    return 0;
}
