#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,K,L,i;
	int *A,*A_idx,*Nums;
	int curr_num_idx, prev_num_idx;
	int tmp, curr_num, prev_num;

	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &L);

	A = (int*)malloc(sizeof(int)*N);
	A_idx = (int*)malloc(sizeof(int)*N);
	for(i=0; i<N; i++) {
		A[i] = i;
		A_idx[i] = i;
	}


	Nums = (int*)malloc(sizeof(int)*K);
	for(i=0; i<K; i++) {
		scanf("%d", &Nums[i]);
	}
#if 0
	for(int j=0; j<N; j++) {
		printf("%d ", A[j]);
	}
	printf("\n");
#endif
	for(i=0; i<K; i++) {
		curr_num = Nums[i];
		curr_num_idx = A_idx[curr_num];
		if(curr_num_idx == 0) continue;
		prev_num_idx = curr_num_idx-1;
		prev_num = A[prev_num_idx];
		A_idx[curr_num]--;
		A_idx[prev_num]++;
		A[curr_num_idx] = prev_num;
		A[prev_num_idx] = curr_num;
#if 0
		for(int j=0; j<N; j++) {
			printf("%d ", A[j]);
		}
		printf("\n");
#endif
	}

	printf("%d", A[L]);

	free(A);
	free(A_idx);
	free(Nums);

	return 0;
}
