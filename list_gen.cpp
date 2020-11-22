#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
  string inputStr;

  cout << "Input word file: ";
  cin >> inputStr;
  cout << endl;

  vector<string> tokens;

  ifstream wfile(inputStr);

  copy(istream_iterator<string>(wfile), istream_iterator<string>(), back_inserter(tokens));

  cout << tokens.size() << endl;

  for (int i = 0; i < tokens.size(); i++) {
    for(int j = 0; tokens[i][j] != '\0'; ++j) {
      while(!( (tokens[i][j] >= 'a' && tokens[i][j] <= 'z') || (tokens[i][j] >= 'A' && tokens[i][j] <= 'Z') || tokens[i][j] == '\0')) {
        for(int k = j; tokens[i][k] != '\0'; ++k) {
          tokens[i][k] = tokens[i][k+1];
        }
      }
    }
  }

  ofstream outFile ("word_list.txt");

  for(int i = 0; i < tokens.size(); i++) {
    outFile << tokens.at(i) << endl;
  }

}
