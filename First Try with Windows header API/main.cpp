#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void SetCursorPosition(int x, int y) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinates = {x, y};
	SetConsoleCursorPosition(output, coordinates);
}

void ScreenPopulate(const string &character) {
	for (int x = 0; x < 256; ++x) {
		for (int y = 0; y < 25; ++y) {
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			SetCursorPosition(x, y);
			cout << character;
		}
	}
}

int main() {
	
	ScreenPopulate(" ");
	
	cin.get();
	return 0;
}