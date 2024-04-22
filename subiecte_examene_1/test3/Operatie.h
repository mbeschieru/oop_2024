//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST3_OPERATIE_H
#define TEST3_OPERATIE_H


class Operatie {
private:
    char *name;

public:
    static int getSize(const char *value);

    char *getName();

    void setName(const char *value);

    virtual double getResult(double x, double y) = 0;

};


#endif //TEST3_OPERATIE_H
