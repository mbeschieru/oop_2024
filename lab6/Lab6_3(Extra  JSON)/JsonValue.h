//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__JSONVALUE_H
#define LAB6_3_EXTRA__JSON__JSONVALUE_H

#include <ostream>

class JsonValue {
public:
    virtual ~JsonValue() = default;

    virtual void print(std::ostream &out) const = 0;

};


#endif //LAB6_3_EXTRA__JSON__JSONVALUE_H
