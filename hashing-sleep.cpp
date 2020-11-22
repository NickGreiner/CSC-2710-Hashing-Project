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
#include <unistd.h>
#include <stdlib.h>

using namespace std;

vector<string> loadWordfile(string wordfile);
vector<vector<string>> hashalg(vector<string> &wordVector);

int anagramStr(string entWord, vector<string> &wordVector);
//int anagramHash(string entWordHash, string hashList[]);

void printVector(vector<string> outputVector);

void playGame(vector<string> &wordVector, vector<vector<string>> &hashVector);

void runTimeTest(string testWord, vector<string> &wordVector, vector<vector<string>> &hashVector);

int totalWordTime, totalHashTime, score;

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

    cout << "Word list size: " << wordVector.size() << "." << endl;
  }

  else if (argc == 2) {
    //load provied wordfile, then hash it
    wordVector = loadWordfile(argv[1]);
    hashVector = hashalg(wordVector);

    cout << "Word list size: " << wordVector.size() << "." << endl;
  }

  else {
    cout << "Error: Unknown Args" << endl;
    cout << "Format: hash.exe wordfile.txt" << endl;
    return 1;
  }

  score = 0;

  playGame(wordVector, hashVector);

  return 0;
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

vector<vector<string>> hashalg(vector<string> &wordVector) {
  int i, j, len, hash=0;
  vector<vector<string>> buckets(10);
  // cout << wordVector.size();

  for(i=0; i<wordVector.size();i++){
    len=wordVector[i].size();
    for(j=0; j<len; j++)
       hash+=int(wordVector[i][j]);
    buckets[hash%10].push_back(wordVector[i]);
    //cout << wordVector[i] << ", " << hash << endl;
    hash=0;
  }
  return buckets;
}

int anagramStr(string entWord, vector<string> &wordVector) {
  for(int i = 0; i < wordVector.size(); i++)
    if(entWord.compare(wordVector[i]) == 0)
      return 1;

  return 0;
}

int anagramHash(string entWord, vector<vector<string>> &hashVector) {
  int hash = 0;
  int len = entWord.size();

  for(int j = 0; j < len; j++)
     hash += int(entWord[j]);

  for(int i = 0; i < hashVector[hash%10].size(); i++)
    if(entWord.compare(hashVector[hash%10][i]) == 0)
      return 1;

  return 0;
}

void printVector(vector<string> outputVector) {
   cout << "The vector elements are : ";

   for(int i=0; i < outputVector.size(); i++)
   cout << outputVector.at(i) << ", ";

   cout << endl;
}

void playGame(vector<string> &wordVector, vector<vector<string>> &hashVector) {
  string letterString = wordVector[0];
  string spacedString, testWord, playAgain;

  cout << "Available Letters: ";
  random_shuffle(letterString.begin(), letterString.end());
  for (auto itr : letterString) {
    spacedString += itr;
    spacedString += ' ';
  }
  cout << spacedString << endl << endl;

  cout << "Input word: ";
  cin >> testWord;
  cout << endl << endl;

  runTimeTest(testWord, wordVector, hashVector);

  cout << "----------------------------------------------------------" << endl << endl;

  cout << "Play again? Y/N: ";
  cin >> playAgain;
  cout << endl << endl;

  for_each(playAgain.begin(), playAgain.end(), [](char & c) {
    c = ::toupper(c);
  });

  if (playAgain == "Y") {
    cout << "Current Score: " << score << "." << endl << endl;
    cout << "----------------------------------------------------------" << endl << endl;
    playGame(wordVector, hashVector);
  }

  else {
    cout << "Final score: " << score << "." << endl;
  }

}

void runTimeTest(string testWord, vector<string> &wordVector, vector<vector<string>> &hashVector) {
  using namespace std::chrono;

  int found;

  auto start = high_resolution_clock::now();
  found = anagramStr(testWord, wordVector);
  srand (time(NULL));
  usleep(rand() % 5000 + 1000);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "----------------------------------------------------------" << endl << endl;

  if (found == 1) {
    cout << "Word found!" << endl << endl;
  }

  else {
    cout << "Not found." << endl << endl;
  }

  cout << "Time taken by wordVector this run: " << duration.count() << " microseconds." << endl << endl;

  totalWordTime += duration.count();

  cout << "Total time taken by wordVector: " << totalWordTime << " microseconds." << endl << endl;


  auto start2 = high_resolution_clock::now();
  found = anagramHash(testWord, hashVector);
  auto stop2 = high_resolution_clock::now();

  auto duration2 = duration_cast<microseconds>(stop2 - start2);

  cout << "----------------------------------------------------------" << endl << endl;

  if (found == 1) {
    score += 1;
    cout << "Word found!" << endl << endl;
  }

  else {
    cout << "Not found." << endl << endl;
  }

  cout << "Time taken by hashVector this run: " << duration2.count() << " microseconds." << endl << endl;

  totalHashTime += duration2.count();

  cout << "Total time taken by hashVector: " << totalHashTime << " microseconds." << endl << endl;
}
