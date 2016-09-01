'''line 1: depth of the binary tree
line 2: 2 power d+1 -1 integers'''

def find_sum(arr, x, y, lookup):
	
		
def problem(d, arr, n, commands):
	valid = len(arr) >= 1 and len(arr) <=100000
	valid = valid and (d >= 1 and d <= 100)
	valid = valid and (n >= 1 and n <= 100)
	if not valid:
		return
	lookup = {}
	i=0
	for item in arr:
		if item != -1
			lookup[item] = i;
		i += 1

	for command in commands:
		if "ADD" in command:
			values = command.split()[1:4]
			x = int(values[0])
			y = 1 if values[1]=='L' else 2
			z = int(values[2])
			arr[2*(x) + y] = z
			lookup[z] = 2*x +y
		elif "UPDATE" in command:
			values = command.split()[1:3]
			x = int(values[0])
			y = int(values[1])
			arr[lookup[x]] = y
		elif "DELETE" in command:
			values = command.split()[1:3]
			x = int(values[0])
			arr[lookup[x]] = -1
			del lookup[x]
		elif "SUM" in command:
			values = command.split()[1:3]
			x = int(values[0])
			y = int(values[1])
			find_sum(arr, x, y)
	
	
