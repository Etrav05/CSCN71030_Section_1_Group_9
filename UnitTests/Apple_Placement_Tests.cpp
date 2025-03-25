#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" int appleX, appleY;
extern "C" int width;
extern "C" int height;
extern "C" struct SNAKENODE;
extern "C" typedef struct SNAKENODE* PSNAKENODE;
extern "C" void placeApple(PSNAKENODE head);
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

    extern int appleX, appleY;
    void placeApple(PSNAKENODE head);
}



namespace Apple_Placement_Test
{
    TEST_CLASS(Apple_Placement_Test)
    {
    public:

        TEST_METHOD(TestApplePlacementWithinBounds)
        {
            width = 20; // Example width
            height = 20; // Example height
            PSNAKENODE dummySnake = NULL;
            placeApple(dummySnake);
            Assert::IsTrue(appleX >= 1 && appleX < width - 1, L"Apple X out of bounds");
            Assert::IsTrue(appleY >= 1 && appleY < height - 1, L"Apple Y out of bounds");
        }

        TEST_METHOD(TestMultipleApplePlacementsUnique)
        {
            PSNAKENODE dummySnake = NULL;

            int previousX = -1, previousY = -1;
            bool allSame = true;

            for (int i = 0; i < 5; i++) // Place 5 apples
            {
                placeApple(dummySnake);
                if (i > 0 && (previousX != appleX || previousY != appleY))
                {
                    allSame = false;
                }
                previousX = appleX;
                previousY = appleY;
            }

            Assert::IsFalse(allSame, L"Apple spawned in the same place 5 times in a row!");
        }

        TEST_METHOD(TestAppleDoesNotSpawnInsideSnake)
        {
            // Define some nodes for the snake
            SNAKENODE snake1 = { {5, 5}, NULL };  // First node (head)
            SNAKENODE snake2 = { {6, 5}, NULL };  // Second node
            SNAKENODE snake3 = { {7, 5}, NULL };  // Third node

            // Link the nodes together
            snake1.next = &snake2;
            snake2.next = &snake3;
            snake3.next = NULL;

            // Pass the head of the snake to placeApple
            PSNAKENODE snakeHead = &snake1;
            placeApple(snakeHead);

            // Check if apple spawned inside snake
            bool appleOnSnake = false;
            PSNAKENODE current = snakeHead;
            while (current != NULL)
            {
                if (current->data.x == appleX && current->data.y == appleY)
                {
                    appleOnSnake = true;
                    break;
                }
                current = current->next;
            }

            // Assert the apple didn't spawn inside the snake
            Assert::IsFalse(appleOnSnake, L"Apple spawned inside the snake!");
        }

        TEST_METHOD(TestAppleRandomness)
        {
            PSNAKENODE dummySnake = NULL;
            placeApple(dummySnake);
            int firstX = appleX, firstY = appleY;
            placeApple(dummySnake);
            bool differentPosition = (firstX != appleX || firstY != appleY);
            Assert::IsTrue(differentPosition, L"Apple spawned in the same location consecutively");
        }
    };
}