#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static char mockInput = 0; // create a mock user input to test acceptance
int mock_getch() { return mockInput; }

extern "C" {
    int input(); // grab the function and variables we will need
    extern int key;
    extern int gameOver;
}


namespace Input_Acceptance_Tests
{
    TEST_CLASS(Input_Acceptance_Tests)
    {
    public:
        TEST_METHOD_INITIALIZE(Setup)
        {
            // Reset global variables before each test
            key = 0;
            gameOver = 0;
        }

        TEST_METHOD(Test_W_Key_Sets_Key_To_1)
        {
            mockInput = 'w';

            int result = input();

            Assert::AreEqual(1, result);
            Assert::AreEqual(1, key);
        }

        TEST_METHOD(Test_S_Key_Doesnt_Set_Key_To_3_When_Previous_Was_1) // testing the disallowance of going directly backwards
        {
            key = 1;  // previous key was 'w' (1)
            mockInput = 's';

            int result = input();

            Assert::AreEqual(1, result);  // Should remain 1
            Assert::AreEqual(1, key);
        }

        TEST_METHOD(Test_X_Key_Sets_GameOver) // testing the game over key functionality 
        {
            mockInput = 'x';

            input();

            Assert::AreEqual(1, gameOver);
        }
    };
}
