#include <iostream>
#include <getopt.h> // arguments
#include <vector>
#include <ctime>
#include "threadSafeKVStore.h"
#include "threadSafeListenerQueue.h"




int main (int argc,char ** argv){
	srand(time(0));
	int option = -1;
	int NUM_OF_THREADS, THRESHOLD, ROWS, COLUMNS, GLENGTH;

	// getopt
	while ( (option = getopt( argc, argv, ":n:d:")) != -1 ){
		switch (option )
		{
			case 'n' : NUM_OF_THREADS = std::stoi(optarg);
				break;
			case 'g' : THRESHOLD = std::stoi(optarg);
				break;
			case 'r' : ROWS= std::stoi(optarg);
				break;
			case 'c' : COLUMNS = std::stoi(optarg);
				break;	
			case 'l' : GLENGTH = std::stoi(optarg);
				break;						
			case '?' : 
				std::cout << "Unrecognized option !" << std ::endl;
				break;	
		}
	}

	std:: cout << "Number of Threads: "<< NUM_OF_THREADS << std::endl;
	std:: cout << "Finding best route for maze... "<< std::endl;
	std:: cout << "------------------------------------------"<< std::endl;

	std::vector <std::vector<int>>  geneVec;
	int random;
	// create genomes of GLENGTH ( 4 * NUM_OF_THREADS) 
	for ( int i = 0 ; i < 4 * NUM_OF_THREADS; i ++){
		for (int j = 0; j < GLENGTH ; j ++){
			random = rand() %5;
		}
	}
	
	
	int random2 = rand() %5;
	std::cout << random2 << std::endl;

}	