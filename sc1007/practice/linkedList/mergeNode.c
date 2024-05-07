// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;


void printList(ListNode *head);
int insertNode(ListNode **ptrHead, int index, int value);
void mergeNode(ListNode **ptrHead);
ListNode * findNode(ListNode *head, int index);


int main() {
    // Write C code here
    int c;
    ListNode *head = NULL;
    
    int length = 4;
    
    for (int i = 0; i < length; i++) {
        insertNode(&head, i, i + 1);
    }
    
    printList(head);
    mergeNode(&head);
    
    printf("The linked list after merging is:\n");
    printList(head);

    return 0;
}

void mergeNode(ListNode **ptrHead) {
    // set up pointers
    ListNode *prev = *ptrHead, *cur = prev->next;
    
    // sanity check
    if (prev == NULL) {
        return;
    }
    
    // traverse linked list
    while (cur != NULL) {
        // merge contents of two nodes
        prev->num += cur->num;
        
        // if even number of nodes, cleanup and return
        if (cur->next == NULL) {
            free(prev->next);
            prev->next = NULL;
            return;
        }
        
        // move pointers along linked list
        cur = cur->next;
        free(prev->next);
        prev->next = NULL;
        
        prev->next = cur;
        prev = cur;
        
        // if odd number of nodes, return
        if (cur->next == NULL) {
            return;
        }
        
        cur = cur->next;
    }
}


void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}


int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}
