fib_dict = {1:1, 2:1}
'''fib(n)=fib(n-1) + fib(n-2)'''
def fib(n):
	#print("Called");
	if(n<1):
		return None
	fib_n_1 = None
	fib_n_2 = None

	if n-2 in fib_dict :
		fib_n_2 = fib_dict[n-2]
	else :
		fib_n_2 = fib(n-2)
		fib_dict[n-2] = fib_n_2

	if n-1 in fib_dict :
		fib_n_1 = fib_dict[n-1]
	else :
		fib_n_1 = fib(n-1)
		fib_dict[n-1] = fib_n_1

	return fib_n_1 + fib_n_2

def fib_naive(n):
	if(n<1):
		return None;
	if(n==1 or n==2):
		return 1
	else:
		return fib_naive(n-1) + fib_naive(n-2)

print fib(100)
print fib_naive(50) #this takes forever to compute
