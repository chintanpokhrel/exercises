void max_heapify(int*, int, int);

//does this asshole assume an increasing sorted array ? No. It doesn't.
void build_max_heap(int* a, int n){
	int i;
	for(i=n/2-1; i>=0; --i){
		max_heapify(a, n, i);
	} 
}
//assuming a single violation of max-heap property at index i, max heapify the array a
void max_heapify(int* a, int n, int i){
	int l_child = 2*(i+1) - 1;
	int r_child = l_child + 1;
	int max_ch = -1;
	int t;
	if(r_child < n){
		if(!(a[i] > a[l_child] && a[i] > a[r_child])){
			if(a[l_child] >= a[r_child]){
				max_ch = l_child;
			}else{
				max_ch = r_child;
			}
		}
	}else if(l_child<n){
		if(a[l_child]>a[i]){
			max_ch = l_child;
		}
	}
	
	if(max_ch != -1){
		t = a[i];
		a[i] = a[max_ch];
		a[max_ch] = t;
		max_heapify(a, n, max_ch);
	}
}


void insert_max_heap(int *a, int n, int val){
	a[n-1] = val;
	//a[0] = val;
	max_heapify(a, n, n-1);
}

int extract_max(int *a, int n){
	int max = a[0];
	a[0] = a[n-1];
	a[n-1] = max;
	max_heapify(a, n-1, 0);
	return max;
}
