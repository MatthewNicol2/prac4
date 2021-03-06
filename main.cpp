#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>
#include "coolvector.h"


using namespace std;

int main(int argc, char** argv) {


  /*ADJUST LEVEL*/
  int level = 2;


  /*PARSING COMMAND LINE ARGUMENTS*/
  enum { total, unique, individual } mode = total;
  for (int c; (c = getopt(argc, argv, "tui")) != -1;) {
    switch(c) {
      case 't': mode = total; break;
      case 'u': mode = unique; break;
      case 'i': mode = individual; break;
    }
  }
  argc -= optind;
  argv += optind;


  /*GENERAL DEFINITIONS*/
  string word;
  int count = 0;


  /*LEVEL 1 DEFINITIONS*/
  vector<string> unique_words;
  vector<string>::iterator iter;  
  bool duplicate = false;


  /*LEVEL 2-> DEFINITIONS*/
  coolvector<string> cv_unique;

  /*WORD PARSING CODE BEGINS HERE*/
  while (cin >> word) {
    count += 1;


    /*PARSE LEVEL 1*/
    if (level == 1) {

      /*HAS WORD APPEARED?*/
      for (vector<string>::const_iterator i = unique_words.begin(); i != unique_words.end(); i++) {
	if (word == *i) { duplicate = true; }
      }
      
      /*NO? INSERT IT*/
      if (!duplicate) { 
        iter = unique_words.end();
	unique_words.insert(iter, word);
      }
      duplicate = false;
    }


    /*PARSE LEVEL 2*/
    else if (level > 1) {
      
      /*HAS WORD APPEARED?*/
      for (iterator<string> i = cv_unique.begin(); i < cv_unique.end(); i++) {
        if (word == *i) { duplicate = true; }
      }

      /*NO? INSERT IT*/
      if (!duplicate) {
        iter = cv_unique.end();
        cv_unique.insert(iter, word);
      }
    }
    duplicate = false;
  
  }


  /*OUTPUT CODE BEINGS HERE*/
  switch(mode) {
    case total: cout << "Total: " << count << endl; break;
    case unique: 
      
      if (level == 1) {
	cout << "Unique: " << unique_words.size() << endl;
      }

      else if (level > 1) {
        cout << "Unique: " << cv_unique.size(); << endl;
      }
      break;
  }
}
