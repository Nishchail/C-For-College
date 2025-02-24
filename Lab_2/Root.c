#include<stdio.h>
#include<math.h>

void main(){
    int n ; 
    printf("enter a positive number : ");
    scanf("%d",&n);

    if(n<0){
        printf("Invalid input\n");
        exit(0);
    }

    float root = 1;
    float diff = 0.0001;
    while(1){
        float temp = root;
        root = 0.5*(root + (n/root));
        if(fabs(root - temp) < diff){
            break;
        }
    }

    printf("Root of %d is : %f\n",n,root);
}