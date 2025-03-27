#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    // Mocked function for getch
    int (*mock_getch)() = nullptr;

    // Function to be tested
    void input(int& key) {
        int ch = mock_getch();  // Get the input key

        if (ch == 'w') {
            key = 1;  // Up
        }
        else if (ch == 'a') {
            key = 2;  // Left
        }
        else if (ch == 's') {
            key = 3;  // Down
        }
        else if (ch == 'd') {
            key = 4;  // Right
        }
    }

    TEST_CLASS(InputAcceptanceTests)
    {
    public:
        TEST_METHOD(TestValidKeyInputA)
        {
            int key = 0;  // Declare key inside the test method

            // Set mock getch to return 'a' key for left
            mock_getch = []() -> int { return 'a'; };  // Simulate 'a' key press

            input(key);  // Call the input function

            // Debugging: Check values of key
            std::cout << "TestValidKeyInputA - key: " << key << std::endl;

            Assert::AreEqual(2, key, L"Key 'a' should set the key to 2 (Left)");
        }

        TEST_METHOD(TestValidKeyInputD)
        {
            int key = 0;  // Declare key inside the test method

            // Set mock getch to return 'd' key for right
            mock_getch = []() -> int { return 'd'; };  // Simulate 'd' key press

            input(key);  // Call the input function

            // Debugging: Check values of key
            std::cout << "TestValidKeyInputD - key: " << key << std::endl;

            Assert::AreEqual(4, key, L"Key 'd' should set the key to 4 (Right)");
        }

        TEST_METHOD(TestValidKeyInputS)
        {
            int key = 0;  // Declare key inside the test method

            // Set mock getch to return 's' key for down
            mock_getch = []() -> int { return 's'; };  // Simulate 's' key press

            input(key);  // Call the input function

            // Debugging: Check values of key
            std::cout << "TestValidKeyInputS - key: " << key << std::endl;

            Assert::AreEqual(3, key, L"Key 's' should set the key to 3 (Down)");
        }

        TEST_METHOD(TestValidKeyInputW)
        {
            int key = 0;  // Declare key inside the test method

            // Set mock getch to return 'w' key for up
            mock_getch = []() -> int { return 'w'; };  // Simulate 'w' key press

            input(key);  // Call the input function

            // Debugging: Check values of key
            std::cout << "TestValidKeyInputW - key: " << key << std::endl;

            Assert::AreEqual(1, key, L"Key 'w' should set the key to 1 (Up)");
        }
    };
}
