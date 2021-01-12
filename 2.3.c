/* This code is like command of UNIX (wc file.txt) and returns the numbers line, words and characters.
 * In the directory of this project there are many files that you can use for test this program and improve it. For example,
 * at the end of the word the program count the white space. However, the counter has a good approximation. It can be
 * compared with a editor of text and check the results with the program. Some editors of text match with the results but
 * others does not.
 * The specific file two (file2.txt) is the main file for test it.
 * Name: Carlos Augusto Pérez Méndez.
 * Telecommunications
 * propedeutic.
 * CINVESTAV GUADALAJARA
*/

#include <stdio.h>

/*In a word*/
#define INPUT 1 
/*Out of a word*/
#define OUTPUT 0 



int main (int argc, char * argv[])
{
	FILE * fp;
	int counter_lines = 1, counter_chars = 0, counter_words = 0;
	int c, flag;

	flag = OUTPUT;
	// Read a file from command line.
	fp = fopen(argv[1], "r");   
	// Beginning of file.
	fseek(fp, 0, SEEK_SET);


	if (fp == NULL)
	{ 
		perror("Error in opening file");
        return -1;
    }
    else
    {
    	while (c != EOF)
    	{
    		c = fgetc(fp);
    		// printf ("%c", c);  /*This line is for debugg.*/
		    // if (feof (fp)) Other option for go out of the loop.
		    // break;
		    
		    if (c == '\n')
		    {
		    	//Counter lines.
		    	++counter_lines;   
		    }
		    if (c)
		    {
		    // Counter characters.
		    	++counter_chars;
		    }
		    if ((c == ' ') || (c == '\n') || (c == '\t'))    
		    {
		    	flag = OUTPUT;
		    } else if (flag == OUTPUT)
		    {
			     flag = INPUT;
			     //Counter words.
			     ++counter_words;
			}
		} 
	   
	   // Print #lines, #chars, #words, name of file.
		printf("%d %d %d %s\n", counter_lines, counter_chars - 1, counter_words, argv[1]);
	}

	fclose(fp);
	return 0;
} 