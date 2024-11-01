#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//extern "C" void rock_paper_scissors(const char* player1, const char* player2, char* result, size_t result_size);

void rock_paper_scissors(const char* player1, const char* player2, char* result, size_t result_size);
void rock_paper_scissors(const char* player1, const char* player2, char* result, size_t result_size){}
    

namespace testrockpaperscissors
{
    TEST_CLASS(testrockpaperscissors)
    {
    public:

        TEST_METHOD(test_rock_beats_scissors)
        {
            const char player1[] = "Rock";
            const char player2[] = "Scissors";
            char result[10];
            rock_paper_scissors(player1, player2, result, sizeof(result));
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(test_scissors_beats_paper)
        {
            const char player1[] = "Scissors";
            const char player2[] = "Paper";
            char result[10];
            rock_paper_scissors(player1, player2, result, sizeof(result));
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(test_paper_beats_rock)
        {
            const char player1[] = "Paper";
            const char player2[] = "Rock";
            char result[10];
            rock_paper_scissors(player1, player2, result, sizeof(result));
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(test_draw)
        {
            const char player1[] = "Rock";
            const char player2[] = "Rock";
            char result[10];
            rock_paper_scissors(player1, player2, result, sizeof(result));
            Assert::AreEqual("Draw", result);
        }

        TEST_METHOD(test_invalid_input)
        {
            const char player1[] = "Rock";
            const char player2[] = "Lizard";  // Invalid input
            char result[10];
            rock_paper_scissors(player1, player2, result, sizeof(result));
            Assert::AreEqual("Invalid", result);
        }
    };
}
