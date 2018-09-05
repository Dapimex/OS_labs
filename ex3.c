#include <stdio.h>
#include <stdlib.h>

struct Node {
    
	int value;
	int index;
	struct Node * next;
	struct Node * previous;

};

void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }

}


void insert_node(struct Node* node, int i, int val) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = val;
    struct Node* current = node; //another node for avoiding NULL at the end
    struct Node* prev = current; //finding previous node for the new one(either last in list or with index-1)
    while ((current != NULL)&&(current->index != i - 1)) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {prev = current;} //if it is not last one, then current will be previous for the new node
    new_node->previous = prev;
    new_node->index = prev->index + 1;
    new_node->next = prev->next;
    prev->next = new_node;
    prev->next->previous = new_node;
    current = new_node->next;
    while (current != NULL) {
        current->index++;
        current = current->next;
    }
}


void delete_node(struct Node* node, int i) {
    while((node != NULL)&&(node->index != i)) {
        node = node->next;
    }
    node->previous->next = node->next;
    node->next->previous = node->previous;
    node = node->next;
    while (node != NULL) {
        node->index--;
        node = node->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->value = 1;
    head->index = 0;
    print_list(head);
    printf("\n");
    insert_node(head, 1, 10);
    print_list(head);
    printf("\n");
    insert_node(head, 5, 15);
    print_list(head);
    printf("\n");
    insert_node(head, 1, 7);
    print_list(head);
    printf("\n");
    delete_node(head, 1);
    print_list(head);
    printf("\n");
    return 0;
}