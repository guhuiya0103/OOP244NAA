#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }
   void CC::aloCopy(const char* name){
      cardholderName = new char[strlen(name)+1];
      strcpy(cardholderName, name);
   }
   void CC::deallocate(){
      delete[] cardholderName;
      cardholderName = nullptr;

   }
   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const{
      if (name == nullptr || strlen(name) <= 2){
         return false;
      }
      if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull){
         return false;
      }
      if (cvv >999 || cvv <100){
         return false;
      }
      if (expMon < 1 || expMon >12){
         return false;
      }
      if (expYear < 24 || expYear>32){
         return false;
      }
      return true;
   }
   void CC::set(){ // chushihua initialize
      cardholderName = nullptr;
      securityDigits = 0;
      expMonth = 0;
      expYear = 0;
      cardNumber = 0;
   }
   bool CC::isEmpty()const{
      if(cardholderName != nullptr){
         return false;
      }
      return true;
   }
   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYr){
      deallocate();
      set();
      bool isValidated = validate(cc_name, cc_no, cvv, expMon, expYr);
      if (isValidated == true){
         aloCopy(cc_name);
         securityDigits = cvv;
         expMonth = expMon;
         expYear = expYr;
         cardNumber = cc_no;
      }
   }
   void CC::display() const{
      bool empty = isEmpty();
      if(empty == true){
         cout << "Invalid Credit Card Record" << endl;
      }else{
         display(cardholderName, cardNumber, expYear, expMonth, securityDigits);
      }
   } 
   CC::CC(){
      set();
   }
   CC::CC(const char* cardName, unsigned long long cardNum, short digits, short expMon, short expYr){
      set(cardName, cardNum, digits, expMon, expYr);
   }
   CC::~CC(){
      deallocate();
   }
}  
