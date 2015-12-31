#include "SearchEngine.h"
#include "dirent.h"
//getdir acquires every file name in the home directory
int getdir (string dir, vector<string> &files)
{
DIR *dp;
struct dirent *ent;
if ((dp = opendir ("./moviesdb")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dp)) != NULL) {
    files.push_back(ent->d_name);
  }
  closedir (dp);
} else {
  /* could not open directory */
  perror ("");
  return EXIT_FAILURE;
}
    return 0;
}

//preProcess executes the parsing algorithm I'll be using in the engine.
void SearchEngine::preProcess(){
	getdir(home, files);
	int count = 0;
	vector<string> txt;
	string templine = "";
	//for each file, open it and tokenize it
	for(int i = 0; i < files.size(); i++){
		templine = "";
		templine = files[i][0];
		if(templine != "."){
		ifstream reader(home+ "/"+files[i]);
		if(reader.is_open()){
			while(getline(reader,templine, ' ')){
				txt.push_back(templine);
			}
			reader.close();
		}
		for(int j = 0; j < txt.size(); j++){
			superHash[txt[j]][files[i]]++;
		}
		
		count++;
	}
	txt.clear();
}
	cout << "Number of files tokenized: " << count<<"\n";
	return ;

}

//search searches through the superHash for the answer to the query
void SearchEngine::search(string phrase){
    map<string, map<string, int> >::iterator it;
    map<string, int>::iterator mykey;
    int freq[3];
    for(int i = 0 ; i < 3 ; i ++){
    	freq[i] = 0;
    }
    string movie[3];
    for(int i = 0 ; i < 3 ; i ++){
    	movie[i] = "N/A";
    }
for(mykey = superHash[phrase].begin() ; mykey != superHash[phrase].end(); mykey++){
	if(mykey->second > freq[0] ){
		freq[2] = freq[1];
		movie[2] = movie[1];
		
		freq[1] = freq[0];
		movie[1] = movie[0];
		
		freq[0] = mykey->second;
		movie[0] = mykey->first;

	}else if(mykey->second > freq[1]){
		freq[2] = freq[1];
		movie[2] = movie[1];

		freq[1] = mykey->second;
		movie[1] = mykey->first;
	}else if(mykey->second > freq[2]){

		freq[2] = mykey->second;
		movie[2] = mykey->first;

	}

}

	cout << "Results: \n";
for(int i = 0 ; i < 3 ; i ++){
	cout << movie[i] << "\n";
}
return ;
}