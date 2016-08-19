#pretty much O(n*n)
def search(arr, subarr):
	lookup = {}
	asc_arr = []
	for i in subarr:
		lookup[i] = []
	index = 0
	for i in arr: #O(n)
		if i in lookup: #O(1)
			asc_arr.append(index) #O(1)
			lookup[i].append(index) #O(1)
		index += 1
	possible = {}
	distance = []
	index_i = 0
	index_j = 0
	while(index_i <= len(asc_arr)-len(subarr)): #worst case O(n) - O(len(matches found in the arr))
		index_j = index_i
		count = 0
		possible[index_i] = []
		seen = {}
		for i in subarr:
			seen[i] = False
		while(count < len(subarr) and index_j < len(asc_arr)): #O(len(matches found in the arr)-i)
			#if asc_arr[index_j] not in possible[index_i]:
			#print not( arr[asc_arr[index_j]] in seen)
			#print seen
			#print count
			if not (seen[arr[asc_arr[index_j]]]): #O(1)
				count += 1
				seen[arr[asc_arr[index_j]]] = True #O(1)
			
			index_j += 1
		possible[index_i] = asc_arr[index_i:index_j] #slicing not sure if this is O(1) - this seems to be O(index_j-index_i) which is better than O(n)
		distance.append(possible[index_i][-1] - possible[index_i][0]) #O(1)
		index_i += 1
	#print possible
	#print asc_arr
	#print len(subarr)	
	#min distance
	min_distance = distance[0]
	pos = 0
	index_i = 1
	while(index_i < len(distance)): #O(len(matches found in the arr) worst case O(n)
		if distance[index_i] < min_distance:
			min_distance = distance[index_i]
			pos = index_i
		index_i += 1
	return possible[pos][0], possible[pos][-1]

print search(['aloo', 'states', 'the', 'union', 'save', 'the', 'bhaloo', 'union', 'union', 'of', 'save', 'of', 'state', 'of', 'the', 'union', 'save', 'states'], ['save', 'states', 'union'])
		
	
	
	
	


