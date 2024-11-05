#ifndef BOOK_HEADER
#define BOOK_HEADER

#include <string>

namespace BookstoreNS {

    struct Book {
        std::string title;
        std::string author;
        std::string ISBN;
        int quantity;
        double price;
    };

    std::ostream& operator<<(std::ostream& os, const Book& book);
    bool operator==(const Book& lhs, const Book& rhs);

}

#endif  BOOK_HEADER