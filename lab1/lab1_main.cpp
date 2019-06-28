#include <string>
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <thread>
#include <vector>
#include <pthread.h>
#include "threadSafeKVStore.h"
#include "threadSafeListenerQueue.h"

int NUM_OF_TEST_RUN = 10;

void test(ThreadSafeKVStore <std::string, int32_t >& m , ThreadSafeListenerQueue < int32_t >& q, int threadNum){
	std::cout << "inside test thread #" << threadNum << std ::endl;
	int32_t threadSum = 0; 
	std:: vector < std::string > keyVector;
	int numOfKeysInVector = 0;

	for (int i = 0; i < NUM_OF_TEST_RUN; i++ ){
		srand(time(0) + i);
		std:: cout << "thread #" << threadNum << " in iteration" << i <<  std::endl;

		// random number [0,9]
		int random = (rand() % 10);

			

		// 20 % accumulate 
		if ( random < 2){
			std:: string key = "user" + std:: to_string( rand() % 501);
			int32_t value = (rand() % 512) - 256;
			m.accumulate( key, value);

			// keep track
			keyVector.push_back( key);
			numOfKeysInVector += 1;
			std:: cout << "thread #" << threadNum << " in 20 %. Iteration" << i << " value: " << value <<  std::endl;

			threadSum += value;
			
		}
		// 80% lookup 
		else {
			int32_t v;

			// if keyVector is not empty lockup  
			if (numOfKeysInVector > 0){
				std:: cout << "thread #" << threadNum << " in 80 % " << i <<  std::endl;
				int i = rand() % numOfKeysInVector;
				bool result = m.lookup(keyVector[i], v);
				// if the lookup returned false then fatal error !!!!
				if ( !result ) {
					std:: cout << "Fatal Error!! - Key Lost" << std::endl;
					exit(EXIT_FAILURE);
				}
			}

			// if keyVector is empty just proceed to next iteration 
		}
	}
	std:: cout << "thread #" << threadNum << " before finally pushing to q "<<  std::endl;

	// push accumulated threadSum 
	std:: cout << "thread #" << threadNum << " value of threadSum: " << threadSum << std::endl;
	q.push(32);


	std:: cout << "END --- thread #" << threadNum << std::endl;
}



int main (int argc, char *argv[]){
	int option = -1;
	int NUM_OF_THREADS;
	

	while ( (option = getopt( argc, argv, ":n:")) != -1 ){
		switch (option )
		{
			case 'n' : NUM_OF_THREADS = std::stoi(optarg);
				break;
			case '?' : 
				std::cout << "Unrecognized option !" << std ::endl;
				break;	
		}
	}

	std:: cout << "Number of Threads : "<< NUM_OF_THREADS << std::endl;
	std:: cout << "--------------------------------------"<< std::endl;

	// instatiate ThreadSafeKVStore & ThreadSafeListenerQueue
	ThreadSafeKVStore <std::string, int32_t > m;
	ThreadSafeListenerQueue < int32_t > q;
	std:: thread threadArray[NUM_OF_THREADS];

	// start threads 
	for (int i=0; i < NUM_OF_THREADS ; i ++ ){
		threadArray[i] = std::thread (test, std::ref(m), std::ref(q), i);
	}

	// listen on q
	int32_t listenSum = 0;
	int32_t element;
	for (int i=0; i < NUM_OF_THREADS ; i ++ ){
		//q.listen(element);
		//std:: cout << " In listen" << std::endl;
		listenSum += element;
	}



	// join threads 	
	for (int i=0; i < NUM_OF_THREADS ; i ++ ){
		// if ( threadArray[i].joinable()){
		// 	threadArray[i].join();	
		// }
		threadArray[i].join();
	}

	

	std:: cout << "Terminating Program..." << std::endl;

	return 0;
}

