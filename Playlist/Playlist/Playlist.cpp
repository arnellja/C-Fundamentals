/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program defines the member functions of the playlist
class.  These include a constructor method, accessor methods for 
playlist name and song vector, and modifier methods for adding
and deleting songs from the vector.
*/



#include "Playlist.h"
#include "Song.h"
#include<iostream>
#include<vector>
using namespace std;

Playlist::Playlist(string name)
{
	playlistName = name;
	vector<Song*> songs;
}

string Playlist::GetPlaylistName() const {
	return playlistName;
}

vector<Song*> Playlist::GetSongVector() const{
	return songs;
}

void Playlist::ListPlaylist() const {
	for (unsigned int counter = 0; counter < songs.size(); ++counter) {
		cout << counter << ": " << songs.at(counter)->GetSongName() << endl;
	}
}

void Playlist::AddSong(Song* temp) {
	songs.push_back(temp);
	return;
}

void Playlist::DeleteSong(int songIndex) {
	songs.erase(songs.begin() + songIndex);
}
