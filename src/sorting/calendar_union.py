#given a set of events, return the union of events - a disjoint set of unioned events
#O(n lg n)
def calendar(events):
	events.sort(key = lambda event: (event[0], event[1])) #O(n lg n)
	#print events
	i = 0
	union = []
	while i<len(events): # O(n)
		j = i
		max_end = events[i][1]
		while j < len(events) and events[j][0] < max_end:
			if events[j][1] > max_end:
				max_end = events[j][1]
			j += 1
		union.append((events[i][0], max_end)) if i < len(events) and j-1 < len(events) else union.append(())
		i = j
	return union
	

cal = [(3, 5), (3, 9), (0, 6), (4, 8), (6, 9), (9, 10)]
print cal	
print sorted(cal, key = lambda event: event[0])
print sorted(cal, key = lambda event: (event[0], event[1]))
print calendar(cal)
