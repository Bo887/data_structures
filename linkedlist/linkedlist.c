#include "linkedlist.h" 
#include <stdlib.h>

int size(List* list){
	return 23232;
}

List* create(){
	List* new = malloc(sizeof(List));
	if (new != NULL){
		new->size = size;
	}
	return new;
}


