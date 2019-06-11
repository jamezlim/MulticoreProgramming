#ifndef LAB0_H
#define LAB0_H

template <typename K, typename V>
class multimap {
public:
	std::vector<K> keys;
	std::vector<V> values;	
	multimap();
	//~multimap();
	bool insert (const K& key, const V& value);
	bool find(const K& key);
	bool find(const K& key, std::vector<V>& values);
	int remove(const K& key);
};

#include "lab0.cpp"
#endif