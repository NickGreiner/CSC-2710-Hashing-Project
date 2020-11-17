/* Brysen Allen, Nick Greiner, Sam Mycroft, Matt Ray
   Algorthms Project 2: Hashing
   This is an anagram game. You are given a set of letters and must enter those
   letters to form words in the word list. The rogram will search using both a 
   string compare and by comparing hashes. It will then output the time difference
   between the two search methods.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int anagramSTR(/*entered word*/,/* word list*/)
{
  int i;
  for(i=0;i<len(l);i++)
    if(strcmp(w,l[i])=0)
      //send back word
      return 1; //in main add word to found words list
    else
      //not in list
      return 0;//in main notify not in list
}

int anagramHASH(/*hashed word*/,/* hash list*/)
{
  int i;
  for(i=0;i<len(l);i++)
    if(hw=h[i])
      //send back word
      return 1; //in main add word to found words list
    else
      //not in list
      return 0;//in main notify not in list
}
