#include<stdio.h>

void main(){
    int row1 , coulmn1 , row2 , coulmn2;
    printf("Enter the number of rows and coulmns of first matrix: ");
    scanf("%d %d" , &row1 , &coulmn1);
    printf("Enter the number of rows and coulmns of second matrix: ");
    scanf("%d %d" , &row2 , &coulmn2);
    if(coulmn1 != row2){
        printf("Matrix Multiplication is not possible\n");
        return;
    }
    int matrix1[row1][coulmn1] , matrix2[row2][coulmn2] , result[row1][coulmn2];
    printf("Enter the elements of first matrix: \n");
    for(int i = 0 ; i < row1 ; i++){
        for(int j = 0 ; j < coulmn1 ; j++){
            scanf("%d" , &matrix1[i][j]);
        }
    }
    printf("Enter the elements of second matrix: \n");
    for(int i = 0 ; i < row2 ; i++){
        for(int j = 0 ; j < coulmn2 ; j++){
            scanf("%d" , &matrix2[i][j]);
        }
    }

    for(int i = 0 ; i < row1 ; i++){
        for(int j = 0 ; j < coulmn2 ; j++){
            result[i][j] = 0;
            for(int k = 0 ; k < coulmn1 ; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }


    printf("The resultant matrix is: \n");
    for(int i = 0 ; i < row1 ; i++){
        for(int j = 0 ; j < coulmn2 ; j++){
            printf("%d " , result[i][j]);
        }
        printf("\n");
    }
}