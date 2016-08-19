#O(m > n ? m : n)
#This is not using the fact that the arrays are sorted, the returned array is sorted though
def intersection(arr1, arr2):
	lookup = {} # O(m) space if arr1 is of m length
	for item in arr1: #O(m)
		lookup[item] = False
	inter = []
	for item in arr2: #O(n)
		if item in lookup: 
			if not lookup[item]:
				inter.append(item) #O(1)
				lookup[item] = True
	
	return inter
	
#Alternative would be to scan the smaller of the arrays and binary search the larger - O(m lg n) time , no additional space
# + advance through both arrays in increasing order

def intersection_improved(arr1, arr2):
	i = 0
	j = 0
	inter = []
	while (i<len(arr1) and j<len(arr2)):
		if arr1[i] == arr2[j] and (i==0 or arr1[i] != arr1[i-1]):
			inter.append(arr1[i])
			i += 1
			j += 1
		elif arr1[i] < arr2[j] :
			i += 1
		else:
			j += 1	
	return inter
	
	
print intersection_improved([], [])
print intersection_improved([], [2, 3, 4])
print intersection_improved([3, 4, 5, 5, 6], [])
print intersection_improved([2, 3, 4, 4], [2, 3, 3])
print intersection_improved([1, 2, 3, 4, 5], [1, 3, 4, 9, 10])
