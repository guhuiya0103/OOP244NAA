#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include <iostream>
namespace seneca{
    template <typename T>
    T* dynaCopy(const T* sourceArr, int sizeArr){
        T* newArr = nullptr;
        newArr = new T[sizeArr];
        for(int i = 0; i < sizeArr; i++){
            newArr[i] = sourceArr[i];
        }
        return newArr;
    }

    template <typename T>
    T*& dynaCopy(T*& destArr, const T* sourceArr, int sizeArr){
        delete[] destArr;
        destArr = new T[sizeArr];
        for(int i = 0; i < sizeArr; i++){
            destArr[i] = sourceArr[i];
        }
        return destArr;
    }

    template <typename T>
    void prnArray(const T* printArr, int sizeArr){
        for(int i = 0; i < sizeArr; i++){
            if(i != sizeArr-1){
                std::cout<<printArr[i]<<", ";
            }
            else{
                std::cout<<printArr[sizeArr-1];
            }
            
        }
        std::cout<<std::endl;
    }
}

#endif