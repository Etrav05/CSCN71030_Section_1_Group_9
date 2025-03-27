#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    // Mocked structure and variables for testing
    struct SNAKENODE {
        int x;
        int y;
        SNAKENODE* next;
    };

    int appleX;
    int appleY;
    int gameOver;
    int snakeLength;
    SNAKENODE* snakeList;

    // Initialize the snake
    SNAKENODE* createInitialSnake() {
        SNAKENODE* head = new SNAKENODE;
        head->x = 0;
        head->y = 0;
        head->next = nullptr;
        return head;
    }

    // Collision logic for testing
    void collision(SNAKENODE** list) {
        if (*list == nullptr) return;

        if ((*list)->x == appleX && (*list)->y == appleY) {
            snakeLength++;
            appleX = 10;
            appleY = 10;
        }

        if ((*list)->x < 0 || (*list)->y < 0) {
            gameOver = 1;
        }
    }

    TEST_CLASS(SnakeCollisionTests)
    {
    public:
        // Test Apple Collision
        TEST_METHOD(TestAppleCollision)
        {
            snakeList = createInitialSnake();
            appleX = 0;
            appleY = 0;
            snakeLength = 1;

            collision(&snakeList);

            Assert::AreEqual(2, snakeLength, L"Snake should grow after eating apple.");
            Assert::AreEqual(10, appleX, L"Apple X should move.");
            Assert::AreEqual(10, appleY, L"Apple Y should move.");
        }

        // Test Game Over Condition
        TEST_METHOD(TestGameOver)
        {
            snakeList = createInitialSnake();
            snakeList->x = -1;  // Move snake out of bounds
            gameOver = 0;

            collision(&snakeList);

            Assert::AreEqual(1, gameOver, L"Game should end when snake is out of bounds.");
        }
    };
}
