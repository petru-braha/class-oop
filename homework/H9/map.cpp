#include "map.h"

template <class K, class V>
Map<K, V>::Map()
{

}


void Set();
bool Get(const K& key, V& value); //copy the value associated to parameter key into the parameter value and returns true.
bool Includes(const Map<K, V>& map);

V operator [] (K key);

entry* begin()const;
entry* end()const;

int  Count()const;
void Clear(); // delete everything
bool Delete(const& K key); //just one entry
~Map();