#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	char *data;
	struct Node *next;
};
struct Node* find(struct Node** head, int index) {
	struct Node* temp = *head;
	if (*head == NULL) {
		*head = (struct Node*)malloc(sizeof(struct Node));
		head->data = head;
		head->next = NULL;
	}
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}
void Insert(struct Node** head, int index, char* data) {
	struct Node *temp = find(head, index);
	struct Node *t = (struct Node*)malloc(sizeof(struct Node));
	strcpy(t->data, data);
	t->next = temp->next;
	temp->next = t;
	return;
}

void deletenode(struct Node** head, int index) {
	struct Node *temp = find(head, index - 1);
	struct Node *t = temp->next;
	temp->next = temp->next->next;
	free(t);
	return;
}
int main() {
	struct Node* head = NULL;
	//find();
	//Insert();
	//delete();
	printf("\nlinked list");
	return 0;
}