def check_palindrome(word):
	d = {}
	for w in list(word):
		if w in d:
			d[w] += 1
		else:
			d[w] = 1
	if len(word)%2==0:
		for k in d:
			if d[k]%2 != 0:
				return False
			
		
		return True
	else:
		single = False
		for k in d:
			s = d[k]%2
			if single and s != 0:
				return False
			if s != 0:
				single = True
			
		return True
		
print check_palindrome('arora')
print check_palindrome('aloo')
print check_palindrome('rotator')
print check_palindrome('boka')
print check_palindrome('aaaaaa')
