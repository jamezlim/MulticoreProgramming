#include <iostream>
#include <vector>
#include <string>
#include "lab0.h"

int main (){
	multimap <int,int> a;
	std:: vector<int> answerKeys;

	for ( int i = 0; i < 10 ; i ++ ){ 
		for (int i = 0; i < 100 ; i ++ ){
			int key = rand()%201;
			int value = rand()%201;
			answerKeys.push_back(key);
			a.insert( key, value);
		}

		for (int i = 0; i < 100; i ++){
			if( ! (a.find( answerKeys[i]))){
				std::cout << "Test Failed" << std::endl;
				return 0;
			}
		}
		std::cout << "All Tests Passed!" << std::endl;
		answerKeys.clear();
	}	


	return 0;
}