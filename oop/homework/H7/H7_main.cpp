#include <stdio.h>
#include "ex 1/H7_literals.h"

void H7_literals_main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("celcius of a is %.2f.\ncelcius of b is %.2f.\n", a,  b);

}

#include "ex 2/H7_tree.h"
#include "ex 2/H7_tree.cpp"
void H7_tree_main()
{
    //tree<int> maxheap;
	/*
	auto maxheap_first = maxheap.root;

	// 20: 10 11 12 13 
	maxheap.add_node(maxheap_first, 10);
	maxheap.add_node(maxheap_first, 11);
	maxheap.add_node(maxheap_first, 12);
	maxheap.add_node(maxheap_first, 13);
	
	// 20: 10 9 12 13
	maxheap.insert(maxheap_first, 1, 9);

	// 13: 5 6 8
	maxheap_first = maxheap.get_node(maxheap_first, 3);
	maxheap.add_node(maxheap_first, 6);
	maxheap.add_node(maxheap_first, 7);
	maxheap.add_node(maxheap_first, 8);
	maxheap.insert(maxheap_first, 0, 5);
	maxheap.insert(maxheap_first, 1, 6);

	// 13: 5 6
	auto p_node = maxheap_first;
	p_node = maxheap.get_node(p_node, 2);
	maxheap.delete_node(p_node);
	maxheap_first = nullptr;

	if (p_node)
		printf("error: can not delete node.\n");

	p_node = maxheap.get_node(maxheap.root, 0);
	maxheap.add_node(p_node, 8);
	maxheap_first = maxheap.find(maxheap.root, 8, is_equal);

	maxheap.add_node(maxheap_first, 7);
	maxheap.add_node(maxheap_first, 4);
	maxheap.add_node(maxheap_first, 3);
	maxheap.add_node(maxheap_first, 3);
	maxheap.add_node(maxheap_first, 2);
	maxheap.add_node(maxheap_first, 1);
	maxheap.sort(maxheap_first, nullptr); // uses the operator
	//maxheap.sort(maxheap_first, maxheap.compare); // doesn't use the operator
	
	size_t nr_nodes = maxheap.cunt(maxheap.root);

	maxheap.delete_node(maxheap_first);
	*/
	printf("does not work yet");
}

/*
	 20
10  9  12    13
8			5  6
1 2 3 3 4 7
*/

#include "extra/H7_vector_extra.h"
int compare_ints(int x, int y) 
{	
	if (x == y)
		return 0;
	return x < y ? -1 : 1;
}

int H7_vector_extra_main() {
	Vector<int> v;

	// index, element
	v.insert(0, 10);
	v.insert(1, 5);
	v.insert(2, 20);
	Vector<int> w(v);

	// index
	v.remove(0);
	v.sort(compare_ints);
	printf("%d\n", w[0]); 

	v.print();
	return 0;
}
