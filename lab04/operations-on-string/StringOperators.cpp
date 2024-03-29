//
// Created by Malwina Juchiewicz on 12/12/2023.
//

#include "StringOperators.h"

std::string wrapInQuotes(const std::string& word) {
    return "\"" + word + "\"";
}

std::string cutString(const std::string &a) {
    if (a.size() >= 2) {
        return a.substr(1, a.size() - 2);
    } else {
        return "";
    }
}

std::string operator+ (const std::string &a, const std::string &b) {
    std::string result = cutString(a) + cutString(b);
    return wrapInQuotes(result);
}

std::string operator-(const std::string &a, const std::string &b) {
    std::string result = cutString(a);
    std::string cutB = cutString(b);

    size_t pos = result.rfind(cutB);

    if (pos != std::string::npos) {
        result.erase(pos, cutB.length());
    }

    return wrapInQuotes(result);
}


std::string operator*(const std::string& a, const std::string& b)
{
    std::string result = cutString(a);
    std::string cutB = cutString(b);

    std::string res = "";
    char toBeReplaced = cutB[0];
    for (char c : result)
    {
        if (c == toBeReplaced) {
            res += cutB;
        }
        else {
            res += c;
        }
    }
    return wrapInQuotes(res);
}


std::string operator/(const std::string &str, const std::string &divisor) {
    std::string result = cutString(str);
    std::string cutDivisor = cutString(divisor);

    if (!cutDivisor.empty()) {
        size_t pos = result.find(cutDivisor);

        while (pos != std::string::npos) {
            result.erase(pos, cutDivisor.length());
            pos = result.find(cutDivisor, pos);
        }
    }

    return wrapInQuotes(result);
}