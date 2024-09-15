#include <string>  // for std::string

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.size() - 1;

    while (left < right) {
        // Move left index to the next alphanumeric character
        while (left < right && !std::isalnum(str[left])) {
            ++left;
        }
        // Move right index to the previous alphanumeric character
        while (left < right && !std::isalnum(str[right])) {
            --right;
        }

        // Compare characters in a case-insensitive manner
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "WORD: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "\"" << input << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << input << "\" is not a palindrome." << std::endl;
    }

    return 0;
}
