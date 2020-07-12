/*(wc file.txt) returns the numbers line, words and characters.
  Some features of this program needs to be improve.
  For example the program dont count any special characters, and if the data is a decimal number count the point like 
  another character.
  In the directory of this file there are many files that you can use for test this program and improve it.
  The specific file two (file2.txt) is the main file for test it.
  Name: Carlos Augusto Pérez Méndez
  Telecommunications
  propedeutic.
  CINVESTAV GUADALAJARA

*/
#include <stdio.h>


#define INPUT 1 /*En una palabra*/
#define OUTPUT 0 /*fuera de una palabra*/



int main (int argc, char * argv[] )
{

	FILE * fp;
	int c, counter_lines = 1, counter_chars = 0, counter_words = 0, flag;


	flag = OUTPUT;


   
    

	fp = fopen (argv[1], "r");  //Read a file from command line. 

	fseek (fp, 0, SEEK_SET);//Beginning of file.


	if ( fp == NULL){ 
		perror ("Error in opening file");
        return -1;
    }
    else{



    	while ( c != EOF )
	    {
		       c = fgetc (fp);



		      // printf ("%c", c);  /*This line is for debugg.*/
		      // if (feof (fp)) 7* Other option for go out of the loop.
		       //   break;
		       if (c == '\n'){                 //Counter lines.
		       	   
		       	  ++counter_lines;

		       	   
		       }
		       if ( c )                        //Counter characters.
		       {

		       	   ++counter_chars;
		       }

		       if ((c == ' ')  || (c == '\n') || (c == '\t'))    //Counter words.
		       {
		       	  flag = OUTPUT;
		       } else if ( flag == OUTPUT){
			     flag = INPUT;
			     ++counter_words;
		}
 
		     
		  
	     } 
	   printf("%d %d %d %s\n", counter_lines, counter_chars - 1, counter_words, argv[1]); 	 // Print #lines, #chars, #words, name of file.
	  
	  
      
		       	
		       	
	   
    }
	    

	fclose (fp);

	return 0;
} 