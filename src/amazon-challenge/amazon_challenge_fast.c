#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void solve();
int_fast64_t findMaxSum(int_fast32_t *, int_fast32_t);

int main(){
	solve();
	return 0;
}

void solve()
{
	int_fast16_t n_test;
    scanf("%"SCNdFAST16, &n_test);
     
    if (!((1 <= n_test) && (n_test <= 1000)))
    {
    	return;
    }


	int_fast32_t *a[2];
	int_fast16_t k;
	//for size of each input test case
	int_fast32_t *n = (int_fast32_t *)malloc(n_test * sizeof(int_fast32_t));
	
    for (k = 0; k < n_test; ++k)
    {
    	//int_fast32_t n;
    	scanf("%"SCNdFAST32, &(n[k]));

        if (!((1 <= n[k]) && (n[k] <= 100000)))
        {
        	return;
        }

        a[0] = (int_fast32_t *)malloc(n[k] * sizeof(int_fast32_t));
        a[1] = (int_fast32_t *)malloc(n[k] * sizeof(int_fast32_t));
             
        //read row 1
        int_fast32_t j = 0;
        int_fast32_t item;
        for(j=0; j<n[k]; ++j)
        {
			scanf("%"SCNdFAST32, &item);
        	if (!((1 <= item) && (item <= 1000000000)))
            {
            	return;
            }
            a[0][j] = item;

        }
        //read row 2
        for(j=0; j<n[k]; ++j)
        {
			scanf("%"SCNdFAST32, &item);
        	if (!((1 <= item) && (item <= 1000000000)))
            {
            	return;
            }
            a[1][j] = item;

        }
	}
	
	for(k=0; k<n_test; ++k){
        //compute the array which contains the max element in each column (reusing row 0)
        int_fast32_t i;
        for (i = 0; i < n[k]; ++i)
        {
        	a[0][i] = (a[0][i] >= a[1][i] ? a[0][i] : a[1][i]);
        }
		//get the max non adjacent sum for a[0]
        int_fast64_t max = findMaxSum(a[0], n[k]);
        //print result
        printf("Case #%"PRIdFAST16, k+1);
        printf(": %"PRIdFAST64, max);
        printf("\n");

	}
	
}

int_fast64_t findMaxSum(int_fast32_t *a, int_fast32_t n)
{
	int_fast64_t inc = a[0];
    int_fast64_t exc = 0;
    int_fast64_t exc_tmp;
	
	int_fast32_t i;
    for (i = 1; i < n; i++)
    {
    	//max excluding current
    	exc_tmp = (inc > exc) ? inc : exc;
        //max including current
        inc = exc + a[i];
        exc = exc_tmp;
    }

    return (inc > exc) ? inc : exc;
}


