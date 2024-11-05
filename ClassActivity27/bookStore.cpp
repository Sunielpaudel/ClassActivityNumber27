#include <iostream>
#include <vector>

namespace BookstoreNS {


    struct Book {
        std::string title;
        std::string author;
        std::string ISBN;
        int quantity;
        double price;
    };

    struct Bookstore {
        std::string storeName;
        std::string address;
        std::vector<Book> inventory;
    };

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Title: " << book.title
            << "\nAuthor: " << book.author
            << "\nISBN: " << book.ISBN
            << "\nQuantity: " << book.quantity
            << "\nPrice: $" << book.price
            << "\n";
        return os;
    }

    bool operator==(const Book& lhs, const Book& rhs) {
        return lhs.ISBN == rhs.ISBN;
    }

    void addBook(Bookstore& bookstore, const Book& book) {
        for (Book& b : bookstore.inventory) {
            if (b.ISBN == book.ISBN) {
                b.quantity += book.quantity;
                std::cout << "Updated quantity of existing book: " << book.title << std::endl;
                return;
            }
        }
        bookstore.inventory.push_back(book);
        std::cout << "Added new book: " << book.title << std::endl;
    }

    void findBook(const Bookstore& bookstore, const std::string& ISBN) {
        for (const auto& b : bookstore.inventory) {
            if (b.ISBN == ISBN) {
                std::cout << "Book found:\n" << b << std::endl;
                return;
            }
        }
        std::cout << "Book not found with ISBN: " << ISBN << std::endl;
    }

    void displayInventory(const Bookstore& bookstore) {
        std::cout << "\nInventory of " << bookstore.storeName << " at " << bookstore.address << ":\n";
        for (const auto& book : bookstore.inventory) {
            std::cout << book << std::endl;
        }
    }

}