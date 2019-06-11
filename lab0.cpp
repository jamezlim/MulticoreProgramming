#include <vector>
#include "lab0.h"

//constructor
template <typename K, typename V>
multimap<K,V> :: multimap(){
	
}

template <typename K, typename V>
bool multimap<K,V> :: insert(const K& key, const V& value){
	keys.push_back(key);
	values.push_back(value);
	return true;
}

template <typename K, typename V>
bool multimap<K,V> :: find(const K& key){
	for (int i = 0; i < keys.size(); i ++ )
		if ( key == keys[i]) return true;
	return false;
}

template <typename K, typename V>
bool multimap<K,V> :: find(const K& key, std::vector<V>& valuesWithSameKey){
	bool flag = false;
	for (int i = 0; i < keys.size(); i ++ ){
		if ( key == keys[i]){ 
			valuesWithSameKey.push_back(values[i]);
			flag = true;
		}
	}
	return flag;
}

template <typename K, typename V>
int multimap<K,V> :: remove(const K& key){
	int count = 0;
	for (int i = 0; i < keys.size(); i ++ ){
		if ( key == keys[i]){ 
			count ++;
			keys.erase(keys.begin() + i);
			values.erase(values.begin() + i);
			i --;
		}
	}
	return count;
}
