#include <stdio.h>
#include <assert.h>

#include "linkedlist.h"

int main(){
	
	//test constructor
	List* list = create();
	assert(list != NULL);

	//test push_back and size
	push_back(list, 4);
	assert(size(list) == 1);

	//test push_front and size
	push_front(list, 3);
	assert(size(list) == 2);

	//test push_front/push_back and size
	push_front(list, 2);
	push_front(list, 1);
	push_front(list, 0);
	push_back(list, 5);
	assert(size(list) == 6);

	//make sure the list prints correctly
	print(list);

	//test that contains returns true when the list contains the value
	for(int i=0; i<6; i++){
		assert(contains(list, i));
	}
	
	//test that contains returns false when the list doesn't contain the value
	assert(!contains(list, -1));
	assert(!contains(list, 40));
	assert(!contains(list, 84));

	//test that get works properly when the index is within range
	for(int i=0; i<6; i++){
		assert(get(list, i) == i);
	}
	//test that get returns -1 when the index is out of range
	assert(get(list, -1) == -1);
	assert(get(list, 6) == -1);
	assert(get(list, 100) == -1);

	//test pop_back
	int val = pop_back(list);
	assert(size(list) == 5);
	assert(val == 5);

	//test pop_front
	val = pop_front(list);
	assert(size(list) == 4);
	assert(val == 0);

	//test that remove returns -1 if the specified value doesn't exist
	int rc = delete(list, 5);
	assert(rc == -1);

	//test remove returns the correct code if the specified value exists, and correctly removes the element
	rc = delete(list, 2);
	assert(rc == 0);
	assert(size(list) == 3);

	delete(list, 1);
	delete(list, 3);
	delete(list, 4);

	//test remove returns -1 when the list is empty
	rc = delete(list, 3);
	assert(rc == -1);

	assert(size(list) == 0);

	//test popping when the list is empty
	rc = pop_back(list);
	assert(rc == -1);
	rc = pop_front(list);
	assert(rc == -1);

	//test pushing after the list has been emptied
	push_back(list, 3);
	assert(get(list, 0) == 3);
	pop_back(list);
	assert(get(list, 0) == -1);

	push_front(list, 2);
	assert(get(list, 0) == 2);
	pop_front(list);
	assert(get(list, 0) == -1);

	destroy(&list);
	assert(list == NULL);

	return 0;
}
