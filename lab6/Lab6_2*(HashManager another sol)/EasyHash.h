//
// Created by Marius Beschieru on 02.04.2024.
//

#ifndef LAB6_2_HASHMANAGER__EASYHASH_H
#define LAB6_2_HASHMANAGER__EASYHASH_H

#include "Hash.h"
#include "utils.h"

class EasyHash : public Hash {
public:
    int calculate(const char *string) override;
};


#endif //LAB6_2_HASHMANAGER__EASYHASH_H
