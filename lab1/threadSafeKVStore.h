#ifndef LAB1m_H
#define LAB1m_H

#include <unordered_map>
#include <iostream>
#include <mutex>

template <typename K, typename V>
class ThreadSafeKVStore {
	std:: unordered_map < K, V> map;
	std:: mutex mtx;
	typename std:: unordered_map< K, V> :: iterator itr;
public:
	ThreadSafeKVStore();
	bool insert(const K key, const V value);
	bool accumulate(const K key, const V value);
	void print();
	bool lookup(const K key, V& value);
	bool remove(const K key);
	typename std:: unordered_map< K, V> :: iterator getBegin() { return map.begin();}
	typename std:: unordered_map< K, V> :: iterator getEnd() { return map.end();}
};

#include "ThreadSafeKVStore.cpp"
#endif