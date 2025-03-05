#include <stdio.h>

typedef struct snakeBody {
	int x;
	int y;
} SNAKEBODY;

typedef struct snakeNode {
	SNAKEBODY data;
	struct snakeNode* next;
} SNAKENODE, *PSNAKENODE;