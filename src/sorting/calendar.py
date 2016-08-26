#given a set of events, return the max number of concurrent events
def calendar(events):
	events.sort(key = lambda event: event[1]) #O(n lg n)
	#print events
	i = 0
	count = []
	while i<len(events): # <O(n*n)
		count.append(0)
		j = i
		#print i, j
		while j < len(events) and events[j][0] < events[i][1]:
			j += 1
			count[i] += 1
		i += 1
	return max(count)
	
print calendar([(3, 5), (0, 6), (4, 8), (6, 9), (9, 10)])
cal = [(3, 9), (3, 5), (0, 6), (4, 8), (6, 9), (9, 10)]
print cal	
print calendar(cal)
