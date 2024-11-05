#ifndef BOOKSTORE_HEADER
#define BOOKSTORE_HEADER

#include <vector>
#include "Book.hpp"

namespace BookstoreNS {

    struct Bookstore {
        std::string storeName;
        std::string address;
        std::vector<Book> inventory;
    };

    void addBook(Bookstore& bookstore, const Book& book);
    void findBook(const Bookstore& bookstore, const std::string& ISBN);
    void displayInventory(const Bookstore& bookstore);

}

#endif BOOKSTORE_HEADER