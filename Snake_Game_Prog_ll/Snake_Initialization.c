#include "Snake_Initalization.h"

SNAKEBODY createBody(int x, int y) {
	SNAKEBODY S;
	S.x = x;
	S.y = y;
	return S;
}

void addNode(PSNAKENODE* list, SNAKEBODY s) {
	PSNAKENODE newNode = (PSNAKENODE)malloc(sizeof(SNAKENODE));

	if (!newNode) {
		fprintf(stderr, "Error creating snake node");
		exit(EXIT_FAILURE);
	}

	else {
		newNode->data = copyBody(s);
		newNode->next = *list;
		*list = newNode;
	}
}

SNAKEBODY copyBody(SNAKEBODY s) {
	return createBody(s.x, s.y);
}