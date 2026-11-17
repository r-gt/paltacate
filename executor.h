#ifndef PALANG_EXECUTOR_H
#define PALANG_EXECUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>
#include <unistd.h>

int * parsed;
long * memory;

int plaexecute(char * path){
	setlocale(LC_CTYPE, "");

	unsigned long maxmem=0;
	unsigned long program_size=0;
	unsigned long program_pointer=0;

	unsigned long memory_pointer=0;


	FILE * program  = fopen(path, "r");
	if(!program) return 2;

	unsigned long count=1;
	unsigned long line=1;

	unsigned int c = 0;

	c=fgetwc(program);


	while(c!=WEOF){
		if( !(c==L' ' || c==L'\t') && (c==L'\n' || c==L'🥑')){

			if (c==L'\n')
				line++;

		}
	c=fgetwc(program);
	}


	parsed = calloc(line, sizeof(long int));
	program_size=line;

	fseek(program, 0, SEEK_SET);
	c=fgetwc(program);

	line=1;
	count=0;


	// parser
	while(c!=WEOF){

		if( !(c==L' ' || c==L'\t') && (c==L'\n' || c==L'🥑')){

			count++;

			if (c==L'\n'){
				parsed[line-1]= count-1;
				line++;
				count=0;

			}

		}
	c=fgetwc(program);
	}


	// set up memory
	memory = calloc(parsed[0], sizeof(long));
	maxmem = parsed[0];
	parsed[0]=0;

	program_pointer = 1;   //start at line 2 (line 1 is reserved for memory allocation)
	memory_pointer=0;

	printf("\n");

	while(program_pointer<=program_size){

		int n = parsed[program_pointer];


		switch(n){

			case 0: break;

			// addition
			case 1:
				program_pointer++;
				memory[memory_pointer]+=parsed[program_pointer];
				break;

			// substraction
			case 2:
				program_pointer++;
				memory[memory_pointer]-=parsed[program_pointer];
				break;

			// move right
			case 3: if(memory_pointer++ > maxmem) memory_pointer=0;break;
			// move left
			case 4: if(memory_pointer-- == ULONG_MAX) memory_pointer=maxmem;break;

			// print character
			case 5: putwchar(memory[memory_pointer]); break;

			// loop start
			case 6:
				if(memory[memory_pointer]<1){
					while(parsed[program_pointer]!=7 || (parsed[program_pointer-1]==1 || parsed[program_pointer-1]==2 ))
						program_pointer++;
					program_pointer++;

				}
				break;

			// loop end
			case 7:
				while(parsed[program_pointer]!=6 || (parsed[program_pointer-1]==1 || parsed[program_pointer-1]==2 ))
				program_pointer--;
				program_pointer--;
				break;


			// get character
			case 8: memory[memory_pointer] = getchar(); break;

			default: printf("\n  Unknown instruction at %lu", program_pointer); break;
		}

		program_pointer++;



	}
	putwchar('\n');

	// we don't free memory, so it could be used later :)
}
#endif
