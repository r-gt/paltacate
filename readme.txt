===========
 PALTACATE
===========

Simple and stupid language for avocado lovers (as me!)



Rules:
	- Instructions are written using "🥑".
	- Any other character is ignored.
	- Instructions are chosen based on how many "🥑" are there in a line.
	- First line is used to allocate memory.
	- Memory slots wraps around.
	- Memory slots are all 32 bits integers.
	- Loops stops when the selected memory slot is less than 0.



instructions:

	1:🥑
		Adds how many "🥑" are there in the next line to the selected memory slot.

	2:🥑🥑
		Substracts how many "🥑" are there in the next line to the selected memory slot.

	3:🥑🥑🥑
		Moves memory pointer 1 slot to the right.

	4:🥑🥑🥑🥑
		Moves memory pointer 1 slot to the left.

	5:🥑🥑🥑🥑🥑
		Prints selected memory slot value as a character.

	6:🥑🥑🥑🥑🥑🥑
		Loop start, will jump to Loop end if the selected memory slot is less than 1.

	7:🥑🥑🥑🥑🥑🥑🥑
		Loop end, Jumps to Loop Start if it's condition requieres a loop.



Licence:
	This is free and unencumbered software released into the public domain.

	Anyone is free to copy, modify, publish, use, compile, sell, or
	distribute this software, either in source code form or as a compiled
	binary, for any purpose, commercial or non-commercial, and by any
	means.

	In jurisdictions that recognize copyright laws, the author or authors
	of this software dedicate any and all copyright interest in the
	software to the public domain. We make this dedication for the benefit
	of the public at large and to the detriment of our heirs and
	successors. We intend this dedication to be an overt act of
	relinquishment in perpetuity of all present and future rights to this
	software under copyright law.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
	OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
	ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
