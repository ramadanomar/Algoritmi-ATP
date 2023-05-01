// SONG STRUCT
// id(int), title(char), artist(char), ratings(4 ratinguri de pe platforme diferite; unsigned char)

// RATING ORDERS (value 1 to 5)
// 1.Youtube Music, 2. Spotify, 3.Apple Music, 4.Amazon Music

// 1.Citind de la tastatura, scrie intr-un fisier 15 inregistrari reprezentand cantecele celor 2 artisti.  (2.5p)

//  2.Urmeaza lansarea in aprilie a unui album fizic. 
// Te poti ocupa de un singur artist. Folosind ca input fisierul de la punctul 1,
// alege artistul si selecteaza/scrie piesele acestuia intr-un fisier(albumul) separat. (2.5p)

// 3.Pentru ca albumul sa se vanda mai bine, te-ai gandit sa manipulezi ratingurile primite pe Spotify.
// Modifica ratingul Spotify la valoarea maxima(5) pentru toate cantecele din album. (2.5p)

// 4.O idee buna este sa ordonezi piesele de pe album in functie de cat de mult sunt apreciate.
// Ordoneaza piesele descrescator, utilizand media ratingurilor per piesa. (2.5p)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Song {
	int id;
	string title;
	string artist;
	unsigned char ratings[4];
};

vector<Song> ListaPiese;
vector<string> Artists;
vector<Song> Album;

void readData() {
	Song input;
	vector<string>::iterator it;
	for (int i = 0; i < 15; i++) {
		cin >> input.id >> input.title >> input.artist;
		it = find(Artists.begin(), Artists.end(), input.artist);
		if (it == Artists.end()) {
			// new artist was added
			Artists.push_back(input.artist);
		}
		for (int j = 0; j < 4; j++) {
			cin >> input.ratings[j];
		}
		ListaPiese.push_back(input);
	}
}

void createSongFile() {
	if (!ListaPiese.empty()) {
		ofstream fout("piese.txt");
		for (int i = 0; i < ListaPiese.size(); i++) {
			fout << ListaPiese[i].id << " " << ListaPiese[i].title << " " << ListaPiese[i].artist << " ";
			for (int j = 0; j < 4; j++) {
				fout << (int)ListaPiese[i].ratings[j] << " ";
			}
			fout << endl;
		}
		fout.close();
	}
}

void readDataFromFile() {
	Song input;
	ifstream fin("data.txt");
	vector<string>::iterator it;
	while (!fin.eof()) {
		fin >> input.id >> input.title >> input.artist;
		it = find(Artists.begin(), Artists.end(), input.artist);

		if (it == Artists.end()) {
			// new artist was added
			Artists.push_back(input.artist);
		}
		for (int j = 0; j < 4; j++) {
			fin >> input.ratings[j];
		}
		ListaPiese.push_back(input);
	}
	fin.close();
}


void createAlbum(string artist) {
	for (int i = 0; i < ListaPiese.size(); i++)
		if (ListaPiese[i].artist == artist) {
			Album.push_back(ListaPiese[i]);
		}
}

void modifySpotifyRatings() {
	for (int i = 0; i < Album.size(); i++) {
		Album[i].ratings[1] = 5 + 48; // 48 is the ascii value of 0
	}
}

void sortAlbum() {
	sort(Album.begin(), Album.end(), [](Song a, Song b) {
		return (((int)a.ratings[0] + (int)a.ratings[1] + (int)a.ratings[2] + (int)a.ratings[3]) / 4) > (((int)b.ratings[0] + (int)b.ratings[1] + (int)b.ratings[2] + (int)b.ratings[3]) / 4);
		});
}


void printAlbum() {
	for (int i = 0; i < Album.size(); i++) {
		cout << Album[i].id << " " << Album[i].title << " " << Album[i].artist << " ";
		for (int j = 0; j < 4; j++) {
			cout << (unsigned char)Album[i].ratings[j] << " ";
		}
		cout << endl;
	}
}

void createAlbumFile() {
	ofstream fout("album.txt");
	for (int i = 0; i < Album.size(); i++) {
		fout << Album[i].id << " " << Album[i].title << " " << Album[i].artist << " ";
		for (int j = 0; j < 4; j++) {
			fout << (unsigned char)Album[i].ratings[j] << " ";
		}
		fout << endl;
	}
}

int main() {
	//readData();
	//createSongFile();
	readDataFromFile();
	createAlbum("Artist1");
	modifySpotifyRatings();
	sortAlbum();
	printAlbum();
	createAlbumFile();
	return 0;
}