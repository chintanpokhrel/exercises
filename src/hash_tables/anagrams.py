def get_anagrams(words):
	sorted_words = {}
	for word in words:
		key = ''.join(sorted(list(word)))
		if(key in sorted_words):
			sorted_words[key].append(word)
		else:
			sorted_words[key] = [word]
	
	
	return [sorted_words[x] for x in sorted_words if len(sorted_words[x])>1]
	
print get_anagrams(['debitcard', 'elvis', 'silent', 'badcredit', 'lives', 'freedom', 'listen', 'levis', 'money'])
