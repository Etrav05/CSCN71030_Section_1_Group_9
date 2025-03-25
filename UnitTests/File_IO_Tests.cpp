#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" void saveHighScore(int score);
extern "C" int readHighScore();


namespace File_IO
{
	TEST_CLASS(File_IO)
	{
	public:

		TEST_METHOD(TestSaveAndReadHighScore)
		{
			int testScore = 42;
			saveHighScore(testScore);  // Save the test score to file
			int readScore = readHighScore();  // Read the score from the file
			Assert::AreEqual(testScore, readScore, L"High score read does not match saved score");
		}

		TEST_METHOD(TestReadHighScoreDefaultValue)
		{
			remove("highscore.txt"); // Ensure the file doesn't exist
			int readScore = readHighScore();  // Read the score (should return 0 if file is missing)
			Assert::AreEqual(0, readScore, L"Default high score should be 0 when file is missing");
		}


		TEST_METHOD(TestOverwriteHighScore)
		{
			int initialScore = 50;
			int newScore = 100;
			saveHighScore(initialScore);  // Save initial score
			saveHighScore(newScore);  // Overwrite with new score
			int readScore = readHighScore();  // Read the new score
			Assert::AreEqual(newScore, readScore, L"High score was not overwritten correctly");
		}


		TEST_METHOD(TestSaveAndReadNegativeHighScore)
		{
			int negativeScore = -42;
			saveHighScore(negativeScore);  // Save the negative score to file
			int readScore = readHighScore();  // Read the score from the file
			Assert::AreEqual(negativeScore, readScore, L"Negative high score was not saved or read correctly");
		}
	};
}
