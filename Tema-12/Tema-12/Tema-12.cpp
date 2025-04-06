/* Folosid liste inlantuite folosind structura de mai jos:

   Structura pentru a reprezenta un produs
   struct Product {
   string name;
   double price;
   int quantity;
   Product* next;
   Product(string n, double p, int q) : name(n), price(p), quantity(q), next(nullptr) {} 
   };

Implementati clasa Clasa ProductList care sa contina urmatoarele functii
Conține un pointer head care face referire la primul produs din listă.
Funcția addProduct adaugă un produs la sfârșitul listei.
Funcția displayProducts afișează lista de produse.
Funcția copyList creează o copie a listei de produse.
Funcția deleteProduct elimină un produs din listă după nume.
EXTRA:
Căutare produs: Adăugarea unei funcționalități de căutare a unui produs în listă.
Actualizare cantitate: Posibilitatea de a modifica cantitatea unui produs existent.
Sortare: Sortarea produselor în funcție de preț sau nume.
*/

#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
    Product* next;
    Product(string n, double p, int q) : name(n), price(p), quantity(q), next(nullptr) {}
};

class ProductList {
private:
    Product* head;
public:
    ProductList();
    void addProduct(string name, double price, int quantity);
    void displayProducts();
    ProductList copyList();
    void deleteProduct(string name);
    Product* searchProduct(string name);
    void updateQuantity(string name, int newQuantity);
    void sortByPrice();
    ~ProductList();
};

ProductList::ProductList() : head(nullptr) {}

void ProductList::addProduct(string name, double price, int quantity) {
    Product* newProduct = new Product(name, price, quantity);
    if (!head) {
        head = newProduct;
        return;
    }
    Product* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newProduct;
}

void ProductList::displayProducts() {
    Product* temp = head;
    while (temp) {
        cout << "Nume: " << temp->name << ", Pret: " << temp->price << ", Cantitate: " << temp->quantity << endl;
        temp = temp->next;
    }
}

ProductList ProductList::copyList() {
    ProductList newList;
    Product* temp = head;
    while (temp) {
        newList.addProduct(temp->name, temp->price, temp->quantity);
        temp = temp->next;
    }
    return newList;
}

void ProductList::deleteProduct(string name) {
    if (!head) return;
    if (head->name == name) {
        Product* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Product* temp = head;
    while (temp->next && temp->next->name != name) {
        temp = temp->next;
    }
    if (temp->next) {
        Product* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

Product* ProductList::searchProduct(string name) {
    Product* temp = head;
    while (temp) {
        if (temp->name == name) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void ProductList::updateQuantity(string name, int newQuantity) {
    Product* product = searchProduct(name);
    if (product) {
        product->quantity = newQuantity;
    }
}

void ProductList::sortByPrice() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Product* temp = head;
        while (temp->next) {
            if (temp->price > temp->next->price) {
                swap(temp->name, temp->next->name);
                swap(temp->price, temp->next->price);
                swap(temp->quantity, temp->next->quantity);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

ProductList::~ProductList() {
    while (head) {
        Product* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ProductList list;
    list.addProduct("Laptop", 3500.99, 5);
    list.addProduct("Mouse", 150.50, 10);
    list.addProduct("Monitor", 900.75, 7);

    cout << "Lista initiala:\n";
    list.displayProducts();

    list.sortByPrice();
    cout << "\nLista sortata dupa pret:\n";
    list.displayProducts();

    list.updateQuantity("Mouse", 20);
    cout << "\nLista dupa actualizarea cantitatii pentru Mouse:\n";
    list.displayProducts();

    list.deleteProduct("Laptop");
    cout << "\nLista dupa stergerea Laptopului:\n";
    list.displayProducts();

    return 0;
}