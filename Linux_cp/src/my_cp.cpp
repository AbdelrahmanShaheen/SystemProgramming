#include"../include/my_cp.h"
#include <fcntl.h>
#include<unistd.h>
int Copy(int argc ,char ** argv)
{
	if(argc < 3)
	return 1;
    
    int fdSrcFile = open(argv[1],O_RDONLY); //open an existing file .
    if(fdSrcFile == -1) //check if the file not opened 
    return 2;
    //creat(if not exist)a file to write on it .
    int fdDstFile = open(argv[2],O_CREAT  | O_WRONLY);
    
    if(fdDstFile == -1)
    return 3;
    
    ssize_t countChar;
    char buffer[1];
    //read from file descriptor into the buffer (end when read all characters).
    while((countChar = read(fdSrcFile ,buffer ,sizeof(buffer))) != 0)
    {
    	//write one character from the buffer to the fdScrFile.
         write(fdDstFile ,buffer ,countChar);
    }	

    return 0;
}