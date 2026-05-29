#include <iostream>
#include "Contact.h"

using namespace std;
using namespace seneca;

int main() {
    Contact c1;
    Contact c2("John Smith", 4165551234LL);
    Contact c3("", 4165551234LL);
    Contact c4("Mary Brown", 12345LL);
    Contact c5(nullptr, 4165551234LL);

    cout << "Testing constructors:" << endl;
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();
    cout << endl;

    cout << "Testing set function:" << endl;
    c1.set("Alex Green", 6475559876LL);
    c1.display();

    c1.set("Invalid Phone", 999LL);
    c1.display();

    c1.set("Sara White", 9055551111LL);
    c1.display();

    c1.set(nullptr, 4165552222LL);
    c1.display();

    return 0;
}