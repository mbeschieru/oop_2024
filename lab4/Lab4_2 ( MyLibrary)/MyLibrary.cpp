
#include "MyLibrary.h"

MyLibrary::~MyLibrary() {
    delete[] books;
}

MyLibrary::MyLibrary(std::ostream &output_stream) : output_stream(output_stream) {
    this->books_count = 0;
    this->books = nullptr;
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, int *books) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books = new int[this->books_count];
    for (int i = 0; i < this->books_count; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, int min, int max) : output_stream(
        output_stream) {
    this->books_count = books_count;
    this->books = new int[books_count];
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(min, max - 1);
    auto element = std::bind(distribution, generator);
    for (int i = 0; i < this->books_count; i++)
        this->books[i] = element();

}

MyLibrary::MyLibrary(std::ostream &output_stream, const char *books_values) : output_stream(output_stream) {
    this->books = new int[50];
    int i = 0;
    while (books_values[i] != '\0') {
        if (books_values[i] == ';')
            i++;
        if (books_values[i] == '\0')
            break;
        int num = 0;
        while (books_values[i] != '\0' && books_values[i] != ';')
            num = num * 10 + (books_values[i] - '0'), i++;
        this->books[this->books_count++] = num;
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, ...) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (int i = 0; i < this->books_count; i++)
        this->books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout) {
    int size = v.size();
    this->books_count = size;
    this->books = new int[size];
    int i = 0;
    for (auto el: v)
        this->books[i++] = el;
}

void MyLibrary::print_books() const {
    if (books_count == 0) {
        output_stream << -1 << '\n';
        return;
    }
    output_stream << books_count << '\n';
    for (int i = 0; i < books_count; i++)
        output_stream << books[i] << " ";
}

void MyLibrary::update_book_id_by_index(unsigned int book_index, int book_id) {
    if (book_index >= books_count)
        return;
    books[book_index] = book_id;
}

int MyLibrary::get_books_count() const {
    if (books_count == 0)
        return -1;
    return books_count;
}

int MyLibrary::get_book_id_by_index(int index) const {
    if (index >= books_count)
        return -1;
    return books[index];
}

MyLibrary::MyLibrary(MyLibrary &obj) : output_stream(obj.output_stream) {
    this->books_count = obj.books_count;
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
        this->books[i] = obj.books[i];
}



