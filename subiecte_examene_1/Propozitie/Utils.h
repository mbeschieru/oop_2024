//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef PROPOZITIE_UTILS_H
#define PROPOZITIE_UTILS_H


class Utils {
public:
    static int GetSize(const char *string);

    static void CopyString(char *destination, const char *source);

    static bool isVowel(char ch);

    static int countVowels(const char *string);

    static int isNumber(const char *string);

    static bool equalStrings(const char *string1, const char *string2);

    static int countEmptySpace(const char*string);

    static bool isSeparator(const char ch);
};


#endif //PROPOZITIE_UTILS_H
