#include <iostream>
#include <vector>
#include <thread>
#include <pthread.h>
#include "threadSafeKVStore.h"
#include <string>
#include <time.h>
#include <unordered_map>
#include "threadSafeListenerQueue.h"

void add (std::vector <int>&v) {
		v.push_back (2);
	}

void terminate(){
	exit(EXIT_FAILURE);
}

void print1 ( ThreadSafeKVStore <std::string, int32_t> i) {
	std::cout << "in thread" << std::endl;
}

int main (){
	ThreadSafeListenerQueue < int32_t> q;
	q.push( 32);
	q.push( 42);
	q.print();

	// bool flag = true;
	// if( flag ){
	// 	int a = 1;
	// 	std::cout << "right before exit" << std::endl;
	// 	terminate();
	// 	std::cout << a << std::endl;
	// }
	// else {
	// 	 int a = 2;
	// }

	// std::cout << "end of main" << std::endl;


	
}