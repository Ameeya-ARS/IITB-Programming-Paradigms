// A program that reads a text file, 
// whose name is supplied as command line parameter,
// and it prints the frequency of counts of every 
// single letter/character appearing in that file.

// AUTHOR :- AMEEYA RANJAN SETHY

#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

class frequency{
   private: 
          int occurence[256]={0}; // To store the frequency of all characters
   
   public:

          void freq(char* source){

              for(int i=0;source[i] != '\0';i++){
                  occurence[source[i]]++ ;
                  } // end of for loop

             cout << '\t' << "Character" << '\t' << "Frequency";
              for(int i=32; i < 126; i++){    // Because only characters having ASCII code 32 to 126 are printable
                  if(occurence[i] != 0 ){
                    cout << '\t' << (char)i << '\t' << '\t' << occurence[i]<< endl;                    
                  } // end of of statement
               }// end of for loop
          }// end of freq()
         
}; // end of class


/* Arbitrary, just to set the size of the buffer (see below).
   Can be bigger or smaller */
#define BUFSIZE 5000

int main(int argc, char *argv[])
{
    frequency F;
    char str[5000];
    /* the first command-line parameter is in argv[1] 
       (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

    char buff[BUFSIZE]; /* a buffer to hold what you read in */

    /* read in one line, up to BUFSIZE-1 in length */
    while(fgets(buff, BUFSIZE - 1, fp) != NULL) 
    {
        /* buff has one line of the file, do with it what you will... */

        printf ("%s\n", buff); /* ...such as show it on the screen */
    }
    fclose(fp);  /* close the file */ 
    
     F.freq(buff);
   
}
