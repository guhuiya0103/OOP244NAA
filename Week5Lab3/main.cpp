#include <iostream>
#include "Battery.h"
 
using namespace std;
using namespace sdds;
 
int main() {
   Battery a;
   Battery b(45);
   Battery c(150);
 
   cout << "Initial values:" << endl;
   a.display() << endl;
   b.display() << endl;
   c.display() << endl;
 
   cout << endl << "Setting battery a to 20:" << endl;
   a.set(20);
   a.display() << endl;
 
   cout << endl << "Charging b by 30:" << endl;
   (b += 30).display() << endl;
 
   cout << endl << "Trying to overcharge b by 50:" << endl;
   (b += 50).display() << endl;
 
   cout << endl << "Draining b by 50:" << endl;
   (b -= 50).display() << endl;
 
   cout << endl << "Trying to over-drain b by 50:" << endl;
   (b -= 50).display() << endl;
 
   cout << endl << "Prefix ++ on a:" << endl;
   (++a).display() << endl;
 
   cout << endl << "Postfix ++ on a:" << endl;
   Battery old = a++;
   cout << "Old value: ";
   old.display() << endl;
   cout << "New value: ";
   a.display() << endl;
 
   cout << endl << "Testing bool conversion:" << endl;
   if (a) {
      cout << "a has usable charge." << endl;
   }
   else {
      cout << "a is empty." << endl;
   }
 
   Battery empty(0);
   if (empty) {
      cout << "empty has usable charge." << endl;
   }
   else {
      cout << "empty is empty." << endl;
   }
 
   cout << endl << "Testing int conversion:" << endl;
   int level = b;
   cout << "b charge level is " << level << "%" << endl;
 
   cout << endl << "Testing display with explicit stream:" << endl;
   b.display(cout) << endl;
 
   return 0;
}