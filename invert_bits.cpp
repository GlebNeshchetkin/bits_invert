#include <iostream>
#include <bitset>

void printBinary(unsigned char* ptr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        std::bitset<8> bits(*ptr);
        std::cout << bits << " ";
        ++ptr;
    }
    std::cout << std::endl;
}

void invertAllBits(unsigned char* ptr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        *ptr = ~(*ptr);
        ++ptr;
    }
}

void invertSecondBits(unsigned char* ptr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        *ptr ^= 0x55;
        ++ptr;
    }
}

void invertThirdBits(unsigned char* ptr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        *ptr ^= 0x24;
        ++ptr;
    }
}

int main() {
    unsigned char array_to_inverse[] = { 0xA, 0xBB, 0xCC };
    size_t length = sizeof(array_to_inverse);

    std::cout << "Before inverting bits:" << std::endl;
    printBinary(array_to_inverse, length);

    invertAllBits(array_to_inverse, length);

    std::cout << "After inverting bits:" << std::endl;
    printBinary(array_to_inverse, length);

    return 0;
}
