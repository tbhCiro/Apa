//proto
void SelectionSort(Item A[], int l, int r);

//func
void SelectionSort(Item A[], int l, int r){
	int i, j, min;
	Item temp;
	for(i = l; i < r; i++) {
		min = i;
	for (j = i+1; j <= r; j++)
		if (less(A[j], A[min]))
			min = j;
	temp = A[i];
	A[i] = A[min];
	A[min] = temp;
	}
	return;
}
