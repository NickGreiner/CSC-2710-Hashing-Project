/*
Name: Hashing Project
Authors:  Nick Greiner, Matt Ray, Brysen Allen, Sam Mycroft
Class:  CSC-2710-01
Date:   11/16/2020
Description:

https://github.com/NickGreiner/CSC-2710-Hasing-Project
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> loadWordfile(string wordfile);
vector<int> loadHashfile(string hashfile);
int anagramStr(string entWord,string wordList[]);
int anagramHash(string entWordHash, string hashList[]);

void runTimeTest();

int main(int argc, char **argv) {
  if (argc == 1) {
    // ask user for wordfile, then load it, then hash i
    cout<<"Please enter file name of word list";
    cin>>inWordFile;
    loadWordfile();
    hashalg();
  }

  else if (argc == 2) {
    //load provied wordfile, then hash it
    loadWordfile(/*wordFile*/);
    hashalg(/*vector holding words*/);
  }

  else if (argc == 3) {
    //load provided wordfile and hashfile
    loadWordfile(/*wordFile*/);
    loadHashfile(/*hashFile*/);
  }
  
  cout<< "Available Letters:";
}
//NEED TIME FUNCTION STILL
int anagramStr(string entWord,string wordList[])
{
  int i;
  for(i=0;i<len(l);i++)
    if(strcmp(entWord,wordList[i])=0)
      return 1; //in main add word to found words list
    else
      return 0;//in main notify not in list
}

int anagramHash(string entW

ordHash, string hashList[])
{
  int i;
  for(i=0;i<len(l);i++)
    if(entWordHash=hashList[i])
      return 1; //in main add word to found words list
    else
      return 0;//in main notify not in list
}
