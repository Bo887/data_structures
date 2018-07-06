#include <stdio.h>
#include <assert.h>

#include "linkedlist.h"

int main(){
	
	//test constructor
	List* list = create();
	assert(list != NULL);

	//test push_back and size
	list->push_back(list, 4);
	assert(list->size(list) == 1);

	//test push_front and size
	list->push_front(list, 3);
	assert(list->size(list) == 2);

	//test push_front/push_back and size
	list->push_front(list, 2);
	list->push_front(list, 1);
	list->push_front(list, 0);
	list->push_back(list, 5);
	assert(list->size(list) == 6);

	//make sure the list prints correctly
	list->print(list);

	//test that contains returns true when the list contains the value
	for(int i=0; i<6; i++){
		assert(list->contains(list, i));
	}
	
	//test that contains returns false when the list doesn't contain the value
	assert(!list->contains(list, -1));
	assert(!list->contains(list, 40));
	assert(!list->contains(list, 84));

	//test that get works properly when the index is within range
	for(int i=0; i<6; i++){
		assert(list->get(list, i) == i);
	}
	//test that get returns -1 when the index is out of range
	assert(list->get(list, -1) == -1);
	assert(list->get(list, 6) == -1);
	assert(list->get(list, 100) == -1);

	//test pop_back
	int val = list->pop_back(list);
	assert(list->size(list) == 5);
	assert(val == 5);

	//test pop_front
	val = list->pop_front(list);
	assert(list->size(list) == 4);
	assert(val == 0);

	//test that remove returns -1 if the specified value doesn't exist
	int rc = list->remove(list, 5);
	assert(rc == -1);

	//test remove returns the correct code if the specified value exists, and correctly removes the element
	rc = list->remove(list, 2);
	assert(rc == 0);
	assert(list->size(list) == 3);

	list->remove(list, 1);
	list->remove(list, 3);
	list->remove(list, 4);

	//test remove returns -1 when the list is empty
	rc = list->remove(list, 3);
	assert(rc == -1);

	assert(list->size(list) == 0);

	//test popping when the list is empty
	rc = list->pop_back(list);
	assert(rc == -1);
	rc = list->pop_front(list);
	assert(rc == -1);

	//test pushing after the list has been emptied
	list->push_back(list, 3);
	assert(list->get(list, 0) == 3);
	list->pop_back(list);
	assert(list->get(list, 0) == -1);

	list->push_front(list, 2);
	assert(list->get(list, 0) == 2);
	list->pop_front(list);
	assert(list->get(list, 0) == -1);

	destroy(list);
	assert(list == NULL);

	return 0;
}
