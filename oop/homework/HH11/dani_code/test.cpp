#pragma warning(disable: 26495)

#include <limits>
#include "pch.h"
#include "dani_code.h"
#define MAX 100
typedef unsigned int lng;
typedef unsigned long long nat;

TEST(array, multiple_objects)
{
	std::initializer_list<int> numbers{ 1, 2, 3, 4 };
	StaticVector<int> all_numbers(numbers);

	ASSERT_TRUE(numbers.size() > 1);

	lng i = 0;
	for (const auto& elem : numbers)
	{
		ASSERT_TRUE(elem == all_numbers[i]);
		i++;
	}
}

TEST(array, correct_size)
{
	std::initializer_list<char> letters{ 'a', 'b', 'a' };
	StaticVector<char> alphabet(letters);

	ASSERT_TRUE(alphabet.get_size() == letters.size());
}

TEST(array, negative_numbers)
{
	StaticVector<long long int> Z(std::initializer_list<long long int>{1, INT_MIN, CHAR_MAX, LLONG_MAX, 0, LLONG_MIN});

	ASSERT_NO_THROW(Z.mergeSort());
	for (lng i = 1; i < Z.get_size(); i++)
		ASSERT_TRUE(Z[i - 1] < Z[i]);
}

TEST(array, large_numbers)
{
	StaticVector<nat> R(std::initializer_list<nat>{ INT_MAX, CHAR_MAX, LLONG_MAX, 0, ULLONG_MAX, ULLONG_MAX - 1, ULLONG_MAX });
	ASSERT_NO_THROW(R.mergeSort());
	for (lng i = 1; i < R.get_size(); i++)
		ASSERT_TRUE(R[i - 1] < R[i]);
}

TEST(array, sort_casual)
{
	std::initializer_list<int> numbers{ 6, 2, 1, 4 };
	StaticVector<int> elements(numbers);

	ASSERT_NO_THROW(elements.mergeSort());
	lng index = 1;
	while (index < numbers.size())
	{
		ASSERT_TRUE(elements[index - 1] < elements[index]);
		index++;
	}
}

TEST(array, sort_sorted)
{
	std::initializer_list<int> numbers{ 1, 2, 3, 4 };
	StaticVector<int> elements(numbers);

	ASSERT_NO_THROW(elements.mergeSort());

	lng index = 1;
	while (index < numbers.size())
	{
		ASSERT_TRUE(elements[index - 1] < elements[index]);
		index++;
	}
}

TEST(array, out_of_bounds)
{
	StaticVector<const char*> banana(std::initializer_list<const char*>{"hello", "dear", "portocale"});
	ASSERT_THROW(banana[5], std::out_of_range);
}

TEST(array, sort_null)
{
	StaticVector<char*> letters(std::initializer_list<char*>{ nullptr, nullptr, nullptr });
	ASSERT_NO_THROW(letters.mergeSort());
	for (lng i = 1; i < letters.get_size(); i++)
		ASSERT_TRUE(letters[i - 1] == letters[i]);

	StaticVector<char*> numbers(std::initializer_list<char*>{ (char*)"1" });
	ASSERT_NO_THROW(numbers.mergeSort());
	ASSERT_FALSE(numbers[0] != (char*)"1");
}

TEST(array, sort_same_element)
{
	std::initializer_list<float> one{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, };
	StaticVector<float> two_one(one);
	ASSERT_NO_THROW(two_one.mergeSort());

	for (lng i = 1; i < two_one.get_size(); i++)
		ASSERT_TRUE(two_one[i - 1] == two_one[i]);

}

// the code is too wrong damn