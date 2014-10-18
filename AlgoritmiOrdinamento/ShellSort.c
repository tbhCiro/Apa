//proto
void ShellSort(Item A[], int l, int r);
//func
void ShellSort(Item A[], int l, int r) {
	int i, j, h=1, n = r – l +1;
	Item temp;
	while (h < n/3)
		h = 3*h+1;
	while(h >= 1) {
		for (i = l + h; i <= r; i++) {
			j = i;
			temp = A[i];
			while(j >= l + h && less(temp, A[j-h])) {
				A[j] = A[j-h];
				j -=h;
			}
			A[j] = temp;
		}
		h = h/3;
	}
}

