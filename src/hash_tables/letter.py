def isConstructible(letter, magazine):
	d = {}
	for c in list(magazine):
		if c in d:
			d[c] += 1
		else:
			d[c] = 1
	for c in list(letter):
		if c not in d or d[c] == 0:
			return False
		else:
			d[c]--
	return True
