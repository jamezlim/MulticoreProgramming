#ifndef LAB1q_H
#define LAB1q_H

#include <list>
#include <condition_variable>
#include <mutex>
//#include <pthread.h> 

template <typename T>
class ThreadSafeListenerQueue {
	std:: list <T> queue;
	std:: mutex mtx ;
	std:: condition_variable cv;
	int size ;
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