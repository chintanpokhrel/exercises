#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int findMaxSum(long a[], long n)
{
	long inc = a[0];
    long exc = 0;
    long exc_tmp;

    for (long i = 1; i < n; i++)
    {
    //max excluding current
    	exc_tmp = (inc > exc) ? inc : exc;
        //max including current
        inc = exc + a[i];
        exc = exc_tmp;
    }

    return (inc > exc) ? inc : exc;
}

void solve()
{
	short n_test;
    scanf("%hi", &n_test);
     
    if (!((1 <= n_test) && (n_test <= 1000)))
    {
    	return;
    }


	short k;
    for (k = 0; k < n_test; ++k)
    {
    	long n;
    	scanf("%li", &n);

        if (!((1 <= n) && (n <= 100000)))
        {
        	return;
        }

        long *a[2];
        a[0] = (long *)malloc(n * sizeof(long));
        a[1] = (long *)malloc(n * sizeof(long));
        
        
        //read row 1
        long j = 0;
        long item;
        for(j=0; j<n; ++j)
        {
			scanf("%li", &item);
        	if (!((1 <= item) && (item <= 1000000000)))
            {
            	return;
            }
            a[0][j] = item;

        }
        //read row 2
        for(j=0; j<n; ++j)
        {
			scanf("%li", &item);
        	if (!((1 <= item) && (item <= 1000000000)))
            {
            	return;
            }
            a[1][j] = item;

        }
        
        long *another = (long *)malloc(n*sizeof(long));
        long i;
        for (i = 0; i < n; ++i)
        {
        	another[i] = a[0][i] >= a[1][i] ? a[0][i] : a[1][i];
        }

        unsigned long max = findMaxSum(another, n);
        printf("Case #%d: %li\n", k, max);

	}
	
}

int main(){
	solve();
}
