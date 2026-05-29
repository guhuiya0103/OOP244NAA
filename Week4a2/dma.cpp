#include <iostream>
#include "dma.h"
#include <cstring>
using namespace std;
using namespace seneca;

namespace seneca {
    Samples* CreateSamples(const char* title){
        Samples *sample = nullptr;
        sample = new Samples;
        sample->m_title = new char[strlen(title)]; //ask the memory from the system for the space to allocate the new titles
        strcpy(sample->m_title, title);

        sample->m_data = nullptr;
        sample->m_size = 0;
        
        return sample;
    };

    void add(Samples& S, const int data[], int size){
        if(S.m_data == nullptr){
           S.m_data = new int[size];
           
           for(int i=0;i<size;i++){
                S.m_data[i] = data[i];   
           }
        } else{
            append(S.m_data, S.m_size, data, size);
        }

        S.m_size += size;
    };

    void append(int*& data, int size, const int appendedData[], int dataSize){
        int* newSpace = new int[size + dataSize];
        for (int i = 0; i < size; i++) {
            newSpace[i] = data[i];
        }
        for (int i = size; i < size + dataSize; i ++) {
            newSpace[i] = appendedData[i - size];
        }

        delete [] data;
        data = nullptr;
        data = newSpace;
    };

    void freemem(Samples*& s){
        delete [] s->m_data;
        s->m_data = nullptr;
        delete [] s->m_title;
        s->m_title = nullptr;
        delete [] s;
        s = nullptr;
    };
}