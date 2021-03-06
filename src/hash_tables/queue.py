from ctypes import *

_Queues = CDLL('../queues/libQueue.so')

class Node(Structure): pass
	
Node._fields_ = [('data', c_void_p), ('next', POINTER(Node))]

	
class Queue(Structure): pass
	
Queue._fields_ = [('type', c_int), 
				('front', POINTER(Node)), 
				('rear', POINTER(Node))]

_Queues.create_Queue.argtypes = [c_int]
_Queues.create_Queue.restype = POINTER(Queue)
def create_Queue():
	return _Queues.create_Queue()

_Queues.enQueue.argtypes = [POINTER(Queue), c_void_p]
def enQueue(queue, val):
	_Queues.enQueue(byref(queue), c_void_p(val))

_Queues.deQueue.argtypes = [POINTER(Queue)]
_Queues.deQueue.restype = c_void_p
def deQueue(queue):
	return _Queues.deQueue(byref(queue))


_Queues.destroy_Queue.argtypes = [POINTER(Queue)]
def destroy_Queue(queue):
	 _Queues.destroy_Queue(byref(queue)) #this crashes for some screwed up reason

_Queues.empty_Queue.argtypes = [POINTER(Queue)]
def empty_Queue(queue):
	_Queues.empty_Queue(byref(queue))
	
_Queues.eraseNode_Queue.argtypes = [POINTER(Queue), POINTER(Node)]
def eraseNode_Queue(queue, node):
	_Queues.eraseNode_Queue(byref(queue), byref(node))

(integer, treeNode) = (0, 1)



