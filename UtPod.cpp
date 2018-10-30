//
// Created by Michael Sullivan1 on 10/21/18.
//

#include <cstdlib>
#include <ctime>
#include "UtPod.h"
#include <iostream>
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = nullptr;
}


UtPod::UtPod(int size){
    memSize = size;
    songs = nullptr;
}


int UtPod::addSong(Song const &s){
    if (s.getSize() > getRemainingMemory()){
        return NO_MEMORY;
    }
    auto *newSong = new SongNode;
    newSong->next = songs;
    newSong->s = s;
    songs = newSong;
    return SUCCESS;
}


int UtPod::removeSong(Song const &s){
    SongNode *trail = songs;
    SongNode *p;
    if (trail == nullptr){
        return NOT_FOUND;
    }
    if (trail->next == nullptr){
        if (trail->s == s){
            delete trail;
            songs = nullptr;
            return SUCCESS;
        }else{
            return NOT_FOUND;
        }
    }
    p = trail->next;
    while (p!=nullptr){
        if (p->s == s){
            trail->next = p->next;
            delete p;
            return SUCCESS;
        }

        trail = p;
        p = p->next;
    }
    return NOT_FOUND;
}


void UtPod::shuffle(){
    auto currentTime = (unsigned int) time(0);
    srand(currentTime);
    for (int i = 0; i < numSongs()*2 ; i++){
        int index1 = rand()%numSongs();
        int index2 = rand()%numSongs();
        SongNode* s1 = findNSong(index1);
        SongNode* s2 = findNSong(index2);
        Song temp = s1->s;
        s1->s = s2->s;
        s2->s = temp;
    }
}


void UtPod::showSongList(){
    cout << "--------------------------------------------" << endl;
    SongNode *p = songs;
    while (p!=nullptr){
        p->s.printSong();
        p = p->next;
    }
    cout << "--------------------------------------------" << endl;
}


void UtPod::sortSongList() {
    SongNode *frontNode = songs;
    while (frontNode != nullptr) {
        SongNode *p = frontNode->next;
        SongNode *minNode = p;
        while (p != nullptr) { // finds the minimum song
            if (p->s < minNode->s) {
                minNode = p;
            }
            p = p->next;
        }
        if (minNode != nullptr) {
            if (minNode->s < frontNode->s){
                Song temp = frontNode->s;
                frontNode->s = minNode->s;
                minNode->s = temp;
            }
        }
        frontNode = frontNode->next;
    }
}


void UtPod::clearMemory(){
    SongNode *p = songs;
    SongNode *tempNode;
    while (p!=nullptr){
        tempNode = p;
        p = p->next;
        delete tempNode;
    }
    songs = nullptr;
}


int UtPod::getRemainingMemory(){
    int memUsed = 0;
    SongNode* p = songs;
    while (p != nullptr){
        memUsed+=p->s.getSize();
        p = p->next;
    }
    return memSize-memUsed;
}


UtPod::~UtPod(){
    clearMemory();
}

int UtPod::numSongs() const {
    SongNode *p = songs;
    int total = 0;
    while (p!=nullptr){
        total+=1;
        p=p->next;
    }
    return total;
}


UtPod::SongNode* UtPod::findNSong(int n) const{
    SongNode* p = songs;
    for (int i = 0 ; i < n; i++) {
        p = p->next;
    }
    return p;
}
