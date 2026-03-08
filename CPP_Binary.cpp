#include <iostream>

void printBinary(unsigned int n) {
    int mask = 1 << 8;
    std::cout << "Number as Binary is ";
    while (mask > 0) {
        bool result = n & mask;
        std::cout << result;
        mask = mask >> 1;
    }
    std::cout << std::endl;
}

bool isEven(int n) {
    int mask = 1;

    if (n & mask)
        return false;
    else
        return true;
}

// n is integet
// i is the i-th bit to find
int getBit(int n, int i) {
    int mask = 1;

    int result = (n >> i) & mask;

    return result;
}

int setBit(int n, int i) {
    int mask = 1 << i;

    return (n | mask);
}


int clearBit(int n, int i) {
    int mask = ~(1 << i);
    int result = n & mask;

    return result;
}


int toggleBit(int n, int i) {
    int mask = 1 << i;
    int result = n ^ mask;

    return result;
}

int countSetBits(int n) {
    int counter = 0;
    printBinary(n);
    while (n) {
        counter++;
        n &= n - 1;
    }
    return counter;
}

bool isPowerOfTwo(int n);

void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

bool oppositeSigns(int x, int y) {
    return (x ^ y) > 0;
}

unsigned int reverseBits(unsigned int n) {
    return ~n;
}

