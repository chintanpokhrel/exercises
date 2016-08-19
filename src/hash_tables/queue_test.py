from queue import (Queue, enQueue, deQueue, empty_Queue, destroy_Queue, integer)
from ctypes import (c_void_p, byref)

queue = Queue(type=integer, front=None, rear=None)
val = 10
enQueue(queue, val)
print queue.front.contents.data
print deQueue(queue)
empty_Queue(queue) 
destroy_Queue(queue) #this is crashing after emptying the queue successfully, invalid pointer - apparently
