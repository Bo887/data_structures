#include "linkedlist.h" 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Node* create_node(int val){
	Node* node = malloc(sizeof(node));
	node->val = val;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void reset(List* list){
	list->start = NULL;
	list->end = NULL;
	list->m_size = 0;
}

void push_front(List* this, int val){
	Node* node = create_node(val);
	if (this->size(this) == 0){
		this->start = node;
		this->end = node;
		this->m_size++;
		return;
	}
	this->start->prev = node;
	node->next = this->start;
	this->start = node;
	this->m_size++;
}

void push_back(List* this, int val){
	Node* node = create_node(val);
	if (this->size(this) == 0){
		this->end = node;
		this->start = node;
		this->m_size++;
		return;
	}
	this->end->next = node;
	node->prev = this->end;
	this->end = node;
	this->m_size++;
}

int pop_front(List* this){
	//if list is empty, return -1
	if (this->size(this) == 0) return -1;
	int rv = this->start->val;
	//special case if list only has 1 item
	if (this->size(this) == 1){
		reset(this);
		return rv;
	}
	Node* orig = this->start;
	this->start = this->start->next;
	this->start->prev = NULL;
	this->m_size--;
	return rv;
}

int pop_back(List* this){
	if (this->size(this) == 0) return -1;
	int rv = this->end->val;
	if (this->size(this) == 1){
		reset(this);
		return rv;
	}
	Node* orig = this->end;
	this->end = this->end->prev;
	this->end->next = NULL;
	this->m_size--;
	return rv;
}

int l_remove(List* this, int val){
	for(Node* it = this->start; it != NULL; it = it->next){
		if (it->val == val){
			if (it->prev == NULL){
				return pop_front(this);
			}
			else{
				it->prev->next = it->next;
			}
			if (it->next == NULL){
				return pop_back(this);
			}
			else{
				it->next->prev = it->prev;
			}
			free(it);
			this->m_size--;
			return 0;
		}
	}
	return -1;
}

int size(List* this){
	return this->m_size;
}

int contains(List* this, int val){
	Node* curr = this->start;
	while(curr != NULL){
		if (curr->val == val){
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

int get(List* this, int index){
	if (index < 0 || index > this->size(this)-1) return -1;
	Node* curr = this->start;
	for(int cnt = 0; cnt < index; cnt++){
		curr = curr->next;
	}
	return curr->val;
}

void print(List* this){
	Node* it = this->start;
	//printf("SIZE:%d\n", this->size(this));
	while(it != NULL){
		printf("%d ", it->val);
		it = it->next;
	}
	printf("\n");
}

List* create(){
	List* list = malloc(sizeof(List));
	if (list != NULL){
		list->start = NULL;	
		list->end = NULL;
		list->m_size = 0;
		list->push_front = push_front;
		list->push_back = push_back;
		list->pop_front = pop_front;
		list->pop_back = pop_back;
		list->contains = contains;
		list->get = get;
		list->remove = l_remove;
		list->size = size;
		list->print = print;
	}
	return list;
}

void destroy(List* this){
	free(this);
	this = NULL;
}

