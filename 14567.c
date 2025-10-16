#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

int in_degree[MAX_SIZE];

typedef struct Queue
{
	int front, rear;
	int data[MAX_SIZE];
}Queue;

void enqueue(Queue* q, int data)
{
	q->rear = q->rear + 1;
	q->data[q->rear] = data;
}

int dequeue(Queue* q)
{
	q->front = q->front + 1;
	return q->data[q->front];
}

void topology_sort(int** node, int size)
{
	int semesters[1001];
	int i, j = 0;
	Queue q;
	q.front = -1;
	q.rear = -1;

	

	for (i = 1; i <= size; i++)
	{
		if (in_degree[i] == 0)
		{
			enqueue(&q, i);
			semesters[i] = 1;
		}
			
	}

	for (i = 1; i <= size; i++)
	{
		int subject = dequeue(&q);

		for (j = 1; j <= node[subject][0]; j++)
		{
			int v = node[subject][j];
			in_degree[v]--;
			if (in_degree[v] == 0)
			{
				enqueue(&q, v);
				semesters[v] = semesters[subject] + 1;
			}
		}
	}

	for (i = 1; i <= size; i++)
	{
		printf("%d ", semesters[i]);
	}
}

int main()
{
	int** node;
	int N, M, A, B, n;

	scanf("%d %d", &N, &M);

	node = (int**)malloc(sizeof(int*) * (N + 1));
	for (int i = 0; i < N + 1; i++)
	{
		node[i] = (int*)malloc(sizeof(int) * (N + 1));
		node[i][0] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &A, &B);
		n = ++node[A][0];
		if (n > 1000)
			node[A] = (int*)realloc(node[A], sizeof(int) * (M + 1));
		node[A][n] = B;
		in_degree[B]++;
	}

	topology_sort(node, N);

	for (int i = 0; i < N; i++)
	{
		free(node[i]);
	}
	free(node);

	return 0;
}
