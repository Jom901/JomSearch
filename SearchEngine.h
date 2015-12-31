////////////////////////////////////////////////////
//
// J Search, a simple search engine class based on
// the requirements for my datastructures final
// project. As of right now, all functions except
// getdir were created by me. getdir was provided
// by Dr.Rafael Arce, the professor for my data-
// structures class.
//
/////////////////////////////////////////////////////

#include <sys/types.h>
#include "dirent.h"
#include <string>
#include <map>
#include <errno.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

class SearchEngine {
private:	
	string home;
  vector<string> files;
  std::map<string, std::map<string, int> > superHash;
public:
	SearchEngine() {};
	SearchEngine(string h) {home = h;}
 
 
  string getHome() {return home;}
 
  //preProcess executes the parsing algorithm I'll be using in the engine.
  void preProcess();

  //search searches through the superHash for the answer to the query
  void search(string phrase);
};



int getdir (string, vector<string> &);
