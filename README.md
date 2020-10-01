# fillit
C program that receives a list of random tetris blocks and arrange them in the smallest possible square.<br />
A coding excercise in parsing and recursion.

## Usage
Repository contains a Makefile for:<br /> 
* compiling executable (**make all**)<br />
* removing object files (**make clean**)<br />
* deleting executable (**make fclean**)<br />
* recompiling (**make re**)<br /><br />

**Tetris blocks**<br />
* Given in 4 lines of 4 characters each. <br />
* Tetris block consists of 4 '#' characters. Empty spaces indicated by '.'<br />
* Each tetris block is seperated by an empty line<br />
* Invalid file format or invalid tetris block returns 'error' on the standard output<br />
* Example of valid input, running and output:<br />
  <img src="Fillit_example.png" alt="example" width="420"/><br />
#### Notes:
This project was done together with [T7Q](https://github.com/T7Q) and is part of my studies at Hive Helsinki.<br />
My part of the code handles the validation and parsing of the tetris blocks. <br />
The project was tested by 3 fellow Hive students as well as an automated evaluation system.


