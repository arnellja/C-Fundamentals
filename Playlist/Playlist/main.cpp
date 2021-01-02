/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program creates and modifies a vector of pointer objects
representing Playlist objects, which are made of pointer objects
representing song objects.  It allows for adding and deleting songs to playlists,
adding and deleting playlists, and adding and deleting songs to the main
library.
Late Days: N/A
Deallocates memory on line 27, 33, 130, 156;
allocates memory on line 55, 72;

Test case 1:
Input: add, jeffs, jeffs song, list, quit.
Expected output: prompt for song name and firstline, list song in library and goodbye.
Result: passed.

Test case 2:
Input: 0, quit;
Expected output: options menu, goodbye.
Result: passed

Test case 3:
Input: 0, options, list, quit;
Expected output: options menu, options menu, nothing(no songs in library), goodbye;
Result: passed
*/

#include "Playlist.h"
#include "Song.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<limits>
#include<vector>
using namespace std;

vector<Playlist*> playlists;
vector<Song*> library;

void ClearPlaylists() {
	for (unsigned int counter = 0; counter < playlists.size(); ++counter) {
		for (unsigned int counter2 = 0; counter2 < playlists.at(counter)->GetSongVector().size(); ++counter2) {
			delete playlists.at(counter)->GetSongVector().at(counter2); //free memory
			playlists.at(counter)->GetSongVector().erase(playlists.at(counter)->GetSongVector().begin() + counter2);
		}
	}

	for (unsigned int counter = 0; counter < library.size(); ++counter) {
		delete library.at(counter); //free memory
		library.erase(library.begin() + counter);
	}
}

void AddToLibrary() {
	string songName;
	string firstLine;

	cout << "Read in Song names and first lines (type \"Stop\" when done) :" << endl;
	while (songName != "STOP") {
		cout << "Song name: " << endl;
		getline(cin, songName);
		if (songName == "STOP") {
			break;
		}
		cout << "Song's first line: " << endl;
		getline(cin, firstLine);

		

		library.push_back(new Song(songName, firstLine)); //allocate memory
	}
}

void ListLibrary() {
	for (unsigned int counter = 0; counter < library.size(); ++counter) {
		cout << library.at(counter)->GetSongName() << ": \"" << library.at(counter)->GetFirstLine() <<
			"\"," << library.at(counter)->GetTimesPlayed() << " play(s)." << endl;
	}
}

void AddPlaylist() {
	string newPlaylistName;

	cout << "Playlist name: " << endl;
	getline(cin, newPlaylistName);

	playlists.push_back(new Playlist(newPlaylistName)); //allocate memory
}

void AddSongToPlaylist() {
	int playlistIndex = 0;
	int songIndex = 0;

	for (unsigned int counter = 0; counter < playlists.size(); ++counter) {
		cout << counter << ": " << playlists.at(counter)->GetPlaylistName() << endl;
	}
	
	cout << "Pick a playlist index number: " << endl;
	cin >> playlistIndex;

	for (unsigned int counter = 0; counter < library.size(); ++counter) {
		cout << counter << ": " << library.at(counter)->GetSongName() << endl;
	}

	cout << "Pick a song index number: " << endl;
	cin >> songIndex;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

	

	playlists.at(playlistIndex)->AddSong(library.at(songIndex));
	
}

void ListPlaylists() {
	for (unsigned int counter = 0; counter < playlists.size(); ++counter) {
		cout << counter << ": " << playlists.at(counter)->GetPlaylistName() << endl;
	}
}

void PlayPlaylist() {
	int playlistIndex = 0;

	ListPlaylists();
	cout << "Pick a playlist index number: " << endl;
	cin >> playlistIndex;

	cout << "Playing first lines of playlist: " << playlists.at(playlistIndex)->GetPlaylistName() << endl;

	for (unsigned int counter = 0; counter < playlists.at(playlistIndex)->GetSongVector().size(); ++counter) {
		cout << playlists.at(playlistIndex)->GetSongVector().at(counter)->GetFirstLine() << endl;
		playlists.at(playlistIndex)->GetSongVector().at(counter)->IncreaseTimesPlayed();
	}
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	
}

