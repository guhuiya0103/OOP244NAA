#include "io.h" 
#include <iostream>
using namespace std;
namespace seneca {
    void read(char* name){
        cout << "name>\n ";
        cin >> name;
    }
    void print(long long phoneNumber){
        long long areaCode = phoneNumber / 10000000;
        long long prefix = (phoneNumber / 10000) % 1000;
        long long lineNumber = phoneNumber % 10000;
        cout << "(" << areaCode << ") " << prefix << "-" << lineNumber << endl;
    }
    void print(const PhoneRec& rec, size_t& rowNumber, const char* nameFilter){
        if (nameFilter == nullptr || strstr(rec.firstName, nameFilter) || strstr(rec.lastName, nameFilter)) {
            cout << rowNumber << ": " << rec.firstName << " " << rec.lastName << " ";
            print(rec.phoneNumber);
            rowNumber++;
        }
    }
    bool read (PhoneRec& rec, FILE* fptr){
        if(fptr == nullptr){
            return false;
        }else{
            if(fscanf(fptr, "%s %s %lld", rec.firstName, rec.lastName, &rec.phoneNumber) == 3){
                return true;
            }
        }
        return false;
    }
    void print(PhoneRec* recs[], size_t numRecs, const char* nameFilter){
        size_t rowNumber = 1;
        for (size_t i = 0; i < numRecs; i++) {
            print(*recs[i], rowNumber, nameFilter);
        }
    }
    void setPointers(PhoneRec* recsPtrs[], PhoneRec recs[], size_t numRecs){
        for (size_t i = 0; i < numRecs; i++){
            recsPtrs[i] = &recs[i];
        }
    }

    void sort(PhoneRec* recsPtrs[], size_t numRecs, bool useLastName){
        for (size_t i = 0; i < numRecs - 1; i++) {
            for (size_t j = i; j < numRecs; j++) {
                if (useLastName == true) {
                    if (strcmp(recsPtrs[i]->lastName, recsPtrs[j]->lastName) >0) {
                        PhoneRec* temp = recsPtrs[i];
                        recsPtrs[i] = recsPtrs[j];
                        recsPtrs[j] = temp;
                    }
                }else{
                    if (strcmp(recsPtrs[i]->firstName, recsPtrs[j]->firstName) > 0) {
                        PhoneRec* temp = recsPtrs[i];
                        recsPtrs[i] = recsPtrs[j];
                        recsPtrs[j] = temp; // if i < 9, then i = 0-8, j > i, then j = 1-9, so we compare the value in the posution
                    }
                }
            }
        }  
    }
}
