#include "utils.h"


Board_t* createBoard() {
	Board_t* board = (Board_t*)malloc(sizeof(Board_t));
	if (board == NULL) {
		printf("ERROR: editor.c -> createBoard() -> malloc() returned NULL\n");
		return NULL;
	}

	strcpy(board->name, "                                                              ");
	time_t rawtime;
	time(&rawtime);
	board->timeCreated = *localtime(&rawtime);


	return board;
}

Board_t* createBoardCopy(Board_t* boardToCopy) {
	Board_t* board = createBoard();
	if (board == NULL) {
		return NULL;
	}

	strcpy(board->name, boardToCopy->name);
	board->timeCreated = boardToCopy->timeCreated;
	board->timeLastEdited = boardToCopy->timeLastEdited;

	for (int i = 0; i < 96; i++) {
		board->boardArr[i] = boardToCopy->boardArr[i];
	}

	return board;
}

int copyBoard(const Board_t* origin, Board_t* destination) {
	// TODO error code
	strcpy(destination->name, origin->name);
	
	for (int i = 0; i < 96; i++) {
		destination->boardArr[i] = origin->boardArr[i];
	}

	destination->timeCreated = origin->timeCreated;
	destination->timeLastEdited = origin->timeLastEdited;

	return 0;
}


Tuple2_t intsToTuple(int x, int y) {
	Tuple2_t tuple = { x, y };
	return tuple;
}

int charOccurrences(char* str, char c) {
	int i = 0;
	int count = 0;

	while (str[i] != NULL) {
		if (str[i] == c) ++count;

		++i;
	}

	return count;
}

int boardArrayLen(Board_t* arr[]) {
	int count = 0;

	while (arr[count] != NULL) {
		++count;
	}

	return count;
}

int indexCharInStr(char* str, char c) {
	int i = 0;

	while (str[i] != NULL) {
		char ch = str[i];
		if (ch == c) return i;
		++i;
	}

	return -1;
}