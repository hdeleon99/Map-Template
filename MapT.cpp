

#include "MapT.h"
#include <unordered_map>
//using namespace std;



template<class K, class T>
int MapT<K, T>::GetHashIndex(const K &key) {
    unordered_map<K,T> mapper;
    typename unordered_map<K,T>::hasher hashFunction = mapper.hash_function();
    return static_cast<int>(hashFunction(key) % numBuckets);
}

template<class K, class T>
MapT<K, T>::MapT() {
    // made 10 buckets, each bucket containing a linked list
    buckets = new forward_list<pair<K,T>>[DEFAULT_BUCKETS];
    numBuckets = DEFAULT_BUCKETS;
    // not storing anything right now so numKeys 0
    numKeys = 0;
    maxLoad = DEFAULT_LOAD;

}

template<class K, class T>
void MapT<K, T>::Add(K key, T value) {
    int bucket = GetHashIndex(key);

    // loop through all elements in bucke
    for(auto it = buckets[bucket].begin(); it != buckets[bucket].end(); ++it){
        // Found that the keys already exists in the bucket
        if (it->first == key){
            it->second = value; // override the value
            return;
        }
    }
    pair<K, T> keyValuePair;
    keyValuePair.first = key;
    keyValuePair.second = value;

    ++numKeys;
    buckets[bucket].push_front(keyValuePair);
}

template<class K, class T>
void MapT<K, T>::Remove(K key) {

}

template<class K, class T>
bool MapT<K, T>::Contains(K key) {
    return false;
}

template<class K, class T>
double MapT<K, T>::LoadFactor() {
    return 0;
}

template<class K, class T>
void MapT<K, T>::SetMaxLoad(double maxLoad) {

}

template<class K, class T>
void MapT<K, T>::Rehash(int numBuckets) {

}

template<class K, class T>
T MapT<K, T>::operator[](K key) {
    return nullptr;
}

template<class K, class T>
void MapT<K, T>::ResetIterator() {

}

template<class K, class T>
pair<K, T> MapT<K, T>::GetNextPair() {
    return pair<K, T>();
}



