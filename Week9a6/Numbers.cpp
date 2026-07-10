#include "Numbers.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
namespace seneca{
    
    Numbers::~Numbers(){
        save();
        delete[] m_numbers;
        delete[] m_filename;      
    }
    
    Numbers::Numbers(const Numbers& other){
        setEmpty();
        m_isOriginal = false;
        
        if(!other.isEmpty()){
            m_numbers = new double[other.m_numCount];
            m_numCount = other.m_numCount;
            for(int i = 0; i < m_numCount; i++){
                m_numbers[i] = other.m_numbers[i];
            }          
        }
    }

    Numbers& Numbers::operator=(const Numbers& other){
        if(this !=&other){
            delete[] m_numbers;
            m_numbers = nullptr;
            m_numCount = 0;
            if(!other.isEmpty()){
                m_numbers = new double[other.m_numCount];
                for(int i = 0; i < other.m_numCount; i++){
                    m_numbers[i] = other.m_numbers[i];
                }
                m_numCount = other.m_numCount;
            }
        }
        return *this;
    }

    int Numbers::numberCount()const{
        ifstream file(m_filename);
        int numLine = 0;
        char singleLetter;
        while(file.get(singleLetter)){
            if(singleLetter=='\n'){
                numLine++;
            }
        } 
        return numLine;
    }

    bool Numbers::load(){
        int i = 0;
        if(m_numCount>0){
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            double aValue;
            while(file >> aValue){
                m_numbers[i] = aValue;
                i++;
            }    
        }
        if(i!=m_numCount){
            delete[] m_numbers;
            setEmpty();
            return false;
        }
        else{
            return true;
        }

    }
    void Numbers::save(){
        if(m_isOriginal == true && !isEmpty()){
            ofstream file(m_filename);
            for(int i = 0; i < m_numCount; i++){
                file << m_numbers[i] << endl;
            }
        }
    }
    Numbers& Numbers::operator+= (double value){ //目标是把新的数据写到原来的m_number里去，
        
        if(!isEmpty()){
        double* temp = new double[m_numCount + 1];//不能直接写因为没有空间放值，所以扩展空间
        for(int i = 0; i < m_numCount; i++){ // 抄下来原来的每一个数据；
            temp[i] = m_numbers[i];
        }
        temp[m_numCount] = value; // m_numCount 代表新的temp抄写的最后一个位置，再把value写进去
        m_numCount++;
        delete[] m_numbers;
        m_numbers = temp;
        sort();
        }
        return *this;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const{
        if(isEmpty()){
            ostr << "Empty list";
        }
        else{
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "========================="<<endl;
            if(m_isOriginal == true){
                ostr << m_filename <<endl;
            }
            else{
                ostr << "*** COPY ***" <<endl;
            }
            for(int i = 0; i<m_numCount; i++){
                ostr << m_numbers[i];
                if(i < m_numCount-1){
                    ostr << ", ";
                }
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const Numbers& N){
        return N.display(os);
    }

    std::istream& operator>>(std::istream& istr, Numbers& N){
        double value;
        if(istr >> value){
            N += value;
        }
        return istr;
    }
}

    