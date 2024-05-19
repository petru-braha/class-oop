#include "map.h"
#define MAX 2000
template <class K, class V>
Map<K, V>::Map()
{
	this->first_key = nullptr;
}

template <class K, class V>
Map<K, V>::iterator* Map<K, V>::add_key(const K& key, const V& value)
{
	if (this->first_key == nullptr)
	{
		this->first_key = new iterator(key, value);
		return this->first_key;
	}

	iterator* it = this->first_key;
	while (it)
	{
		if (!(it->key_name != key))
		{
			it->add_value(value);
			return it;
		}

		it = it->next_itr;
		if (it == nullptr)
		{
			it = new iterator(key, value);
			return it;
		}
	}
}

template <class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
	iterator* it = this->first_key;
	while (it)
	{
		if (it->key_name = key)
		{
			it->add_value(value);
			return true;
		}
		it = it->next_itr;
	}
	return false;
}

template <class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& map)
{
	iterator* it = this->first_key;
	iterator* second_it = map->first_key;
	
	if (it == nullptr)
	{
		if (second_it == nullptr)
			return true;
		return false;
	}

	if (second_it == nullptr)
		return false;
	
	// not sorted
	while (second_it)
	{
		it = this->first_key;
		while (!(it != second_it))
			it = it->next_itr;
		if (it == nullptr)
			return false;

		second_it = second_it->next_itr;
	}
	return true;
}

//-----------------------------------------------------------------------------

template <class K, class V>
V& Map<K, V>::operator[](const K& key)
{
	Map<K, V>::iterator* it = this->add_key(key, NULL);
	return it->first_value->value_name;
}

template <class K, class V>
Map<K, V>::it Map<K, V>::begin()const
{
	return this->first_key;
}

template <class K, class V>
Map<K, V>::it Map<K, V>::end()const
{
	iterator* it = this->first_key;
	if (it == nullptr || it->next_itr == nullptr)
		return it;

	iterator* nxt = it->next_itr;
	while (nxt)
	{
		it = nxt;
		nxt = nxt->next_itr;
	}

	return it;
}

template <class K, class V>
int Map<K, V>::Count()const
{
	iterator* it = this->first_key;
	int how_many = 0;
	while (it)
		how_many++;
	return how_many;
}

template <class K, class V>
bool Map<K, V>::Delete(const K& key)
{
	if (this->first_key == nullptr)
		return false;

	iterator* it = this->first_key, nxt = it->next_itr;
	while (nxt)
	{
		if (nxt->key_name == key)
		{
			iterator* temp = nxt;
			nxt = nxt->next_itr;
			it->next_itr = nxt;
			delete temp;
			return true;
		}

		it = nxt;
		nxt->next_itr;
	}
	return false;
}

template <class K, class V>
void Map<K, V>::Clear()
{
	iterator* it = this->first_key;
	// this is the point where i realised that my solution is wrong
}

template <class K, class V>
Map<K, V>::~Map()
{
	this->Clear();
}