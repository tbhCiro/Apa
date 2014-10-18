//proto
void CountingSort(Item A[], int l, int r, int k);
//func
void CountingSort(Item A[], int l, int r, int k){
	int i, n, *C;
	Item *B;
	n = r – l + 1;
	B = malloc(n*sizeof(Item)); C = malloc(k*sizeof(int));
	for (i = 0; i < k; i++)
		C[i] = 0;
	for (i = l; i <= r; i++)
		C[A[i]]++;
	for (i = 1; i < k; i++)
		C[i] += C[i-1];
	for (i = r; i >= l; i--) {
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
	for (i = l; i <= r; i++)
		A[i] = B[i];
}
