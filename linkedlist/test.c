#include <stdio.h>
#include "linkedlist.h"

int main(){
	List* list = create();
	if (list == NULL){
		printf("HIHIHIHIHI\n");
	}
	printf("test\n");
	printf("%d\n", list->size());

}

