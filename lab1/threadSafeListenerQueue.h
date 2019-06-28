#ifndef LAB1q_H
#define LAB1q_H

#include <list>
#include <pthread.h> 

template <typename T>
class ThreadSafeListenerQueue {
	std:: list <T> queue;
	pthread_mutex_t mtx;
	pthread_cond_t cv;
	int size;
	typename std:: list <T> :: iterator itr;
public:
	ThreadSafeListenerQueue();
	bool push(const T element);
	bool pop(T& element);
	bool listen(T& element);
	void print ();
	int get_size() { return size; }
};

#include "threadSafeListenerQueue.cpp"
#endif