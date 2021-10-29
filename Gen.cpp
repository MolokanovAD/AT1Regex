#include "Gen.h"

std::string generateCorrectS(int len) {
    int cap = len / 10;
    std::string str = "";
    str.reserve(len * 1.5);
    int wordLength = rand() % cap;
    for (int i = 0; i < cap; i++) {
        str += rand() % 26 + (rand() & 1 ? 'a' : 'A');
    }
    int spaces = 1 + rand() % 5;
    for (int i = 0; i < spaces; i++) {
        str += ' ';
    }
    str += ':';
    for (int i = 0; i < spaces % 2; i++) {
        str += ' ';
    }
    while (str.length() < len) {
        wordLength = rand() % cap;
        for (int i = 0; i < cap; i++) {
            str += rand() % 26 + (rand() & 1 ? 'a' : 'A');
        }
        spaces = 1 + rand() % 10;
        for (int i = 0; i < spaces; i++) {
            str += ' ';
        }
        for (int i = 0; i < (spaces % 2 + 1); i++) {
            str += ' ';
        }
    }
    return str;
}

std::string generateWrongS(int len) {
    int cap = len / 10;
    std::string str = "";
    str.reserve(len * 1.5);
    int wordLength = rand() % cap;
    for (int i = 0; i < cap; i++) {
        str += rand() % 30 + (rand() & 1 ? 'a' : 'A');
    }
    int spaces = 1 + rand() % 5;
    for (int i = 0; i < spaces; i++) {
        str += ' ';
    }
    str += rand() % 1 ? ':' : ' ';
    for (int i = 0; i < spaces % 2; i++) {
        str += ' ';
    }
    while (str.length() < len) {
        wordLength = rand() % cap;
        for (int i = 0; i < cap; i++) {
            str += rand() % 30 + (rand() & 1 ? 'a' : 'A');
        }
        spaces = 1 + rand() % 10;
        for (int i = 0; i < spaces; i++) {
            str += ' ';
        }
        for (int i = 0; i < (spaces % 2 + 1); i++) {
            str += ' ';
        }
    }
    return str;
}