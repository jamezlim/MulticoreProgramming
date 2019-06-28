#include "threadSafeKVStore.h"

//constructor
template <typename K, typename V>
ThreadSafeKVStore<K,V> :: ThreadSafeKVStore(){
}

//print function 
template <typename K, typename V>
void ThreadSafeKVStore<K,V> :: print(){
	for ( itr = map.begin(); itr != map.end();itr ++)
		std::cout << "[" << itr -> first << "->" << itr -> second << "] ";
	
}

template <typename K, typename V>
bool ThreadSafeKVStore<K,V> :: insert(const K key, const V value){
	mtx.lock();
	map[key] = value;
	mtx.unlock();
	return true;
}

template <typename K, typename V>
bool ThreadSafeKVStore<K,V> :: accumulate(const K key, const V value){
	mtx.lock();
	itr = map.find( key);
	// if key is found 
	if ( itr != map.end()) {
		V temp = itr -> second;
		map[key] = temp + value;
	}
	// if key is not found 
	else map[key] = value;
	mtx.unlock();
	return true;
}

template <typename K, typename V>
bool ThreadSafeKVStore<K,V> :: lookup(const K key, V& value){
	mtx.lock();
	itr = map.find( key);

	// if key is present 
	if ( itr != map.end()) {
		value = itr -> second;
		mtx.unlock();
		return true;
	}
	else {
		mtx.unlock();
		return false;
	}
}


template <typename K, typename V>
bool ThreadSafeKVStore<K,V> :: remove (const K key){
	mtx.lock();
	if ( map.erase(key) >= 0  ){
		mtx.unlock();
		return true;
	}
	else {
		mtx.unlock();
		return false;
	}
	
	
}
