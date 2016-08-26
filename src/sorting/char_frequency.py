def frequency(text): #works only for a specific set of chars, O(n) extra space, O(n) max time
	a = 97
	lookup = {}
	while (a < 97+ 25):
		lookup[chr(a)] = 0
		a += 1
	for char in list(text):
		if char in lookup:
			lookup[char] += 1
	result = []
	a = 97
	while (a < 97+ 25):
		if lookup[chr(a)] > 0:
			result.append((chr(a), lookup[chr(a)]))
		a += 1
	return result 

def frequency_other(text): #O(n) extra space, O(n lg n) time, can be implemented in O(1) extra space in C/C++ treating text as an arr of chars
	text = sorted(list(text))
	result = []
	count = 0
	i=1
	while i < len(text) + 1:
		count = 1
		while i < len(text) and text[i-1] == text[i]:
			count += 1
			i += 1
		result.append((text[i-1], count))
		i += 1
	return result

#another approach that can be used when the character set is small is maintaining an array of integers indexed by characters

print frequency("basdjkdfjdsskkjdn")
print frequency_other("basdjkdfjdsskkjdn")
		
