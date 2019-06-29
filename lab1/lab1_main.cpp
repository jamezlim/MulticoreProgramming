#include <string>
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <thread>
#include <vector>
#include <pthread.h>
#include <chrono>
#include "threadSafeKVStore.h"
#include "threadSafeListenerQueue.h"





int NUM_OF_TEST_RUN = 10000;

void test(ThreadSafeKVStore <std::string, int32_t >& m , ThreadSafeListenerQueue < int32_t >& q, int threadNum, std::chrono::steady_clock::time_point &lastTerminationTime){
	// execution time variable 
	auto begin = std:: chrono::steady_clock :: now();

	//std::cout << "inside test thread #" << threadNum << std ::endl;
	int32_t threadSum = 0; 
	std:: vector < std::string > keyVector;
	int numOfKeysInVector = 0;


	for (int i = 0; i < NUM_OF_TEST_RUN; i++ ){
		srand(time(0) + i);
		//std:: cout << "thread #" << threadNum << " in iteration" << i <<  std::endl;

		// random number [0,9]
		int random = (rand() % 10);

			

		// 20 % accumulate 
		if ( random < 2){
			std:: string key = "user" + std:: to_string( rand() % 501);
			int32_t value = (rand() % 513) - 256;
			m.accumulate( key, value);

			// keep track
			keyVector.push_back( key);
			numOfKeysInVector += 1;
			//std:: cout << "thread #" << threadNum << " in 20 %. Iteration" << i << " value: " << value <<  std::endl;

			threadSum += value;
			
		}
		// 80% lookup 
		else {
			int32_t value;

			// if keyVector is not empty lockup  
			if (numOfKeysInVector > 0){
				//std:: cout << "thread #" << threadNum << " in 80 % " << i <<  std::endl;
				int i = rand() % numOfKeysInVector;
				bool result = m.lookup(keyVector[i], value);
				// if the lookup returned false then fatal error !!!!
				if ( !result ) {
					std:: cout << "Fatal Error!! - Key Lost" << std::endl;
					exit(EXIT_FAILURE);
				}
			}

			// if keyVector is empty just proceed to next iteration 
		}
	}
	//std:: cout << "thread #" << threadNum << " before finally pushing to q "<<  std::endl;

	// iteration over -> push accumulated threadSum 
	//std:: cout << "thread #" << threadNum << " value of threadSum: " << threadSum << std::endl;
	q.push(threadSum);


	// time stamps
	//std:: cout << "END --- thread #" << threadNum << std::endl;
	auto end = std::chrono::steady_clock :: now();
	if ( end > lastTerminationTime) lastTerminationTime = end;
	auto exTime = end - begin;
	auto ms = std::chrono::duration_cast < std::chrono:: milliseconds> (exTime).count(); 

	std:: cout << " - > Execution time for thread #" << threadNum << ": " << ms << " ms" << std::endl;
}



int main (int argc,char ** argv){

	int option = -1;
	int NUM_OF_THREADS = 0;
	
	// getopt
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
	std:: cout << "------------------------------------------"<< std::endl;

	// instatiate ThreadSafeKVStore & ThreadSafeListenerQueue
	ThreadSafeKVStore <std::string, int32_t > m;
	ThreadSafeListenerQueue < int32_t > q;
	std:: thread threadArray[NUM_OF_THREADS];

	// time stamps for total execution time 
	auto firstExecutionTime = std::chrono::steady_clock::now();
	auto lastTerminationTime = std::chrono::steady_clock::now();

	// start threads 
	for (int i=0; i < NUM_OF_THREADS ; i ++ ){
		threadArray[i] = std::thread (test, std::ref(m), std::ref(q), i, std::ref(lastTerminationTime));
	}

	// listen on q
	int32_t listenSum = 0;
	int32_t element;
	for (int i=0; i < NUM_OF_THREADS ; i ++ ){
		q.listen(element);
		listenSum += element;
		//std:: cout << " In listen" << std::endl;
	}
	//std:: cout << "value of listenSum: " << listenSum <<  std::endl;

	// join threads 	
	for (int i=0; i < NUM_OF_THREADS ; i ++ ){
		// if ( threadArray[i].joinable()){
		// 	threadArray[i].join();	
		// }
		threadArray[i].join();
	}

	//iterating on map and adding values
	int32_t iterationSum = 0;
	for (auto itr = m.getBegin(); itr != m.getEnd(); itr ++){
		//std::cout << "[" << itr -> first << "->" << itr -> second << "] ";
		iterationSum += (itr -> second);
	}
	//std:: cout << "value of iterationSum: " << iterationSum <<  std::endl;

	if ( NUM_OF_THREADS == 0) {
		std:: cout << "No threads executed " <<  std::endl;
	}
	// Successfully synced
	else if ( iterationSum == listenSum) {
		std:: cout << "Synchronized !!! " <<  std::endl;
	}
	else {
		std:: cout << "Synchronization error somewhere!! " <<  std::endl;
	}

	// thread total time
	auto totalTime = lastTerminationTime - firstExecutionTime;
	auto ms = std::chrono::duration_cast < std::chrono:: milliseconds> (totalTime).count();
	std:: cout << " --- > Total thread execution time: " << ms << " ms" << std::endl;

	// program termination 
	std:: cout << "------------------------------------------" << std::endl;
	std:: cout << "Terminating Program..." << std::endl;

	return 0;
}

