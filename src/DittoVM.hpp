/*

DittoVM - One VM to rule them all

--- About ---

We gave DittoVM 100,000 cells for any calculation, essentially infinite memory. Go wild!

--- Example Usage ---

#include "DittoVM.hpp"

int main() {
	DittoTM VM;
	// Printing "123"
	VM.script = {
		"inc",
		"out_lit",
		"inc",
		"out_lit",
		"inc",
		"out_lit"
};
	VM.exec();
	return 0;
}

--- INSTRUCTION SET ---

inc - Increments current cell by 1.
dec - Decrements current cell by 1.

out - Outputs ASCII value of current cell.
out_lit - Outputs literal value of current cell.

in - Asks for input of the ASCII value of every cell combined behind the head (until the cell is empty), then writes an empty character ahead of the head, then the input string's ASCII values of each letter, THEN another empty cell.

jmp_st - If the current cell is 0, advances the program counter (PC) right until jmp_en. If not, execute the following instructions until the current cell is non-zero or empty.

jmp_en - Ends a jump-if-zero loop.

left - Moves head to the left.
right - Moves head to the right.

clear - Sets current cell to 0.

add - Adds the last two cells to the left together and sets the current cell to the result.
sub - Subtracts the last two cells to the left together and sets the current cell to the result.
mult - Multiplies the last two cells to the left together and sets the current cell to the result.
div - Divides the last two cells to the left together and sets the current cell to the result.
rand - Generates a random number, with the cell to the left being the minimum, and the cell two cells back being the maximum, then setting the current cell to the result.

<begin> - Begin a multi-line comment.

<end> - Ends a multi-line comment.

Okay, now that we have instructions ready, let's get started.
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#ifndef DITTO_VM
#define DITTO_VM

class DittoTM {
	public:
		std::vector<int> TM = std::vector(100000, 0);
		int PTR = 0;
		int PC = 0;
		std::vector<std::string> script;
		void inc() { TM[PTR]++; }
		void dec() { TM[PTR]--; }
		void out() { std::cout << static_cast<char>(TM[PTR]); }
		void out_lit() { std::cout << TM[PTR]; }
		void left() { PTR--; }
		void right() { PTR++; }
		void clear() { TM[PTR] = 0; }
		void in() {
			std::string temp;
			std::string input;
			while(TM[PTR] != 0 && PTR < 25000) {
				left();
				temp += static_cast<char>(TM[PTR]);
			}
			std::cout << temp;
			std::getline(std::cin, input);
			for(char x : input) {
				TM[PTR] = x;
				right();
			}
			clear();
	}
	void jmp_st() {
		if(TM[PTR] == 0) {
			while(script[PC] != "jmp_en") { PC++; }
		}
	}
	void add() { TM[PTR] = TM[PTR - 1] + TM[PTR - 2]; }
	void sub() { TM[PTR] = TM[PTR - 1] - TM[PTR - 2]; }
	void mult() { TM[PTR] = TM[PTR - 1] * TM[PTR - 2]; }
	void div() { TM[PTR] = TM[PTR - 1] / TM[PTR - 2]; }
	void rand() {
	   std::srand(std::time(NULL));
	   TM[PTR] = (std::rand() % TM[PTR - 1]) + TM[PTR - 2];
    }
    void comments() {
    	while (script[PC] != "<end>") {
    		PC++;
    	}
    }
	inline void exec() {
		while (PC < script.size()) {
			if(script[PC] == "inc") {
				inc();
				PC++;
			} else if(script[PC] == "dec") {
				dec();
				PC++;
			}else if(script[PC] == "out") {
				out();
				PC++;
			}else if(script[PC] == "out_lit") {
				out_lit();
				PC++;
			}else if(script[PC] == "in") {
				in();
				PC++;
			}else if(script[PC] == "jmp_st") {
				jmp_st();
				PC++;
			}else if(script[PC] == "jmp_en") {
				PC++;
			}else if(script[PC] == "left") {
				left();
				PC++;
			}else if(script[PC] == "right") {
				right();
				PC++;
			}else if(script[PC] == "clear") {
				clear();
				PC++;
			} else if(script[PC] == "add") {
				add();
				PC++;
			} else if(script[PC] == "sub") {
				sub();
				PC++;
			} else if(script[PC] == "mult") {
				mult();
				PC++;
			} else if(script[PC] == "div") {
				div();
				PC++;
			} else if(script[PC] == "rand") {
				rand();
				PC++;
			} else if(script[PC] == "<begin>") {
				comments();
				PC++;
			}
		}
	}
};
#endif