#include "pch.h"
#include <limits>
#define MAX 100

TEST(array, multiple_objects)
{
	size_t index = 1, n = 5;
	int elements[MAX] = { 1, 2, 3, 4 };

	ASSERT_TRUE(n > 1);
}

TEST(array, sorted)
{
	size_t index = 1, n = 0;
	int elements[MAX] = { 1, 2, 3, 4 };

	while (index < n)
	{
		ASSERT_TRUE(elements[index - 1] < elements[index]);
		index++;
	}
}