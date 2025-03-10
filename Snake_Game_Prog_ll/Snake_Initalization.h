#pragma once
#include <stdio.h>
#include <stdlib.h>

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

PSNAKENODE initialSize(int startX, int startY, int length);

void freeSnake(PSNAKENODE head);