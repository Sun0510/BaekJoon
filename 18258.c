#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

typedef struct _queue {
	int value;
	struct _queue* prev;
	struct _queue* next;
}Queue;

void init(Queue* head, Queue* tail) {
	head->value = 0;
	head->next = NULL;
	head->prev = NULL;
	tail = head;
}

Queue* push(Queue *tail, int x) {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));

	tail->next = newQueue;
	newQueue->next = NULL;
	newQueue->prev = tail;
	newQueue->value = x;
	size++;

	return newQueue;
}

Queue* pop(Queue* head) {
	if (size == 0) {
		printf("-1\n");
		return head;
	}
	else {
		printf("%d\n", head->next->value);
		head = head->next;

		free(head->prev);
		head->prev = NULL;
		size--;

		return head;
	}
}

void is_empty() {
	if (size == 0)
		printf("1\n");
	else
		printf("0\n");
}

void print_front(Queue* head) {
	if (size == 0)
		printf("-1\n");
	else
		printf("%d\n", head->next->value);
}

void print_back(Queue* tail) {
	if (size == 0)
		printf("-1\n");
	else
		printf("%d\n", tail->value);
}

int main() {
	char cmd[10] = "";
	int N, x;
	Queue* head = (Queue*)malloc(sizeof(Queue));
	Queue* tail = head;

	init(head, tail);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &x);
			tail = push(tail, x);
		}
		else if (strcmp(cmd, "pop") == 0) {
			head = pop(head);
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", size);
		}
		else if (strcmp(cmd, "empty") == 0) {
			is_empty();
		}
		else if (strcmp(cmd, "front") == 0) {
			print_front(head);
		}
		else if (strcmp(cmd, "back") == 0) {
			print_back(tail);
		}
	}

	for (int i = 0; i < size; i++) {
		head = head->next;
		free(head->prev);
	}
	free(head);

	return 0;
}
