/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program declares the private data members for the playlist class
such as the playlist name and song vector.  It also declares the public
member functions such as a constructor method, accessor methods for the
private data members mentioned, and two modifier methods for adding and
deleting songs from the playlists song vector.

*/


#pragma once
#include "Song.h"
#include<string>
#include<vector>
using namespace std;

class Playlist
{
public:
	Playlist(string name);
	string GetPlaylistName() const;
	void ListPlaylist() const;
	vector<Song*> GetSongVector() const;
	void AddSong(Song* temp);
	void DeleteSong(int songIndex);

private:
	string playlistName;
	vector<Song*> songs;
	
};

#ifndef PLAYLIST_H
#define PLAYLIST_H
string GetPlaylistName();
void ListPlaylist();
vector<Song*> GetSongVector();
void AddSong(Song* temp);
void DeleteSong(int songIndex);
#endif