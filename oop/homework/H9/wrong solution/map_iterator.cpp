#include "map.h"

template <class K, class V>
Map<K, V>::iterator::iterator(const K& key, const V& value)
{
	this->key_name = key;
	this->next_itr = nullptr;
	this->first_value->value_name = value;
	this->first_value->next_val = nullptr;
}

template <class K, class V>
void Map<K, V>::iterator::add_value(V next_value)
{
	iterator::value* val = this->first_value;
	if (val == nullptr)
	{
		this->first_value = new value(next_value, nullptr);
		return;
	}

	iterator::value* nxt = val->next_val;
	if (nxt == nullptr)
	{
		nxt = new value(next_value, nullptr);
		return;
	}

	while (nxt)
	{
		if (nxt->value_name == next_value)
			return;
		val = nxt;
		nxt = nxt->next_val;
	}

	nxt = new value(next_value, nullptr);
}

template <class K, class V>
void Map<K, V>::iterator::operator++()
{
	this = this->next_itr;
}

template <class K, class V>
bool Map<K, V>::iterator::operator!=(iterator* second_itr)
{
	if (this->key_name != second_itr->key_name)
		return true;
	if (this->first_value != second_itr->first_value)
		return true;

	iterator::value* val = this->first_value, second_val = second_itr->first_value;
	if (val->value_name == nullptr)
	{
		if (second_val == nullptr)
			return false;
		return true;
	}

	if (second_val == nullptr)
		return true;

	while (val->value_name == second_val->value_name)
	{
		if (val == nullptr) // both nullptr
			return true;
		val = val->next_val;
		second_val = second_val->next_val;
	}

	if ((val == nullptr && second_val) || (val && second_val == nullptr))
		return true;
	return false;
}

template <class K, class V>
bool Map<K, V>::iterator::exists_value(const V& value)
{
	iterator::value* val = this->first_value;
	if (val == nullptr)
		return false;
	if (val->value_name == value)
		return true;

	iterator::value* nxt = val->next_val;
	while (nxt)
	{
		if (nxt->value_name == value)
			return true;

		val = nxt;
		nxt = nxt->next_val;
	}

	return false;
}

// delete values
template <class K, class V>
void Map<K, V>::iterator::delete_value(const V& value)
{
	iterator::value* val = this->first_value;
	if (val == nullptr)
		return;

	if (val->value_name == value)
	{
		delete val;
		if (val->next_val == nullptr)
		{
			this->first_value = nullptr;
			return;
		}

		this->first_value = this->first_value->next_val;
	}
	
	iterator::value* nxt = val->next_val;
	while (nxt)
	{
		if (nxt->value_name == value)
		{
			iterator::value* temp = nxt;
			nxt = nxt->next_val;
			val->next_val = nxt;
			delete temp;
			return;
		}

		val = nxt;
		nxt = nxt->next_val;
	}
}

template <class K, class V>
void Map<K, V>::iterator::delete_values_recursive(value*& pointer_head)
{
	if (pointer_head == nullptr)
		return;
	
	this->delete_values_recursive(pointer_head->next_val);
	delete pointer_head; pointer_head = nullptr;
}

template <class K, class V>
Map<K, V>::iterator::~iterator()
{
	delete_values_recursive(this->first_value);
}
