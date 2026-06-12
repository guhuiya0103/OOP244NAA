/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// You may modify any code in this file to suit your requirements.
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
 

   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);//'\0'
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }

   Account::operator bool() const{
      if (m_number <= 99999 && m_number >= 10000 && m_balance >= 0.0 && m_holderName[0] != char(0)){
         return true;
      }else{
         return false;
      }
   }
   Account::operator int() const{
      return m_number;
   };
   Account::operator double() const{
      return m_balance;
   }
   Account::operator const char*() const{
      return m_holderName;
   }
   char& Account::operator[](int index){
      int result = index % 30;
      return m_holderName[result];
   }
   const char Account::operator[](int index)const{
      int result = index % 30;
      return m_holderName[result];
      //带Operator的function，都是在用同样的概念去赋予【】在ACCOUNT原本里面的作用，做新的功能
   }
   Account& Account::operator=(int value){
      if (m_number == 0 && m_holderName[0] != char(0)){
         m_number = value;
         if (true != isValidNumber(value)){
            m_holderName[0] = char(0);
            m_number = -1;
            m_balance = 0.0;
         }
      }
      return *this; // this 是指 current object pointer ，*的作用是通过pointer找到 对应的实际数据
   }
   Account& Account::operator=(double value){
      if(value >= 0){
         m_balance = value;
      }else{
         m_holderName[0] = char(0);
         m_number = -1;
         m_balance = 0.0;
      }
      return *this;
   }
   Account& Account::operator+=(double value){
      if(*this && value >= 0){//represent the bool operator return value line #90
         m_balance+=value;
      } 
      return *this;
   }
   Account& Account::operator-=(double value){
      if(*this && value >=0 && m_balance >= value){
         m_balance-=value;
      }
      return *this;
   }
   Account& Account::operator<<(Account& otherAccount){
      if(otherAccount.m_number != (*this).m_number){
         m_balance += otherAccount.m_balance;
         otherAccount.m_balance = 0;
      }
      return *this;
      
   }
   Account& Account::operator>>(Account& otherAccount){
      if(otherAccount.m_number !=(*this).m_number){
         otherAccount.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   bool Account::operator~() const{
      if(m_number == 0){
         return true;
      }else return false;
      
   }
   Account& Account::operator++(){
      m_balance += 1;
      return *this;
   }
   Account Account::operator++(int){
      Account before = *this;// create a new variable of the current status
      m_balance += 1; // changed value
      return before;
   }
   Account& Account::operator--(){
      if(m_balance >=1){
         m_balance -= 1;
      }
      return *this;
   }
   Account Account::operator--(int){
      Account before =*this;
      if(m_balance >=1){
         m_balance -= 1;
      }
      return before;
   };

}