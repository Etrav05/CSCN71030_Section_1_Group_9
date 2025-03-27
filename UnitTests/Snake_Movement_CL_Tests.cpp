#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" int key; // Assuming key is an integer controlling snake movement
extern "C" struct SNAKENODE;
extern "C" typedef struct SNAKENODE* PSNAKENODE;
extern "C" void movementLogic(PSNAKENODE* list);
extern "C" typedef SNAKENODE* PSNAKENODE;

extern "C" {
    typedef struct SNAKENODE {
        struct {
            int x;
            int y;
        } data;
        struct SNAKENODE* next;
    } SNAKENODE;

    typedef SNAKENODE* PSNAKENODE;

    void movementLogic(PSNAKENODE* list);  // Function to test snake movement logic
}

namespace Snake_Movement_Test
{
    TEST_CLASS(Snake_Movement_Test)
    {
    public:

        TEST_METHOD(TestSnakeMovesUp)
        {
            // Initialize the snake
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            PSNAKENODE snakeHead = &snake1;

            key = 1;  // Set key to 1 (up movement)
            movementLogic(&snakeHead);  // Call the movement logic

            // Assert the new position of the head
            Assert::AreEqual(4, snakeHead->data.y, L"Snake did not move up correctly");
        }

        TEST_METHOD(TestSnakeMovesLeft)
        {
            // Initialize the snake
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            PSNAKENODE snakeHead = &snake1;

            key = 2;  // Set key to 2 (left movement)
            movementLogic(&snakeHead);  // Call the movement logic

            // Assert the new position of the head
            Assert::AreEqual(4, snakeHead->data.x, L"Snake did not move left correctly");
        }

        TEST_METHOD(TestSnakeMovesDown)
        {
            // Initialize the snake
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            PSNAKENODE snakeHead = &snake1;

            key = 3;  // Set key to 3 (down movement)
            movementLogic(&snakeHead);  // Call the movement logic

            // Assert the new position of the head
            Assert::AreEqual(6, snakeHead->data.y, L"Snake did not move down correctly");
        }

        TEST_METHOD(TestSnakeMovesRight)
        {
            // Initialize the snake
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            PSNAKENODE snakeHead = &snake1;

            key = 4;  // Set key to 4 (right movement)
            movementLogic(&snakeHead);  // Call the movement logic

            // Assert the new position of the head
            Assert::AreEqual(6, snakeHead->data.x, L"Snake did not move right correctly");
        }

        TEST_METHOD(TestSnakeBodyMovesWithHead)
        {
            // Initialize the snake with multiple body parts
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            SNAKENODE snake2 = { {6, 5}, NULL };  // Second node
            snake1.next = &snake2;
            PSNAKENODE snakeHead = &snake1;

            key = 4;  // Set key to 4 (right movement)
            movementLogic(&snakeHead);  // Call the movement logic

            // Assert the movement of the head
            Assert::AreEqual(6, snakeHead->data.x, L"Head did not move correctly");

            // Assert the movement of the second body part
            Assert::AreEqual(5, snake2.data.x, L"Body part did not follow the head correctly");
        }

        TEST_METHOD(TestSnakeDoesNotMoveWithKeyZero)
        {
            // Initialize the snake
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            PSNAKENODE snakeHead = &snake1;

            key = 0;  // Set key to 0 (no movement)
            movementLogic(&snakeHead);  // Call the movement logic

            // Assert the position of the head remains the same
            Assert::AreEqual(5, snakeHead->data.x, L"Snake moved when it shouldn't have");
            Assert::AreEqual(5, snakeHead->data.y, L"Snake moved when it shouldn't have");
        }
    };
}
