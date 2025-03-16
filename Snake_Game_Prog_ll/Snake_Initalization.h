#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct snakeBody {
	int x;
	int y;
} SNAKEBODY;

typedef struct snakeNode {
	SNAKEBODY data;
	struct snakeNode* next;
} SNAKENODE, * PSNAKENODE;

SNAKEBODY createBody(int x, int y);

void addNode(PSNAKENODE* list, SNAKEBODY s);

SNAKEBODY copyBody(SNAKEBODY s);

PSNAKENODE initialSize();

void freeSnake(PSNAKENODE head);
