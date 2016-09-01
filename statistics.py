#count the number of lines of .py, .c and .h files recursively inside src/ folder
import os

count = {}
def do_count(filepath, ext):
	if (ext != 'py') and (ext != 'c') and (ext != 'h'):
		return
	if ext not in count:
		count[ext] = 0
	with open(filepath, 'r') as f:
		for line in f:
			count[ext] += 1


for root, dirs, files in os.walk("src/"):
	i=0
	for filename in files:
		do_count(os.path.join(root, filename), filename.split(".")[-1]) #passing extension

#Updating the statistics in README.md file
readme = []
with open("README.md", 'r') as f:
	for line in f:
		readme.append(line)
	f.close()
	
#print "readme: "
#print readme

readme[-3] = "C: " + str(count['c']) + "\n"
readme[-2] = "PYTHON: " + str(count['py']) + "\n"
readme[-1] = "C HEADER: " + str(count['h']) + "\n"
readme = "".join(readme)
with open("README.md", 'w') as f:
	f.write(readme)
	f.close()
		
print count
