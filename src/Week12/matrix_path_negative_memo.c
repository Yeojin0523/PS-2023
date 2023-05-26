#include <stdio.h>
#include <stdlib.h>

int matrixPath_memo(int **m, int r, int c, int i, 
        int j, int **M, int **M1)
{
	if (i == 0 && j == 0) 
		return m[0][0];
	else if (i == 0) {
		if (M1[0][j-1] == 0){
			M[0][j-1] = matrixPath_memo(m,r,c,0,j-1,M,M1);
            M1[0][j-1] = 1;
        }
		return M[0][j-1] + m[i][j];
	}
	else if (j == 0) {
		if (M1[i-1][0] == 0) {
			M[i-1][0] = matrixPath_memo(m,r,c,i-1,0,M,M1);
			M1[i-1][0] = 1;
        }
		return M[i-1][0] + m[i][j];
	}
	else {
		if (M1[i-1][j] == 0){
			M[i-1][j] = matrixPath_memo(m,r,c,i-1,j,M,M1);
			M1[i-1][j] = 1;
        }
		if (M1[i][j-1] == 0){
			M[i][j-1] = matrixPath_memo(m,r,c,i,j-1,M,M1);
			M1[i][j-1] = 1;
        }
		return (M[i-1][j] < M[i][j-1] ? M[i-1][j]: M[i][j-1]) + m[i][j];
	}
}


int main(void)
{
    int **m, **M, **M1; // M은 메모, M1은 계산 여부를 저장
    int i,j,r,c;
    r=c=4; // 4x4 matrix
    m = (int**) malloc( sizeof(int*) * r );
    M = (int**) malloc( sizeof(int*) * r );
    M1 = (int**) malloc( sizeof(int*) * r );
    for(i=0; i < r; i++ ) {
        m[i] = (int*) malloc(sizeof(int) * c );
        M[i] = (int*) malloc(sizeof(int) * c );
        M1[i] = (int*) malloc(sizeof(int) * c );
    }
    for(i=0; i < r; i++ )
        for(j=0; j < c; j++ ) {
            scanf("%d", &m[i][j] );
            M1[i][j] = 0; //메모 초기화
    }
    printf("%d\n", matrixPath_memo(m,r,c,3,3,M,M1) );
    //free
    return 0;
}

