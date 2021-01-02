/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program declares the private data members of the 
song class including song name, first line, and times played, and 
the public member functions such as a constructor method, accessor methods
for the mentioned data members and a modifier method for increasing 
times played.

*/

#pragma once
#include<string>
using namespace std;

class Song
{
public:
	Song(string name, string firstLyrics);
	string GetSongName() const;
	string GetFirstLine() const;
	void IncreaseTimesPlayed();
	int GetTimesPlayed() const;

private:
	string songName;
	string firstLine;
	int timesPlayed;
};


#ifndef SONG_H
#define SONG_H

string GetSongName();
string GetFirstLine();
void IncreaseTimesPlayed();
int GetTimesPlayed();

#endif