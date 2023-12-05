#include <iostream>
#include <string>

using namespace std;

// Library Class
class Library {
public:
    // Show Books Function
    static void showBooks(string *Products, int ProductsListSize, int *Prices) {
        cout << "\n-- List Of The Available Books : --" << endl;
        for (int index = 0; index < ProductsListSize; index++) {
            cout << "(" << index+1 << ") " << Prices[index] << "Dh - " << Products[index] << endl;
        }
    }

    // Show User Balance Function
    static void showBalance(int UserBalance) {
        cout << "\n-- Your Balance : --" << endl;
        cout << UserBalance << "Dh" << endl;
    }

    // Show User Cart Function
    static void showCart(string *userCart, int CartIListSize) {
        bool isEmpty = CartIListSize == 0; // CartIListSize == 0 => return true else return false
        cout << "\n-- Your Cart : --" << endl;

        if (!isEmpty) {
            for (int index = 0; index < CartIListSize; index++) {
                cout << "- " << userCart[index] << endl;
            }
        }
        else cout << "[]" << endl;
    }

    // Update The User Balance Function
    static void updateUserBalance(int userBalance, int productPrice) {
        int updatedBalance = userBalance - productPrice;
        showBalance(updatedBalance);
    };

    // Update The User Cart Function
    static void updateUserCart(string *userCart, const string &product, int CartIListSize) {
        userCart->append(product);
        showCart(userCart, CartIListSize);
    }
    // Update User Cart Function Isn't Working The Way It Should :)

    // Buy Book Function
    static void buyBook(string *Products, int productPosition, int ProductsListSize, const int *Prices, int userBalance, string  *userCart, int CartIListSize) {
        cout << "\n-----" << endl;
        for (int index = 0; index < ProductsListSize; index++) {
            if (productPosition - 1 == index) {

                const string selectedProductTitle = Products[productPosition - 1];
                const int selectedProductPrice = Prices[productPosition - 1];

                cout << "Book: " << selectedProductTitle << endl;
                cout << "Price: " << selectedProductPrice << "Dh" << endl;
                updateUserBalance(userBalance,  selectedProductPrice);
                updateUserCart(userCart, selectedProductTitle, CartIListSize);
            }
        }
        cout << "-----" << endl;
    }

    // Ask To Buy Function
    static int askToBuy(string *Products, int ProductsListSize, int *Prices, int userBalance, string *userCart, int CartIListSize) {
        int bookPosition;
        cout << "\nType the position of a book :";
        cin >> bookPosition;

        // Aak For Confirmation Before Buying
        string confirmation = confirmBuy();
        if (confirmation == "y" || confirmation == "Y") {
            buyBook(Products, bookPosition, ProductsListSize, Prices, userBalance, userCart, CartIListSize);
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
int Balance = 1000;

int main() {
    // Call Library Functions
    Library::showBooks(Books, BooksListSize, Prices);
    Library::showBalance(Balance);
    Library::showCart(Cart, CartItemsLength);
    Library::askToBuy(Books, BooksListSize, Prices, Balance, Cart, CartItemsLength);

    return 0;
}
