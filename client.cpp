#include <iostream>
#include "SearchEngine.h"


int main(){
	SearchEngine engine("./moviesdb");

	engine.preProcess();
	string word;
	string cont = "N";
	while(cont == "N"){
	cout<< "Insert search word here: ";
	cin >> word;

	engine.search(word);
	cout<<"end (Y/N)? ";
	cin >> cont;
	}
	return 0;
}