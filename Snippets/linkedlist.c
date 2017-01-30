#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist_node {
	int val;
	struct linkedlist_node* next;
} node;

typedef struct linkedlist {
	node* head;
	node* tail;
} ll;

//Prototypes
ll* init_ll();
void push(ll* ll, int val);
void print_ll(ll* ll);
void free_ll(ll* ll);

//Main
int main(int argc, char const **argv){
	ll* my_ll = init_ll(0,1);
	for (int i = 2; i < 10; i++){
		push(my_ll, i);
	}
	print_ll(my_ll);
	free_ll(my_ll);
	return EXIT_SUCCESS;
}

ll* init_ll(int head_val, int tail_val){
	ll* ll = NULL;
	ll = malloc(sizeof(ll));
	if (ll == NULL){
		fprintf(stderr, "ERROR- maloc ll\n");
		exit(EXIT_FAILURE);
	}
	ll->head = NULL;
	ll->tail = NULL;

	ll->head = malloc(sizeof(node));
	if (ll->head == NULL){
		fprintf(stderr, "ERROR- maloc head\n");
		exit(EXIT_FAILURE);
	}
	ll->head->val = head_val;
	ll->head->next = malloc(sizeof(node));
	if (ll->head->next == NULL){
		fprintf(stderr, "ERROR- maloc head->next\n");
		exit(EXIT_FAILURE);
	}
	ll->head->next->val = tail_val;
	ll->head->next->next = NULL;
	ll->tail = ll->head->next;
	ll->tail->next = NULL;
	return ll;
}

//add a node at the end
void push(ll* ll, int val){
    node* current = ll->head;
    while (current->next != NULL) {
        current = current->next;
    }

    //now we can add a new variable
    current->next = malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
 	//update the tail
    ll->tail = current->next;
}

void print_ll(ll* ll){
    node* current = ll->head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void free_ll(ll* ll){
	node* current = ll->head;
	node* tmp = NULL;
    while (current != NULL) {
    	tmp = current;
        current = current->next;
        free(tmp);
    }
}