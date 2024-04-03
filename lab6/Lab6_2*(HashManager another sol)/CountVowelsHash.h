//
// Created by Marius Beschieru on 02.04.2024.
//

#ifndef LAB6_2_HASHMANAGER__COUNTVOWELSHASH_H
#define LAB6_2_HASHMANAGER__COUNTVOWELSHASH_H

#include "Hash.h"
#include "utils.h"

class CountVowelsHash : public Hash{
public:
    int calculate(const char* string) override;
};


#endif //LAB6_2_HASHMANAGER__COUNTVOWELSHASH_H
