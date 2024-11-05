#include <iostream>
#include "Bookstore.hpp"

using namespace BookstoreNS;

int main() {
    Bookstore bookstore = { "Marcus Books", "3900 Martin Luther King Jr Way, Oakland" };

    addBook(bookstore, { "Battle Of The Soul", "Carl Alves", "1549927035", 12, 14.99 });
    addBook(bookstore, { "A Clockwork Orange", "Anthony Burgess", "0393341763", 8, 8.55 });
    addBook(bookstore, { "I Am America (And So Can You!)", "Stephen Colbert", "0446580503", 10, 8.91 });

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Find Book\n";
        std::cout << "3. Display Inventory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Book newBook;
            std::cout << "Enter title: ";
            std::cin.ignore();
            std::getline(std::cin, newBook.title);
            std::cout << "Enter author: ";
            std::getline(std::cin, newBook.author);
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, newBook.ISBN);
            std::cout << "Enter quantity: ";
            std::cin >> newBook.quantity;
            std::cout << "Enter price: ";
            std::cin >> newBook.price;

            addBook(bookstore, newBook);
            break;
        }
        case 2: {
            std::string isbn;
            std::cout << "Enter ISBN to find: ";
            std::cin >> isbn;
            findBook(bookstore, isbn);
            break;
        }
        case 3:
            displayInventory(bookstore);
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}