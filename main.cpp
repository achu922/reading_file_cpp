#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "sub.h"
#include <new>
using namespace std;

int main()
{
    string str;             //String variable to read char from text file
    int n,*A,*B,*C,result;       //Creating n and A,B,C variables 
    
    FILE* infile;           
    infile = fopen("input.txt", "r");    //Opens and reads
    if(infile == NULL)              //if file does not open, print "Error! The File cannot be opened"
    {
        cout << "Error! The Input file cannot be opened" << endl;
        return 0;

    }
    else
    {
        cout << "Input file open" << endl;  //Prints that file is open
        fscanf(infile, "%d", &n);   //Getting first integer in the file

        cout << n << endl;

        //Dynamic memory allocation
        A = new int [n];
        B = new int [n];
        C = new int [n]; 
        

        for(int i = 1; i <= n; i++)     //loop to input file in array
        {
            fscanf(infile, "%d%d%d" , &A[i-1],&B[i-1],&C[i-1]);
        }
        cout << "Data read from input file" << endl;

        fclose(infile); //closes infile
        cout << "input file close" << endl;

    }
    ////////////////
    //output file
     FILE *outfile;
    outfile = fopen("output.txt", "w"); // open output file and giving writing permissions
    if (outfile == NULL)
    {
        cout << "Error! The Output file cannot be opened" << endl;
        return 0;
    }
    else
    {
        cout << "Output file open" << endl;

        fprintf(infile, "%d\n", n); // puts n on first line and creates new line for rest of inputs
        for(int i = 1; i <= n; i++)     //loop to put array into file
        {
            // did "%d %d %d\n" so it will be formated similarly to example
            fprintf(infile, "%d %d %d\n" , A[i-1],B[i-1],C[i-1]);
            
        }
        cout << "Data written to output file" << endl;  

        result = sub(n,A,B,C);  //Calling sub storing in result
        cout << "Function called" << endl;
        fprintf(outfile, "%d",result); // printing result 
        cout << "Result written to output file" << endl;

        fclose(outfile);    //close outfile 
        cout << "Output file closed" << endl;

        //Deallocating memory values
        delete[] A;
        delete[] B;
        delete[] C;
        
    }
    return 0;
}