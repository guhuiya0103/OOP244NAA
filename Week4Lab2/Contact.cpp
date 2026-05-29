#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace seneca {

    // Safely releases dynamic memory and resets pointer
    void Contact::deallocate() {
        delete[] m_name;
        m_name = nullptr;
    }

    // Default constructor: creates an empty contact
    Contact::Contact() {
        m_name = nullptr;
        m_phoneNumber = 0;
    }

    // Two-argument constructor
    Contact::Contact(const char* name, long long phoneNumber) {
        // Initialize fields first so set() doesn't deallocate garbage pointers
        m_name = nullptr;
        m_phoneNumber = 0;
        set(name, phoneNumber);
    }

    // Destructor
    Contact::~Contact() {
        deallocate();
    }

    // Puts the object into a clean, safe empty state
    void Contact::setEmpty() {
        deallocate();
        m_phoneNumber = 0;
    }

    // Returns true if the contact state represents an empty target
    bool Contact::isEmpty() const {
        return m_name == nullptr;
    }

    // Validates if the phone number meets the exact 10-digit boundaries
    bool Contact::validPhone(long long phoneNumber) const {
        return (phoneNumber >= 1000000000LL && phoneNumber <= 9999999999LL);
    }

    // Sets or replaces contact info with fresh dynamic allocation
    void Contact::set(const char* name, long long phoneNumber) {
        // Always clean up existing memory allocation first
        deallocate();

        if (name && name[0] != '\0' && validPhone(phoneNumber)) {
            // Allocate exact memory size including null-terminator
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_phoneNumber = phoneNumber;
        } else {
            setEmpty();
        }
    }

    // Displays contact content matching expected formatting rules
    void Contact::display() const {
        if (isEmpty()) {
            cout << "Invalid Contact" << endl;
        } else {
            cout << "Name: " << m_name << ", Phone: " << m_phoneNumber << endl;
        }
    }

}