void DeletePlaylist() {
	int playlistIndex = 0;

	ListPlaylists();
	cout << "Pick a playlist index number to delete: " << endl;
	cin >> playlistIndex;


	delete playlists.at(playlistIndex); //free memory
	playlists.erase(playlists.begin() + playlistIndex);
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void DeleteSongFromLibrary() {
	int songIndex = 0;
	string songName;
	

	for (unsigned int counter = 0; counter < library.size(); ++counter) {
		cout << counter << ": " << library.at(counter)->GetSongName() << endl;
	}

	cout << "Pick a song index number: " << endl;
	cin >> songIndex;

	songName = library.at(songIndex)->GetSongName();
	for (unsigned int counter = 0; counter < playlists.size(); ++counter) {
		for (unsigned int counter2 = 0; counter2 < playlists.at(counter)->GetSongVector().size(); ++counter2) {
			if (songName == playlists.at(counter)->GetSongVector().at(counter2)->GetSongName()) {
				playlists.at(counter)->DeleteSong(counter2);
			}
		}
	}

	delete library.at(songIndex); //free memory
	library.erase(library.begin() + songIndex);
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

}

void DeleteSongFromPlaylist() {
	int playlistIndex = 0;
	int songIndex = 0;

	ListPlaylists();
	cout << "Pick a playlist index number: " << endl;
	cin >> playlistIndex;

	playlists.at(playlistIndex)->ListPlaylist();
	cout << "Pick a song index number to delete: " << endl;
	cin >> songIndex;

	playlists.at(playlistIndex)->DeleteSong(songIndex);
	

	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void PrintOptions() {
	const int SPACING = 10;
	cout << left << setw(SPACING) << "add";
	cout << "Adds a list of songs to the library" << endl;
	cout << left << setw(SPACING) << "list";
	cout << "Lists all the songs in the library" << endl; 
	cout << left << setw(SPACING) << "addp";
	cout << "Adds a new playlist" << endl; 
	cout << left << setw(SPACING) << "addsp";
	cout << "Adds a song to a playlist" << endl; 
	cout << left << setw(SPACING) << "listp";
	cout << "Lists all the playlists" << endl; 
	cout << left << setw(SPACING) << "play";
	cout << "Plays a playlist" << endl; 
	cout << left << setw(SPACING) << "delp";
	cout << "Deletes a playlist" << endl; 
	cout << left << setw(SPACING) << "delsp";
	cout << "Deletes a song from a playlist" << endl; 
	cout << left << setw(SPACING) << "delsl";
	cout << "Deletes a song from the library (and all playlists)" << endl; 
	cout << left << setw(SPACING) << "options";
	cout << "Prints this options menu" << endl; 
	cout << left << setw(SPACING) << "quit";
	cout << "Quits the program" << endl; 
	return;
}


int main() {
	
	string menuChoice;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;

	while (menuChoice != "quit") {
		cout << "Enter your selection now: " << endl;
		cin >> menuChoice;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

		if (menuChoice == "add") {
			AddToLibrary();
		}
		else if (menuChoice == "list") {
			ListLibrary();
		}
		else if (menuChoice == "addp") {
			AddPlaylist();
		}
		else if (menuChoice == "addsp") {
			AddSongToPlaylist();
		}
		else if (menuChoice == "listp") {
			ListPlaylists();
		}
		else if (menuChoice == "play") {
			PlayPlaylist();
		}
		else if (menuChoice == "delp") {
			DeletePlaylist();
		}
		else if (menuChoice == "delsp") {
			DeleteSongFromPlaylist();
		}
		else if (menuChoice == "delsl") {
			DeleteSongFromLibrary();
		}
		else if (menuChoice == "options") {
			PrintOptions();
		}
		else if (menuChoice == "quit") {
			break;
		}
		else {
			PrintOptions();
		}

	}

	cout << "Goodbye!" << endl;

	//system("pause");
	return 0;
}