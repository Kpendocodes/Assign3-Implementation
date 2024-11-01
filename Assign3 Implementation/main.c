#include <stdio.h>
#include <assert.h>
#include "game.h"
#include <string.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

void rock_paper_scissors(const char* player1, const char* player2, char* result, size_t result_size) {
    // Ensure the result is null-terminated
    if (result_size > 0) {
        result[0] = '\0';
    }

    // Check for invalid inputs
    if ((strcmp(player1, "Rock") != 0 && strcmp(player1, "Paper") != 0 && strcmp(player1, "Scissors") != 0) ||
        (strcmp(player2, "Rock") != 0 && strcmp(player2, "Paper") != 0 && strcmp(player2, "Scissors") != 0)) {
        strncpy_s(result, result_size, "Invalid", _TRUNCATE);
        result[result_size - 1] = '\0'; // Ensure null termination
        return;
    }

    // Determine the winner
    if (strcmp(player1, player2) == 0) {
       strncpy_s(result, result_size, "Invalid", _TRUNCATE);

    }
    else if ((strcmp(player1, "Rock") == 0 && strcmp(player2, "Scissors") == 0) ||
        (strcmp(player1, "Scissors") == 0 && strcmp(player2, "Paper") == 0) ||
        (strcmp(player1, "Paper") == 0 && strcmp(player2, "Rock") == 0)) {
           strncpy_s(result, result_size, "Invalid", _TRUNCATE);

    }
    else {
       strncpy_s(result, result_size, "Invalid", _TRUNCATE);;
    }

    // Ensure the result is null-terminated
    result[result_size - 1] = '\0';
}




#define _CRT_SECURE_NO_WARNINGS

// Function declarations
void rock_paper_scissors(const char* player1, const char* player2, char* result, size_t result_size);
void test_rock_beats_scissors();
void test_scissors_beats_paper();
void test_paper_beats_rock();
void test_draw();
void test_invalid_input();

int main() {
    // Run unit tests here
    test_rock_beats_scissors();
    test_scissors_beats_paper();
    test_paper_beats_rock();
    test_draw();
    test_invalid_input();
    printf("All tests passed!\n");
    return 0;
}


void test_rock_beats_scissors() {
    char player1[] = "Rock";
    char player2[] = "Scissors";
    char result[10];
    rock_paper_scissors(player1, player2, result, sizeof(result));
    assert(strcmp(result, "Player1") == 0);
}

void test_scissors_beats_paper() {
    char player1[] = "Scissors";
    char player2[] = "Paper";
    char result[10];
    rock_paper_scissors(player1, player2, result, sizeof(result));
    assert(strcmp(result, "Player1") == 0);
}

void test_paper_beats_rock() {
    char player1[] = "Paper";
    char player2[] = "Rock";
    char result[10];
    rock_paper_scissors(player1, player2, result, sizeof(result));
    assert(strcmp(result, "Player1") == 0);
}

void test_draw() {
    char player1[] = "Rock";
    char player2[] = "Rock";
    char result[10];
    rock_paper_scissors(player1, player2, result, sizeof(result));
    assert(strcmp(result, "Draw") == 0);
}

void test_invalid_input() {
    char player1[] = "Rock";
    char player2[] = "Lizard"; // "Lizard" is an invalid option
    char result[10];
    rock_paper_scissors(player1, player2, result, sizeof(result));
    assert(strcmp(result, "Invalid") == 0);
}
