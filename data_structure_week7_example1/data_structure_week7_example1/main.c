#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int m,n,p;
    
    // m, n, p 입력
    printf("행렬A(m x n), 행렬B(n x p) 의 m,n,p을 입력해주세요 : ");
    scanf("%d %d %d",&m,&n,&p);
        // 행렬 A 동적할당
        int** matrixA = malloc(sizeof(int*) * m);
        
        // 행렬 A : m x n
           for (int i = 0; i < m; i++)
           {
               matrixA[i] = malloc(sizeof(int) * n);
           }
        
        // 행렬 B 동적할당
        int** matrixB = malloc(sizeof(int*) * n);
        
        // 행렬 B 크기 : n x p
           for (int i = 0; i < n; i++)
           {
               matrixB[i] = malloc(sizeof(int) * p);
           }
        
        // 연산 값 저장을 위한 행렬 C 동적할당
        int** matrixC = malloc(sizeof(int*) * m);
        
        // 행렬 m x p
           for (int i = 0; i < m; i++)
           {
               matrixC[i] = malloc(sizeof(int) * p);
           }
        
        
        // 행렬 A 입력받기
        printf("=== 행렬 A입력 ===\n");
        
        // m행, n열
        for (int i = 0; i < m; i++)
         {
             for (int j = 0; j < n; j++)
             {
                 scanf("%d",&matrixA[i][j]);
             }
             
         }
        printf("\n");
        
        //행렬 B 입력받기
        printf("=== 행렬 B입력 ===\n");
        
        // n행, p열
        for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < p; j++)
             {
                 scanf("%d",&matrixB[i][j]);
             }
         }
        
        
        printf("\n");
        
        // 행렬 곱셈 진행 m x p
        for(int i = 0; i < m; i++)
                for(int j = 0; j < p; j++){
                    // matrixC 초기화
                    matrixC[i][j] = 0;
                    for(int k = 0; k < n; k++)
                        // C(m x p) = A(m x n) * B(n x p)
                        matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                }
        
        // 결과 출력
        printf("=== 행렬 A X 행렬 B 결과 ===\n");
        
        // C행렬 m x p
        for (int i = 0; i < m; i++)
         {
             for (int j = 0; j < p; j++)
             {
                 printf("%d ",matrixC[i][j]);
             }
             printf("\n");
         }
    
    // 동적 할당해제
    free(matrixA);
    free(matrixB);
    free(matrixC);
    return 0;
}
