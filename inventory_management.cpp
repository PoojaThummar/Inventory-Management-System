#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Product class definition
class Product {
public:
    string name;
    int id;
    int quantity;
    double price;

    Product(string name, int id, int quantity, double price) 
        : name(name), id(id), quantity(quantity), price(price) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name 
             << ", Quantity: " << quantity 
             << ", Price: " << price << endl;
    }
};

// Inventory class definition
class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayProducts() const {
        cout << "Product Inventory:" << endl;
        for (const auto& product : products) {
            product.display();
        }
    }

    void generateReport() const {
        ofstream reportFile("inventory_report.txt");
        reportFile << "Inventory Report\n";
        reportFile << "================\n";
        for (const auto& product : products) {
            reportFile << "ID: " << product.id << ", Name: " << product.name 
                       << ", Quantity: " << product.quantity 
                       << ", Price: " << product.price << endl;
        }
        reportFile.close();
        cout << "Report generated: inventory_report.txt" << endl;
    }

    void manageStock(int id, int quantity) {
        for (auto& product : products) {
            if (product.id == id) {
                product.quantity += quantity;
                cout << "Stock updated for product ID: " << id << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void billing(int id, int quantity) const {
        for (const auto& product : products) {
            if (product.id == id) {
                if (product.quantity >= quantity) {
                    double total = quantity * product.price;
                    cout << "Total bill for product ID: " << id << " is $" << total << endl;
                } else {
                    cout << "Insufficient stock for product ID: " << id << endl;
                }
                return;
            }
        }
        cout << "Product not found!" << endl;
    }
};

// Main function
int main() {
    Inventory inventory;

    // Adding sample products
    inventory.addProduct(Product("Laptop", 101, 10, 999.99));
    inventory.addProduct(Product("Mouse", 102, 50, 19.99));
    inventory.addProduct(Product("Keyboard", 103, 30, 49.99));

    // Display products
    inventory.displayProducts();

    // Manage stock
    inventory.manageStock(102, 10);

    // Billing
    inventory.billing(101, 1);

    // Generate report
    inventory.generateReport();

    return 0;
}
