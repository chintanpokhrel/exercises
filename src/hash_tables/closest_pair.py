
def closest_pair(arr):
	lookup = {}
	distance = None
	index = 0
	for item in arr:
		if item in lookup:
			if distance:
				if (distance > index - lookup[item]):
					distance = index - lookup[item]
			else:
				distance = index - lookup[item]
			lookup[item] = index
		else:
			lookup[item] = index
		index += 1
	return distance

assert closest_pair(['All', 'work', 'and', 'no', 'play', 'makes', 'for', 'no', 'work', 'no', 'fun', 'and', 'no', 'results']) == 2
