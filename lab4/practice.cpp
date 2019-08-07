# include <iostream>
# include <map>
# include <iterator>
#include <string>
#include <vector>
#include <utility>
# include "maze.hpp"
#include <ctime>
#include <pthread.h>
#include <thread>
#include <iterator>
#include "threadSafeKVStore.h"

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

	ThreadSafeKVStore <int,char > m; 


void threadFunc(){
	m.insert(20,'e');
	m.truncate(2);

}


int main( ){


	//pthread_rwlock_wrlock( &rwlock);
	
	
	std::thread a[1];
		a[0]	= std:: thread( threadFunc);
	
	m.insert( 10,'a');
	m.insert( 10,'b');
	
	m.insert( 10,'c');
	m.insert( 20,'d');



	for (auto itr = m.begin(); itr != m.end(); ++itr) 
    { 
        std:: cout  <<  '\t' << itr->first
              <<  '\t' << itr->second << '\n'; 
    } 
    std::cout << std::endl; 
     


	a[0].join();





	//std::srand(std::time(0));			// Remember to do this!
	
	// Maze m(20,20);
	// std::cout << m;
	// std::vector<int> c;

	// std::cout << "Start at (" << m.getStart().row << ", " << m.getStart().col << ")" << std::endl;
	// std::cout << "Finish at (" << m.getFinish().row << ", " << m.getFinish().col << ")" << std::endl;
	// c.push_back(1);
	// c.push_back(2);
	// c.push_back(3);





	// m.insert( std:: pair < int, char> (10, 'b'));
	// m.insert( std:: pair < int, char> (10, 'a')); 
	
	// m.insert( std:: pair < int, char> (10, 'c'));
	// m.insert( std:: pair < int, char> (20, 'd'));
	



    //m.remove(10);
    //m.truncate (2);
    // std:: cout  <<  '\t' << m[6].first
    //           <<  '\t' << m[6].second << '\n'; 

    for (auto itr = m.begin(); itr != m.end(); ++itr) 
    { 
        std:: cout  <<  '\t' << itr->first
              <<  '\t' << itr->second << '\n'; 
    } 
    std::cout << std::endl; 
    //std::cout <<m.size() <<  std::endl; 
    
    //std:: cout << (m.begin() ++) -> second << std:: endl;

    // find just finds the very first one 
    //std:: cout << m.find(10) -> second << std:: endl;
	


	return 0;
}