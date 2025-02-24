#include <stdio.h>
#include <stdlib.h>

void main(){
    int n , m ;
    printf("Enter the two number for GCD calculation ");
    scanf("%d %d", &n, &m);
    int gcd = 1;

    int min = (n < m) ? n : m;

    for(int i = 2; i <= min; i++){
        if(n % i == 0 && m % i == 0){
            gcd = i;
        }
    }

    printf("GCD of %d and %d is %d", n, m, gcd);
}