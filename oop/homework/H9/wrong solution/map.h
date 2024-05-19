#pragma once
template <class K, class V>
class Map
{
	typedef iterator* it;
	struct iterator
	{
		K key_name;
		iterator* next_itr;
		
		struct value
		{
			V value_name;
			value* next_val;

			value() : value_name(NULL), next(nullptr){}
			value(const V& next_value, value* nxt):value_name(next_value), next_val(nxt){}
		};
		value* first_value;
		
		iterator(): key_name(NULL), next(nullptr), first_value(nullptr){}
		iterator(const K& key, const V& value);
		void add_value(V next_value); // checks if the value already exists
		bool exists_value(const V& value);
			 
		void operator++();
		bool operator!=() { return this != nullptr ? true : false; }
		bool operator!=(iterator* second_itr);

		void delete_value(const V& value);
		void delete_values_recursive(value*& pointer_head);
		~iterator();
	};

	iterator* first_key;
	iterator* add_key(const K& key, const V& value);
	
public:
	Map();
	void Set(iterator* index, const V& value) { index->add_value(value); }
	bool Get(const K& key, V& value);
	bool Includes(const Map<K, V>& map);
	
	V& operator[](const K& key); // what will happen here?
	it begin()const;
	it end()const;

	int  Count()const;
	bool Delete(const K& key);
	void Clear(); // everything
	~Map();
};

// map = multiple keys // key = multiple values
// iterator == index == key
// int + const char

