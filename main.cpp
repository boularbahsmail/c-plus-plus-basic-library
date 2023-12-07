#include <iostream>
#include <string>

using namespace std;

// Books
string Books[] = {
        "Zickola's Land",
        "AMARITA - Zickola's Land Part 2",
        "The Valley Of The Forgotten wolves - Zickola's Land Part 3"
};
int BooksListSize = sizeof(Books)/sizeof(Books[0]);

// Prices
int Prices[] = {30, 25, 45};

// Cart
string Cart[] = {};
int CartItemsLength = sizeof(Cart)/sizeof(Cart[0]);

// Balance
int Balance = 200;

// Library Class
class Library {
public:
    // Show Books Function
    static void showBooks() {
        cout << "\n-- List Of The Available Books : --" << endl;
        for (int index = 0; index < BooksListSize; index++) {
            cout << "(" << index+1 << ") " << Prices[index] << "Dh - " << Books[index] << endl;
        }
    }

    // Show User Balance Function
    static void showBalance() {
        cout << "\n-- Your Balance : --" << endl;
        cout << Balance << "Dh" << endl;
    }

    // Show User Cart Function
    static void showCart() {
        bool isEmpty = CartItemsLength == 0; // CartIListSize == 0 => return true else return false
        cout << "\n-- Your Cart : --" << endl;

        if (!isEmpty) {
            for (int index = 0; index < CartItemsLength; index++) {
                cout << "- " << Cart[index] << endl;
            }
        }
        else cout << "[]" << endl;
    }

    // Update The User Balance Function
    static void updateUserBalance(int bookPrice) {
        Balance = Balance - bookPrice;
        showBalance();
    };

    // Update The User Cart Function
    static void updateUserCart(string book) {
        Cart->append(book);
        showCart();
    }

    // Buy Book Function
    static void buyBook(int bookPosition) {
        cout << "\n-----" << endl;
        for (int index = 0; index < BooksListSize; index++) {
            if (bookPosition - 1 == index) {

                const string selectedBookTitle = Books[bookPosition - 1];
                const int selectedProductPrice = Prices[bookPosition - 1];

                cout << "Book: " << selectedBookTitle << endl;
                cout << "Price: " << selectedProductPrice << "Dh" << endl;
                updateUserBalance(selectedProductPrice);
                updateUserCart(selectedBookTitle);
            }
        }
        cout << "-----" << endl;
    }

    // Ask To Buy Function
    static int askToBuy() {
        int bookPosition;
        cout << "\nType the position of a book :";
        cin >> bookPosition;

        // Aak For Confirmation Before Buying
        string confirmation = confirmBuy();
        if (confirmation == "y" || confirmation == "Y") {
            buyBook(bookPosition);
        }
        else return 0;
    }

    // Buy Action Confirmation Function
    static string confirmBuy() {
        string userConfirmation;
        cout << "Continue buying? ([y]: Yes | [n]: No) :";
        cin >> userConfirmation;
        return userConfirmation;
    }
};

int main() {
    // Call Library Functions
    Library::showBooks();
    Library::showBalance();
    Library::showCart();
    Library::askToBuy();

    return 0;
}
