#include "Snake_Movement.h"
#include "main.h"

void movementLogic(PSNAKENODE* list) {
	if (*list == NULL) { // if the list is empty, there's nothing to remove
		return;
	}

	PSNAKENODE current = *list;

	int prevX = current->data.x; // save the current body parts x and y
	int prevY = current->data.y;

	switch (key) { // snake head movement 
	case 1:  // w - up
		current->data.y--;
		break;
	case 2:  // a - left
		current->data.x--;
		break;
	case 3:  // s - down
		current->data.y++;
		break;
	case 4:  // d - right
		current->data.x++;
		break;
	default:
		break;
	}

	if (key != 0) {
		PSNAKENODE next = current->next;  // move the body parts with the head
		while (next != NULL) {           // while youre not at the tail
			int tempX = next->data.x;   // save the position of the next body part
			int tempY = next->data.y;
			next->data.x = prevX;     // set the next body part location to the current body part 
			next->data.y = prevY;
			prevX = tempX;          // the next body parts location is now the "prev" for the next loop
			prevY = tempY;
			next = next->next;    // set next to the next node to continue
		}
	}
}