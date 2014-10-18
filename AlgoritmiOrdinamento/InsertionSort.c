//proto
void InsertionSort(Item A[], int l, int r);
//func
void InsertionSort(Item A[], int l, int r) {
	int i, j;
	Item x;
	for(i = l+1; i <= r; i++) {
		x = A[i];
		j = i - 1;
		while (j >= l && less(x, A[j])) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = x;
	}
}
