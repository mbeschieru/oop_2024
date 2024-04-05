//
// Created by Marius Beschieru on 14.03.2024.
//

#include "Phrase.h"

Phrase::Phrase(const char *value) {
    count = 0;
    int size = getSize(value);
    words = new char *[50];
    int i = 0;
    while (i < size) {
        while (value[i] == ' ')
            i++;
        if (value[i] == '\0')
            break;
        int k = 0;
        words[count] = new char[64];
        while (value[i] != '\0' && value[i] != ' ')
            words[count][k++] = value[i++];
        words[count][k] = '\0';
        count++;
    }
}


int Phrase::getSize(const char *value) {
    int i = 0;
    while (value[i] != '\0')
        i++;
    return i ;
}

Phrase::~Phrase() {
    for (int i = 0; i < count; i++)
        delete[] words[i];
    delete[] words;
}

Phrase::operator int() const {
    return count;
}

char *Phrase::operator[](int index) {
    if (index < 0 && index > count)
        return nullptr;
    return words[index];
}

int Phrase::CountLetter(int index, char ch) {
    int s = 0;
    int size = getSize(words[index]);
    for (int i = 0; i < size; i++)
        if (words[index][i] == ch)
            s++;
    return s;
}

int Phrase::CountLetter(char ch) {
    int s = 0;
    for (int i = 0; i < count; i++)
        s += CountLetter(i, ch);
    return s;
}

char *Phrase::GetLongestWord() {
    int size = -1;
    char *word = nullptr;
    for (int i = 0; i < count; i++) {
        int current = getSize(words[i]);
        if (current > size) {
            size = current;
            word = words[i];
        }
    }
    return word;
}

bool Phrase::isVowel(char ch) {
    if (ch <= 90 && ch >= 65)
        ch += 32;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int Phrase::CountVowels(int index) {
    int s = 0;
    int size = getSize(words[index]);
    for (int i = 0; i < size; i++)
        if (isVowel(words[index][i]))
            s++;
    return s;
}

int Phrase::CountVowels() {
    int s = 0;
    for (int i = 0; i < count; i++)
        s += CountVowels(i);
    return s;
}
