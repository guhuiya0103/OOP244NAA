#ifndef SENECA_IO_H
#define SENECA_IO_H
#include <iostream>
using namespace std;
namespace seneca {
    struct PhoneRec{
        char firstName[16];
        char lastName[26];
        long long phoneNumber;
    };
    void read(char* name);
    void print(long long phoneNumber);
    void print(const PhoneRec& rec, size_t& rowNumber, const char* nameFilter=nullptr);
    bool read (PhoneRec& rec, FILE* fptr);
    void print(PhoneRec* recs[], size_t numRecs, const char* nameFilter=nullptr);
    void setPointers(PhoneRec* recsPtrs[], PhoneRec recs[], size_t numRecs);
    void sort(PhoneRec* recsPtrs[], size_t numRecs, bool useLastName);
}    
#endif
