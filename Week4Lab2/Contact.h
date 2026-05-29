#ifndef SENECA_CONTACT_H
#define SENECA_CONTACT_H

namespace seneca {

    class Contact {
        char* m_name;
        long long m_phoneNumber;

        // Private helper function to handle safe resource deallocation
        void deallocate();

    public:
        // Constructors & Destructor
        Contact();
        Contact(const char* name, long long phoneNumber);
        ~Contact();

        // Member Functions
        void setEmpty();
        bool isEmpty() const;
        bool validPhone(long long phoneNumber) const;
        void set(const char* name, long long phoneNumber);
        void display() const;
    };

}

#endif // SENECA_CONTACT_H