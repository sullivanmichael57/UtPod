//
// Created by Michael Sullivan1 on 10/19/18.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H
#include <string>

using namespace std;


class Song{
private:
    string title;
    string artist;
    int size;
public:
    Song();
    Song(string _title, string _artist, int _size);
    string getTitle() const;
    string getArtist() const;
    int getSize() const;
    void printSong() const;
    bool operator <(Song const &rhs);
    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
};