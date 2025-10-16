#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

int in_degree[MAX_SIZE];
int construction_time[MAX_SIZE];
int required_time[MAX_SIZE];

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

void topology_sort(int** node, int size, int last)
{
	int result = 0;
	int construction;
	Queue q;
	q.front = -1;
	q.rear = -1;

	for (int i = 1; i <= size; i++)
	{
		if (in_degree[i] == 0)
		{
			enqueue(&q, i);
		}
		required_time[i] = 0;
	}

	for (int i = 1; i <= size; i++)
	{
		construction = dequeue(&q);

		for (int j = 1; j <= node[construction][0]; j++)
		{
			int v = node[construction][j];
			in_degree[v]--;
			if (required_time[v] < construction_time[construction] + required_time[construction])
				required_time[v] = construction_time[construction] + required_time[construction];

			if (in_degree[v] == 0)
				enqueue(&q, v);
		}
	}
	result = construction_time[last] + required_time[last];
	printf("%d\n", result);
}

int main()
{
	int T, N, K, X, Y, W, v, i, j;
	int** node;
	
	node = (int**)malloc(sizeof(int*) * 1001);
	for (int j = 0; j < 1001; j++)
	{
		node[j] = (int*)malloc(sizeof(int) * 100001);
		node[j][0] = 0;
	}

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &K);

		
		for (j = 1; j <= N; j++)
		{
			scanf("%d ", &construction_time[j]);
			node[j][0] = 0;
		}
		
		for (j = 0; j < K; j++)
		{
			scanf("%d %d", &X, &Y);
			v = ++node[X][0];
			node[X][v] = Y;
			in_degree[Y]++;
		}

		scanf("%d", &W);

		topology_sort(node, N, W);
	}

	for (j = 0; j < 1001; j++)
	{
		free(node[j]);
	}
	free(node);

	return 0;
}
