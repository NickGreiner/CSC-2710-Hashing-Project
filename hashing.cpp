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

vector<string> loadWordfile(string wordfile);
vector<vector<string>> hashalg(vector<string> wordVector);

//int anagramStr(string entWord,string wordList[]);
//int anagramHash(string entWordHash, string hashList[]);

void printVector(vector<string> outputVector);

// void runTimeTest();

int main(int argc, char **argv) {
  vector<string> wordVector;
  vector<vector<string>> hashVector;

  if (argc == 1) {
    string inWordFile;
    // ask user for wordfile, then load it, then hash i
    cout << "Please enter file name of word list: ";
    cin >> inWordFile;
    cout << endl;
    wordVector = loadWordfile(inWordFile);
    hashVector = hashalg(wordVector);
  }

  else if (argc == 2) {
    //load provied wordfile, then hash it
    wordVector = loadWordfile(argv[1]);
    hashVector = hashalg(wordVector);
  }

  else {
    cout << "Error: Unknown Args" << endl;
    cout << "Format: hash.exe wordfile.txt" << endl;
    return 1;
  }

  cout << "Available Letters: ";
  string letterString = wordVector[0];
  string spacedString;
  random_shuffle(letterString.begin(), letterString.end());

  for (auto itr : letterString)
   {
      spacedString += itr;
      spacedString += ' ';
   }

  cout << spacedString << endl;
}

vector<string> loadWordfile(string wordfile) {
  vector<string> wordVector;
  ifstream wfile(wordfile);

  copy(istream_iterator<string>(wfile), istream_iterator<string>(), back_inserter(wordVector));

  return wordVector;
}

vector<vector<string>> loadHashfile(string hashfile) {
  vector<vector<string>> hashVector;

  return hashVector;
}

vector<vector<string>> hashalg(vector<string> wordVector) {
  vector<vector<string>> hashVector;

  return hashVector;
}

/*
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

int anagramHash(string entWordHash, string hashList[])
{
  int i;
  for(i=0;i<len(l);i++)
    if(entWordHash=hashList[i])
      return 1; //in main add word to found words list
    else
      return 0;//in main notify not in list
}
*/

void printVector(vector<string> outputVector) {
   cout << "The vector elements are : ";

   for(int i=0; i < outputVector.size(); i++)
   cout << outputVector.at(i) << ", ";

   cout << endl;
}
