//proto
void BubbleSort(Item A[], int l, int r);
//func
void BubbleSort(Item A[], int l, int r)
{
	int i, j;
	Item temp;
	for( i = l; i < r; i++) {
		for (j = l; j < r – i +l; j++)
			if (greater(A[j], A[j+1])) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
	}
	return;
}

