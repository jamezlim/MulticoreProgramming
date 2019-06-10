#include <iostream>
#include <vector>
#include <string>

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




int main (){
	multimap <std::string,int> a;
	std:: vector<int> valuesWithSameKey;

	a.insert("first",1);
	a.insert("second",2);
	a.insert("third",3);
	a.insert("fourth",4);
	a.insert("fourth",5);
	a.insert("fourth",6);
	a.insert("fourth",7);

	for (int i = 0; i < a.keys.size(); i ++ ) std:: cout << a.keys[i]<< std:: endl;
	for (int i = 0; i < a.keys.size(); i ++ ) std:: cout << a.values[i]<< std:: endl;	
	// std:: cout << a.find("first");
	//a.find ( "fourth",valuesWithSameKey);
	// std:: cout << valuesWithSameKey[0];
	// std:: cout << valuesWithSameKey[1];
	// std:: cout << valuesWithSameKey[2];
	// std:: cout << valuesWithSameKey[3];
	// std:: cout << "size is:" << valuesWithSameKey.size() <<std:: endl;

	// std:: cout << a.remove("fourth") << std::endl;
	// valuesWithSameKey.erase(valuesWithSameKey.begin());
	// std:: cout << valuesWithSameKey[0];
	// std:: cout << valuesWithSameKey[1];
	// std:: cout << valuesWithSameKey[2];
	// std:: cout << valuesWithSameKey[3];
	// std:: cout << valuesWithSameKey[4];
	// std:: cout << "size is:" << valuesWithSameKey.size() <<std:: endl;
	std:: cout << "how many were removed?" <<  a.remove("fourth") << std::endl;

	for (int i = 0; i < a.keys.size(); i ++ ) std:: cout << a.keys[i]<< std:: endl;
	for (int i = 0; i < a.keys.size(); i ++ ) std:: cout << a.values[i]<< std:: endl;

	return 0;
}