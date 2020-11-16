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

void runTimeTest();

int main(int argc, char **argv) {
  if (argc == 1) {
    // ask user for wordfile, then load it, then hash it
  }

  else if (argc == 2) {
    //load provied wordfile, then hash it
  }

  else if (argc == 3) {
    //load provided wordfile and hashfile
  }
}
