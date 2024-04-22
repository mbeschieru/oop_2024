//
// Created by Marius Beschieru on 21.03.2024.
//

#ifndef P1_CATALOG_H
#define P1_CATALOG_H

struct Student {
    char *nume;
    int nota;

    Student(const char *nume, int nota);

    char *getNume() const;

    double getNota() const;

    static int getStringSize(const char *nume);

    static bool equalNames(const char *nume1, const char *nume2);

    void Print() const;

    bool operator!=(Student &other) const;
};

class Catalog {
private:
    Student **catalog;
    char *materie;
    static constexpr int MAX_SIZE = 16;
    int count = 0;
public:

    Catalog(const char *materie);

    ~Catalog();

    Catalog &operator+=(Student student);

    bool operator==(const char *nume);

    Catalog &operator-=(const char *nume);

    explicit operator int();

    explicit operator const char *();

    explicit operator float();

    class Itterator {
    private:
        Student **ptr;
    public:
        explicit Itterator(Student **ptr);

        Student &operator*() const;

        Itterator& operator++();

        bool operator !=(const Itterator& other);
    };
    Itterator begin();

    Itterator end();
};

#endif //P1_CATALOG_H
