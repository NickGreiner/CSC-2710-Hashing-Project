#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<string>> hashing(vector<string> wordVector);

int main()
{
   int i, j;
   string temp;
   vector<string> words;
   vector<vector<string>> buckets;
   ifstream file;
   file.open("Final_Data.txt");
   while(file >> temp)
      words.push_back(temp);
   file.close();

   buckets = hashing(words);
   for(i=0; i<10; i++){
      for(j=0; j<buckets[i].size(); j++)
         cout << buckets[i][j] << " ";
      cout << endl;
   }

   return 0;
}

vector<vector<string>> hashing(vector<string> wordVector)
{
   int i, j, len, hash=0;
   vector<vector<string>> buckets(10);
//   cout << wordVector.size();

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
