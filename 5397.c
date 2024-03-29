#include <stdio.h>
#include <stdlib.h>

char L[1000001];

typedef struct _node{
	char ch;
	struct _node* prev;
	struct _node* next;
}Node;

void printNode(Node* head) {
	Node* curr = head->next;
	if (curr->next != NULL) {
		do {
			printf("%c", curr->ch);
			curr = curr->next;
			free(curr->prev);
		} while (curr->next != NULL);
	}
	printf("%c", curr->ch);

	free(head);
	free(curr);
}

void password() {
	Node* head = NULL; // first Node
	Node* curr = NULL; // (current) cursor Node
	Node* temp = NULL; // temporary Node
	int i = 0;
	char ch;

	do {	// Until the character comes out
		ch = L[i++];
		if (ch != '<' && ch != '>' && ch != '-') {
			curr = (Node*)malloc(sizeof(Node)); 
			head = (Node*)malloc(sizeof(Node));

			curr->ch = ch;
			curr->prev = head;
			curr->next = NULL;
			
			head->next = curr;
			head->prev = NULL;
			break;
		}
	} while (1);

	while (L[i] != 0) {
		ch = L[i];

		switch (ch) {
		case '<':	// left
			if (curr->prev != NULL) {
				curr = curr->prev;
			}
			break;
		case '>':	// right
			if (curr->next != NULL) {
				curr = curr->next;
			}
			break;
		case '-':	// delete
			if (curr != head) {
				temp = curr;
				curr = curr->prev;
				curr->next = temp->next;
				if (temp->next != NULL) {
					curr->next = temp->next;
					temp->next->prev = curr;
				}
				free(temp);
			}
			break;
		default:	// character
			temp = (Node*)malloc(sizeof(Node));	// create node
			temp->ch = ch;
			temp->prev = curr;
			temp->next = curr->next;

			if (curr->next != NULL) 
				curr->next->prev = temp;
			curr->next = temp;
			curr = temp;
			break;
		}

		i++;
	}
	printNode(head);
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", L);
		password();
		printf("\n");
	}

	return 0;
}
