# DittoVM
A small, Brainfuck-like language written in C++.
# About
I designed DittoVM for compiler devs that didn't want to write a VM themselves.

I also gave DittoVM 100,000 cells for HUGE calculations.

DittoVM also handles adding strings (like adding an input string to a chunk of the VM's memory) and reading them.

DittoVM is essentially Brainfuck but with better commands and more commands, like out_lit which outputs the literal value of a cell, which differs from out (which outputs the ASCII value of a cell)

# Roadmap
v0.1 - First upload to GitHub. Officially turing-complete.

v0.2 - Replaced "std::cin >> input;" with "std::getline(std::cin, input);" to handle spaces in input.

v0.3 - Added 4 new arithmetic commands, those being:

- add

- sub

- mult

- div

v0.4 - Added a "rand" command for random number generation.

v0.5 - Added comments, like so:

\<begin\>

out_lit

The last line does nothing!

\<end\>

v0.6 - Added a goto command. It goes to a specific line based on the value of the current cell.


# Future updates
Since DittoVM is already turing-complete, I might add some of these in the future:

- Error messages!

- FUNCTIONS!!!

- And more quality of life updates!
