#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    // Mocked function for command line processing
    std::string(*mock_getInput)() = nullptr;

    // Function to initialize the snake game based on the user input
    bool startGame() {
        std::string input = mock_getInput();
        if (input == "startGame") {
            // Simulate initializing the game and showing the main menu
            return true;
        }
        return false;
    }

    TEST_CLASS(StartGameTests)
    {
    public:
        TEST_METHOD(TestStartGameCommand)
        {
            // Mock user input to simulate "startGame" command
            mock_getInput = []() -> std::string { return "startGame"; };

            bool gameInitialized = startGame();  // Call the function to start the game

            // Debugging: Check if the game is initialized
            std::cout << "TestStartGameCommand - gameInitialized: " << gameInitialized << std::endl;

            // Assert that the game was successfully initialized
            Assert::IsTrue(gameInitialized, L"Game should be initialized when 'startGame' command is entered.");
        }

        TEST_METHOD(TestInvalidCommand)
        {
            // Mock user input to simulate an invalid command
            mock_getInput = []() -> std::string { return "invalidCommand"; };

            bool gameInitialized = startGame();  // Call the function to start the game

            // Debugging: Check if the game is initialized
            std::cout << "TestInvalidCommand - gameInitialized: " << gameInitialized << std::endl;

            // Assert that the game was not initialized for an invalid command
            Assert::IsFalse(gameInitialized, L"Game should not be initialized for invalid command.");
        }
    };
}
