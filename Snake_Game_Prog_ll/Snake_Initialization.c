#include "Snake_Initalization.h"
#include "main.h"

int snakeLength;

int height, width;

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

	snakeLength++; // increase the snakes length
}

SNAKEBODY copyBody(SNAKEBODY s) {
	return createBody(s.x, s.y);
}

PSNAKENODE initialSize() { // startX and Y will be passed based on the given size of the snake area, however, length with be hard coded
	PSNAKENODE head = NULL;

	for (int i = 0; i < 5; i++) {
		SNAKEBODY body = createBody(width / 2 - i, height / 2); // creates body parts down vertically (for a given length)
		addNode(&head, body);
	}

	return head;
}

void freeSnake(PSNAKENODE head) {
	PSNAKENODE temp;

	while (head != NULL) {    // until all nodes are gone
		temp = head;	     // temp is head
		head = head->next;  // move head to the next node
		free(temp);        // free the temp
	}

	snakeLength--;
}
