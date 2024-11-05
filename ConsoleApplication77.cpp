#include <iostream>

class String {
private:
    char* data;
    int length;

    int StringLenght(const char* str) const {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    void CopyString(char* dest, const char* src) {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    String() : data(nullptr), length(0) {}

    String(const char* str) {
        length = StringLenght(str);
        data = new char[length + 1];
        CopyString(data, str);
    }

    String(const String& other) : length(other.length) {
        data = new char[length + 1];
        CopyString(data, other.data);
    }

    int getLength() const {
        return length;
    }

    bool equals(const String& other) const {
        if (length != other.length) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    ~String() {
        delete[] data;
    }

    void print() const {
        if (data) {
            std::cout << data;
        }
    }
};

int main() {
    String str1("Hello world");
    String str2("Hello world");

    str1.print();
    std::cout << std::endl;
    std::cout << "Length of str1: " << str1.getLength() << std::endl;

    str2.print();
    std::cout << std::endl;
    std::cout << "Length of str2: " << str2.getLength() << std::endl;

    String str3("Hello world");
    std::cout << "str1 equals str3: " << (str1.equals(str3) ? "Yes" : "No") << std::endl;

    return 0;
}
