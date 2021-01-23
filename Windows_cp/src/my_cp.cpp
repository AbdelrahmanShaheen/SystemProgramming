#include"../include/my_cp.h"
#include <fstream>
using namespace std;
int Copy(int argc ,char**argv){
  if(argc < 3)
    return 1;
  ifstream fdSrcFile;
  fdSrcFile.open(argv[1] ,ifstream::binary | ifstream::in);
  if(!fdSrcFile)
  return 2;
  ofstream dstFile;
  dstFile.open(argv[2] ,ofstream::binary | ofstream::out);
  if(!dstFile)
  return 3;

  string buffer;

  while(getline(fdSrcFile , buffer))
  dstFile << buffer <<"\n";

  fdSrcFile.close();
  dstFile.close();
  return 0;
}
