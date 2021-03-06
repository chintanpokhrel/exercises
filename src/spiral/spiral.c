#include <stdio.h>

#define NUM_ROWS_COLS 4


void spiral(int a[][NUM_ROWS_COLS], int, int, int*);

int main(int argc, char* argv[]){
	int arr[][NUM_ROWS_COLS] = {
				    {1, 2, 3, 4}, 
				   {16, 17, 18, 19}, 
				   {15, 24, 25, 20}, 
				   {14, 23, 22, 21},
				   //{13, 12, 11, 10}
				   };
	int result[NUM_ROWS_COLS*NUM_ROWS_COLS];
	spiral(arr, NUM_ROWS_COLS, NUM_ROWS_COLS, result);
	int i;
	for(i=0; i<NUM_ROWS_COLS*NUM_ROWS_COLS; ++i){
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}

void spiral(int a[][NUM_ROWS_COLS], int m, int n, int* b){
	int z[] = {0, 1, 0, -1};
	int zx = 3, zy = 0;
	int k=0;
	int xmax = m-1, ymax = n-1, xmin = 0, ymin = 0;
	int x = xmin, y = ymin;
	
	while((xmax-xmin>0) || (ymax-ymin>0)){
		//short reset = 0;	
		/*printf("k: %d\n", k);
		printf("x: %d\n", x);
		printf("y: %d\n", y);
		printf("xmax: %d\n", xmax);
		printf("xmin: %d\n", xmin);
		printf("ymax: %d\n", ymax);
		printf("ymin: %d\n", ymin);
		printf("zx: %d\n", zx);
		printf("zy: %d\n", zy);
		getchar();*/
		b[k] = a[x][y];
		if(x==xmin+1&&y==ymin){
			xmin++, ymin++;
			xmax--, ymax--;
			zx = 3;
			zy = 0;
			x = xmin, y = ymin;
			//reset = 1;
			++k;
			b[k] = a[x][y];
		}
		
		
		
		if((x==xmin && y==ymax)||(x==xmax && y==ymin)||(y==ymin && x==xmin)||(y==ymax&&x==xmax)){
			zx = (zx+1)%4;
			zy = (zy+1)%4;
			//++corner;
		}
		
		//if(!reset){
			x += z[zx];
			y += z[zy];
		//}
		
		++k;
	}	
}
