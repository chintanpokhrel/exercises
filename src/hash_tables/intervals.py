#O(n*n)
def intervals(arr):
	arr = sorted(arr) #O(n lg n)
	i=0
	j=None
	possible = {}
	while i < len(arr): #O(n)
		j = i + 1
		possible[i] = []
		possible[i].append(arr[i])
		while j < len(arr) and arr[j] == arr[j-1] + 1: #worst case O(n)
			possible[i].append(arr[j])
			j += 1
		i += 1	
	max_interval = []
	for interval in possible: #O(n)
		max_interval = possible[interval] if len(possible[interval]) > len(max_interval) else max_interval
	return max_interval
	

def intervals_improved(arr):
	
	print possible

print intervals_improved([3, -2, 7, 9, 8, 1, 2, 0, -1, 5, 8, -5])
