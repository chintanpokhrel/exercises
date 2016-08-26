class Student:
	def __init__(self, name, age):
		self.name = name
		self.age = age
	def __repr__(self):
		#return "Student Name = %s, Age = %s" % (self.name, self.age)
		return "%s"%self.age

#O(nk), k distinct elements, still worse than O(n lg n) - achieved by sorting, so this sucks
def gather_duplicates(students):
	i, j = 0, 0
	while (i<len(students)):
		j = i + 1
		while j < len(students):
			if students[i].age == students[j].age :
				#swap at i + 1 and j
				age_j = students[j].age
				students[j].age = students[i+1].age
				students[i+1].age = age_j
				i += 1
			j += 1
		i += 1
	return students

def gather_duplicates_without_sucking(students):
	age_lookup = {}
	for student in students:
		if student.age in age_lookup:
			age_lookup[student.age] += 1
		else:
			age_lookup[student.age] = 1
	print age_lookup
	index_lookup = {}
	prev = 0
	for age in age_lookup:
		index_lookup[age] = prev
		prev += age_lookup[age]
	print index_lookup
		
	i=0
	n = len(students)
	while i < n:
		stud = students[i]
		print students, index_lookup[stud.age], stud.age
		students[i] = students[index_lookup[stud.age]]
		students[index_lookup[stud.age]] = stud
		index_lookup[stud.age] += 1
		if stud.age != students[i].age:
			index_lookup[students[i].age] += 1 
		i += 1
		
		
studs = []
#print gather_duplicates(studs)
studs.append(Student('Harkey', 45))
studs.append(Student('Birkhey', 22))
studs.append(Student('Bimal', 45))
studs.append(Student('Dalley', 21))
studs.append(Student('Harkey', 45))
studs.append(Student('Bhuntey', 22))
studs.append(Student('Dalley', 21))

s = gather_duplicates_without_sucking(studs)
print studs
print s

