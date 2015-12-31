## JomSearch

This project is a re-do of my 2012 Data Structures final project. The program
consists of a client file, a class header and a class descriptor file. Essentially,
this is supposed to simulate a program that reads an old collection of IMDB files and
collects the names of the top 3 movies that contain whatever word you input. 

# Instructions

In order to run this program, simply type the following in your terminal.

```shell
$ g++ client.cpp  SearchEngine.cpp -o search
$ ./search
```
As it stands, it runs for C+98, haven't tried it with C++11, though i don't see a reason for it not to work.

#Side notes

The only function in this program that was not created by me is the getdir function,
which was created by the professor of my Datastructures class, Dr.Rafael Arce.

Note: This repo is missing the IMDB text files that it was meant to work with. While
this program will likely work with most collections of text files, I haven't tried it.
