#1. implement an ISBN -  book price cache - a dict can be used
#2. also need to store the use timestamp to implement LRU cache
# this will give O(1) lookup cache['isbn'][1] = cur_time, return cache['isbn']
# but when cache is full, need to find the LRU item i.e. with min timestamp, O(n) operation and del it
# Okay, instead of storing <isbn, [price, cur_time]>, I maintain a queue.
# Queue is implemented in queue.c already, so using ctypes, I load the .so and proceed -getting tired trying this

from queue import *

class Cache1:
	def __init__(self):
		#self.data = data
		self.lookup = {}
		self.size = 5
		self.counter = 0
	
	def isbn_lookup(self, isbn):
		if isbn in self.lookup:
			self.counter += 1
			self.lookup[isbn][1] = self.counter
			return self.lookup[isbn][0]
		return None
	
	def insert(self, isbn, price):
		if isbn in self.lookup:
			self.counter += 1
			self.lookup[isbn][1] = self.counter
		else:
			if len(self.lookup.keys())>=self.size:
				minimum = self.counter + 1
				min_k = None
				for k in self.lookup:
					if minimum == self.counter + 1:
						min_k = k
					#print 'k:', k
					#print 'self.lookup[k][1]: ', self.lookup[k][1]
					#print 'minimum: ', minimum
					#print 'self.counter: ', self.counter
					if self.lookup[k][1] < minimum:
						minimum = self.lookup[k][1]
						min_k = k
				print min_k
				del self.lookup[min_k]
			self.lookup[isbn] = []
			self.lookup[isbn].append(price)
			self.counter += 1
			self.lookup[isbn].append(self.counter)
			
	def remove(self, isbn):
		for k in self.lookup:
			if k == isbn:
				del self.lookup[k]
				return True
		return False
		
c = Cache1()
c.insert(10, 500)
c.insert(12, 450)
print c.isbn_lookup(10)
c.insert(13, 498)
c.insert(14, 459)
c.insert(15, 511)
c.insert(16, 900)
print c.isbn_lookup(12)
print c.isbn_lookup(10)

#this is not useful, because erase will take O(n) as I don't store previous pointer in my queue
class Cache2:
	def __init__(data):
		self.data = data
		self.lookup = {}
		self.size = 5
		self.lru_Queue = create_Queue()
		#self.counter = 0
		
	#Okay, two underscores at the start and you're private ! Beautiful 
	def __move_to_front(node):
		eraseNode_Queue(self.lru_Queue, node)
		enQueue(node)
	
	def lookup(isbn):
		if isbn in self.lookup:
			__move_to_front(self.lru_Queue, self.lookup[isbn][1]) #but then this is O(n) :(
			return self.lookup[isbn][0]
	
	
			
			
			
