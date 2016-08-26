#O(n) time and O(1) additional space
def remove_dup(arr):
	#aux_array = [] #O(n) time, worst case O(n) space - when all first names are distinct
	#aux_array.append(arr[0] if arr else ())
	if(len(arr)>1):
		arr.sort(key=lambda val: val[0])
	i=1
	j=1
	while i < len(arr):
		while (i < len(arr)) and (arr[i-1][0] == arr[i][0]):
			#del arr[i] #this is O(n) so it is not good
			#i -= 1
			i += 1
		if i < len(arr):
			#aux_array.append(arr[i])
			arr[j] = arr[i]
			j += 1
			i += 1

	return arr[0: j]

print remove_dup([(2, 3), (4, 5), (4, 5), (6, 4), (6, 4), (2, 3), (2, 3), (4, 5), (6, 4)])
print remove_dup([(2, 3), (4, 5), (6, 4)])
print remove_dup([(2, 3)])
print remove_dup([()])
print remove_dup([])