int add(int a, int b) {
    int carry;
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

int multiply(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    int result = 0;

    while (b > 0) {
        if (b & 1) {
            result = add(result, a);
        }

        a <<= 1;
        b >>= 1;
    }

    return result;
}

int substract(int x, int y) {
    int borrow = 0;

    while (y != 0) {
        borrow = (~x) & y;

        x ^= y;

        y = borrow << 1;
    }

    return x;
}

int divide(int dividend, int divisor) {
    if (dividend == divisor) {
        return 1;
    }

    if (dividend == 0 || dividend < divisor) {
        return 0;
    }

    if (divisor == 0) {
        std::cout << "Cannot divide on 0" << std::endl;
        return 0;
    }

    int result = 1;
    int orig_divisor = divisor;

    while (dividend > divisor) {
        divisor <<= 1;
        result <<= 1;
    }

    if (dividend < divisor) {
        divisor >>= 1;
        result >>= 1;
    }

    result += divide(substract(dividend, divisor), orig_divisor);

    return result;
}

bool isPowerOfFour(int n) {
    if (n == 1) return true;
    if (n <= 0) return false;

    if ((n & 3) != 0) return false;

    int result = n >> 2;
    return isPowerOfFour(result);
}

enum Permission {
    READ = 1,
    WRITE = 2,
    EXECUTE = 4,
    DELETE = 8
};
/*
    Write functions to: - Add permission - Remove permission - Check permission - Print permissions
*/

void printMenu() {
    std::cout << "1. Print Binary." << std::endl;
    std::cout << "2. Is number even?" << std::endl;
    std::cout << "3. Get i-th bit." << std::endl;
    std::cout << "4. Set i-th bit." << std::endl;
    std::cout << "5. Clear i-th bit." << std::endl;
    std::cout << "6. Toggle i-th bit." << std::endl;
    std::cout << "7. Count set bits." << std::endl;
    std::cout << "8. Is Power of 2?" << std::endl;
    std::cout << "9. Swap two numbers" << std::endl;
    std::cout << "10. Are signs opposite?" << std::endl;
    std::cout << "11. Reverse bits." << std::endl;
    std::cout << "12. Addition" << std::endl;
    std::cout << "13. Multiply" << std::endl;
    std::cout << "14. Divide" << std::endl;
    std::cout << "15. Is power of 4." << std::endl;
    std::cout << "16. Permissions." << std::endl;
    std::cout << "17. Exit" << std::endl;
    std::cout << "Please chose one number to execute: ";
}

void executeChoice(int& choice) {
    unsigned int uNumber = 0;
    int number = 0;
    int bitNumber = 0;

    switch (choice) {
    case 1: {
        std::cout << std::endl;
        std::cout << "Please enter a number: ";
        std::cin >> uNumber;
        printBinary(uNumber);
        std::cout << std::endl;
    }
          break;
    case 2: {
        std::cout << std::endl;
        std::cout << "Please enter a number: ";
        std::cin >> number;;
        if (number == true) {
            std::cout << "Number is odd" << std::endl;
        }
        else {
            std::cout << "Number is even" << std::endl;
        }
        std::cout << std::endl;
    }
          break;
    case 3: {
        std::cout << std::endl;
        std::cout << "Please enter a number: ";
        std::cin >> number;
        std::cout << "Please enter a bit number: ";
        std::cin >> bitNumber;
        std::cout << "the i-th bit is " << getBit(number, bitNumber) << std::endl;
        std::cout << std::endl;
    }
          break;
    case 4: {
        std::cout << std::endl;
        std::cout << "Please enter a number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter a bit number: " << std::endl;
        std::cin >> bitNumber;
        std::cout << "the i-th bit is " << setBit(number, bitNumber) << std::endl;
        std::cout << std::endl;
    }
          break;
    case 5: {
        std::cout << std::endl;
        std::cout << "Please enter a number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter a bit number: " << std::endl;
        std::cin >> bitNumber;
        std::cout << "Before change:" << std::endl;
        printBinary(number);
        number = clearBit(number, bitNumber);
        std::cout << "number after setting the i-th bit to `0` is " << number << std::endl;
        printBinary(number);
        std::cout << std::endl;
    }
          break;
    case 6: {
        std::cout << std::endl;
        std::cout << "Please enter a number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter a bit number: " << std::endl;
        std::cin >> bitNumber;
        std::cout << "the i-th bit was changed to " << toggleBit(number, bitNumber) << std::endl;
        std::cout << std::endl;
    }
          break;
    case 7: {
        std::cout << std::endl;
        std::cout << "Please enter a number: " << std::endl;
        std::cin >> number;
        std::cout << "Set bits are " << countSetBits(number) << std::endl;
        std::cout << std::endl;
    }
          break;
    case 8: {
        std::cout << "not implemented" << std::endl;
    }
          break;
    case 9: {
        std::cout << std::endl;
        std::cout << "Please enter first number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter second number: " << std::endl;
        std::cin >> bitNumber;
        std::cout << "Number after the swap:" << std::endl;
        swap(number, bitNumber);
        /* need to use CPP to use references */
        std::cout << "a = " << number << std::endl;
        std::cout << "b = " << bitNumber << std::endl;

        std::cout << std::endl;
    }
          break;
    case 10: {
        std::cout << std::endl;
        std::cout << "Please enter first number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter second number: " << std::endl;
        std::cin >> bitNumber;
        if (oppositeSigns(number, bitNumber)) {
            std::cout << "Signs are same" << std::endl;
        }
        else {
            std::cout << "Signs are opposite" << std::endl;
        }

        std::cout << std::endl;
    }
           break;
    case 11: {
        std::cout << std::endl;
        std::cout << "Please enter а number: " << std::endl;
        std::cin >> uNumber;
        std::cout << "Before the change: " << std::endl;
        printBinary(uNumber);
        std::cout << "After the change: " << std::endl;
        printBinary(reverseBits(uNumber));

        std::cout << std::endl;
    }
           break;
    case 12: {
        std::cout << std::endl;
        std::cout << "Please enter first number: ";
        std::cin >> number;
        std::cout << "Please enter second number: ";
        std::cin >> bitNumber;
        printBinary(add(number, bitNumber));
        std::cout << std::endl;
    }
           break;
    case 13: {
        std::cout << std::endl;
        std::cout << "Please enter first number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter second number: " << std::endl;
        std::cin >> bitNumber;

        int result = multiply(number, bitNumber);

        std::cout << "a x b = " << result << std::endl;
        printBinary(result);
        std::cout << std::endl;
    }
           break;
    case 14: {
        std::cout << std::endl;
        std::cout << "Please enter first number: " << std::endl;
        std::cin >> number;
        std::cout << "Please enter second number: " << std::endl;
        std::cin >> bitNumber;

        int result = divide(number, bitNumber);

        std::cout << "a / b = " << result << std::endl;
        printBinary(result);
        std::cout << std::endl;
    }
           break;
    case 15: {
        std::cout << std::endl;
        std::cout << "Please enter a number: ";
        std::cin >> number;

        bool result = isPowerOfFour(number);

        if (result) {
            std::cout << "Number is power of 4" << std::endl;
        }
        else {
            std::cout << "Number is NOT power of 4" << std::endl;
        }
        std::cout << std::endl;
    }
           break;
    case 16: {
		std::cout << "not implemented" << std::endl;
    }
           break;
    default: {}
    }
}

int main() {
    int choice = 0;
    do {
        printMenu();
        std::cin >> choice;
        executeChoice(choice);

    } while (choice >= 1 && choice <= 16);

    return 0;
}
