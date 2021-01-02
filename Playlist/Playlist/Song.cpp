/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program defines the member functions for the Song
class.  Functions include, constructor method, accessor methods
for song name, firstline and times played, and a modifier method
for increasing the times played.
*/

#include "Song.h"



Song::Song(string name, string firstLyrics)
{
	songName = name;
	firstLine = firstLyrics;
	timesPlayed = 0;
}


string Song::GetFirstLine() const{
	return firstLine;
}

string Song::GetSongName() const {
	return songName;
}

int Song::GetTimesPlayed() const {
	return timesPlayed;
}

void Song::IncreaseTimesPlayed() {
	timesPlayed++;
	return;
}