#include <iostream>
using namespace std;
#include <string>
#include "UtPod.h"
#include <fstream>
#include <string.h>


string removeUnderscores(string input);

int main() {
    cout << "Hello, World!" << endl;
    UtPod pod = UtPod(256);
    ifstream infile;
    infile.open("testCases.txt");
    string line;

    while (infile){
        infile >> line;
        if (line == "add" || line == "remove"){
            string _title,_artist,_size;
            infile >> _title;
            infile >> _artist;
            infile >> _size;
            if (line == "add"){
                pod.addSong(Song(removeUnderscores(_title),removeUnderscores(_artist),stoi(_size)));
            }else{
                pod.removeSong(Song(_title,_artist,stoi(_size)));
            }
        }else if (line == "sort"){
            cout << "Sorting List . . . " << endl;
            pod.sortSongList();
        }else if (line == "print"){
            cout << "Current Data: " << endl;
            pod.showSongList();
        }else if (line == "shuffle"){
            cout << "Shuffling Songs . . . " << endl;
            pod.shuffle();
        }else if (line == "exit"){
            cout << "Finished Processing Instructions" << endl;
            break;
        }
    }

    /*while (getline(infile,line)){
        string title,artist,size;
        int i = 0;
        while(line[i]!=','){
            title+=line[i];
            i++;
        }
        i+=2;
        while (line[i]!=','){
            artist+=line[i];
            i++;
        }
        i+=2;
        while (i<line.size()){
            size+=line[i];
            i++;
        }
        pod.addSong(Song(title,artist,stoi(size)));
        cout << "remaining memory: " << pod.getRemainingMemory() << endl;
    }


    cout << "Current List: " << endl;
    pod.showSongList();
    pod.shuffle();
    cout << "-------------" << endl << "Shuffled List" << endl;
    pod.showSongList();
    pod.sortSongList();
    cout << "-------------" << endl << "Sorted List" << endl;
    pod.showSongList();
    */

}

string removeUnderscores(string input){
    for (int i = 0; i<input.length() ; i++){
        if (input.at(i) == '_'){
            input.replace(i,1," ");
        }
    }
    return input;
}