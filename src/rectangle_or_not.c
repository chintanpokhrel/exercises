/*Given 4 points on a plane, determine whether those points are on a rectangle.*/

/*Strategy: compute all possible distances d1 to d6 and put them in an array. 
  Now sort the array and check if the first pair are equal, second pair are equal and third pair are equal.
  If not, definitely not a rectangle.
  If else, check if the three available distances are a Pythagoras triplet. If yes, rectangle.
  If not, not a rectangle.
  
  The above wasn't working due to float screwups. So instead used the squares of the distances, 
  sorted them, added first two to get the third.
  
  ASSUMPTION: (x, y) where x and y are int
*/
  
#include <stdio.h>
#include <math.h>
#include <bsd/stdlib.h>

void print_array(int*, int);

int compare(int *a, int* b){
	return (*a) - (*b);
}

int main(int argc, char* argv[]){
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
	
	printf("Enter x1 y1 > ");
	scanf("%d %d", &x1, &y1);
	
	printf("\nEnter x2 y2 > ");
	scanf("%d %d", &x2, &y2);
	
	printf("\nEnter x3 y3 > ");
	scanf("%d %d", &x3, &y3);
	
	printf("\nEnter x4 y4 > ");
	scanf("%d %d", &x4, &y4);
	
	int d[6], t[6];
	
	/*d[0] = round(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
	d[1] = round(sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)));
	d[2] = round(sqrt((x1-x4)*(x1-x4) + (y1-y4)*(y1-y4)));
	d[3] = round(sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)));
	d[4] = round(sqrt((x2-x4)*(x2-x4) + (y2-y4)*(y2-y4)));
	d[5] = round(sqrt((x3-x4)*(x3-x4) + (y3-y4)*(y3-y4)));*/
	
	d[0] = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	d[1] = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
	d[2] = (x1-x4)*(x1-x4) + (y1-y4)*(y1-y4);
	d[3] = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
	d[4] = (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4);
	d[5] = (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4);
	
	print_array(d, 6);
	mergesort(d, 6, sizeof(float), (int(*)(const void*, const void*))compare);
	print_array(d, 6);
	short flag = d[0] == d[1] && d[2] == d[3] && d[4] == d[5];
	
	if(!flag){
		printf("Not a rectange!\n");
		return 0;
	}
	
	//check for Pythagoras triplet
	if(d[0] + d[2] == d[4]){
		printf("Yesss!! Points lie on the rectangle!!!\n");
		return 0;
	}
	
	printf("Not a rectangle!\n");
	return 0;
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


