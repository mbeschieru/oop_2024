//
// Created by Marius Beschieru on 14.03.2024.
//

#ifndef TEST1_PHRASE_H
#define TEST1_PHRASE_H


class Phrase {
private:
    int count;
    char **words;

    static int getSize(const char *value);

    static bool isVowel(char ch);

    int CountVowels(int index);

public:
    Phrase(const char *value);

    ~Phrase();

    operator int() const;

    char *operator[](int index);

    int CountLetter(int index, char ch);

    int CountLetter(char ch);

    char *GetLongestWord();

    int CountVowels();

};


#endif //TEST1_PHRASE_H
