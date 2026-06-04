#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      char* cardholderName;
      short securityDigits;
      short expMonth;
      short expYear;
      unsigned long long cardNumber;
      //method = fubction; property = attributes
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      void prnNumber(unsigned long long no) const;
      void aloCopy(const char* name);
      void deallocate();
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
   public:
      CC();
      CC(char* cardName, unsigned long long cardNum, short digits, short expMon=12, short expYr=26);
      ~CC();
      void set();
      bool isEmpty() const;
      void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYr);
      void display() const;

      
   };
}
#endif // !SENECA_CC_H_


