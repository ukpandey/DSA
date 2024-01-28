#include <cstring> // For strlen, strcpy, and other string functions
#include <iostream>

class String {
private:
    char* str;

public:
    // Default constructor
    String() : str(nullptr) {}

    // Parameterized constructor
    String(const char* s) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = nullptr;
        }
    }

    // Copy constructor
    String(const String& other) {
        if (other.str) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str; // Free the existing memory

            if (other.str) {
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);
            } else {
                str = nullptr;
            }
        }
        return *this;
    }

    // Concatenation operator
    String operator+(const String& other) const {
        String result;
        result.str = new char[length() + other.length() + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // Getter for the length of the string
    size_t length() const {
        return str ? strlen(str) : 0;
    }

    // Getter for the C-style string
    const char* c_str() const {
        return str ? str : "";
    }
};

// Overloading the stream insertion operator for easy printing
std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.c_str();
    return os;
}

int main() {
    // Testing the String class
    String s1 = "Hello";
    String s2 = " World";
    String s3 = s1 + s2;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;

    return 0;
}
