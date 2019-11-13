# Multiprocess-Synchronization-Tool

What is achieved?
The producer should not add data when the buffer is already full. 
The producer should place the data in the buffer only if there is at least one slot vacantly available to it. Else if the buffer is full, the producer must wait till any slot is released. 
The consumer should not try to remove data is the buffer is already empty. 
The consumer should consume and remove the data from the buffer only if the buffer is not empty i.e., there is at least some data in the buffer. Else if the buffer is empty, since there is nothing to take and remove, it must wait till any slot is filled again. 

What is used?

Using three Semaphores:
	 empty and full and a mutex lock.
   circular Buffer


What is a Producer?
A producer:
Produces data and makes it available to the consumer. 
Can only add data into buffer. 
Cannot delete from the buffer.


What is a Consumer?
A consumer: 
Consumes data and removes it from the buffer. 
Can only consume and delete from the buffer. 
Cannot add data into buffer. 

Producer and Consumer must be synchronized in order to avoid situations like deadlocks or data being lost. 
