//
// Created by Michael Sullivan1 on 10/19/18.
//

#include "Song.h"
#include <iostream>
using namespace std;


Song::Song(){
    title = "";
    artist = "";
    size = 0;
}

Song::Song(string _title, string _artist, int _size) {
    title = _title;
    artist = _artist;
    size = _size;
}

bool Song::operator<(Song const &rhs) {
    if (artist < rhs.artist){
        return true;
    }else if (artist == rhs.artist){
        if (title < rhs.title){
            return true;
        }else if (title == rhs.title){
            if (size < rhs.size){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

bool Song::operator>(Song const &rhs) {
    if (artist > rhs.artist){
        return true;
    }else if (artist == rhs.artist){
        if (title > rhs.title){
            return true;
        }else if (title == rhs.title){
            if (size > rhs.size){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

bool Song::operator==(Song const &rhs){
    if (artist == rhs.artist && title == rhs.title && size == rhs.size){
        return true;
    }
    return false;
}

string Song::getTitle() const {
    return title;
}
string Song::getArtist() const {
    return artist;
}
int Song::getSize() const {
    return size;
}

void Song::printSong() const {
    cout << "Title: " << title << " Artist: " << artist << " Size: " << size << endl;
}
