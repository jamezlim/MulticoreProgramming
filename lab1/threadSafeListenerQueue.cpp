#include <iostream>


//constructor 
template <typename T>
ThreadSafeListenerQueue <T>:: ThreadSafeListenerQueue(){
	size = 0;
}

template <typename T>
void ThreadSafeListenerQueue <T> :: print(){
	for (itr = queue.begin(); itr != queue.end(); itr ++ ){
		std::cout << * itr << " --> " ;
	}
}

// template <typename T>
// int ThreadSafeListenerQueue <T> :: size(){
// 	return size;
// }

//??? take care of the case where size is max?? 

template <typename T>
bool ThreadSafeListenerQueue <T> :: push (const T element){
	pthread_mutex_lock(&mtx);
	size ++;
	queue.push_back(element);
	pthread_cond_signal(&cv);
	pthread_mutex_unlock(&mtx);
	return true;
}

template <typename T>
bool ThreadSafeListenerQueue <T> :: pop(T& element){
	pthread_mutex_lock(&mtx);
	if ( size == 0 ){
		pthread_mutex_unlock(&mtx);
		return false; 
	} 
	else if ( size != 0 ){
		element = queue.front();
		queue.pop_front();
		size--;
		pthread_mutex_unlock(&mtx);
		return true;
	}
	// error 
	pthread_mutex_unlock(&mtx);
	return false; 
}

template <typename T>
bool ThreadSafeListenerQueue <T> :: listen(T& element){
	pthread_mutex_lock(&mtx);
	while ( size  == 0) {
		pthread_cond_wait(&cv,&mtx);
	}
	if ( size != 0) {
		element = queue.front();
		queue.pop_front();
		size--;
		pthread_mutex_unlock(&mtx);
		return true;
	}
	pthread_mutex_unlock(&mtx);
	return false;
}
