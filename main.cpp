// main.cpp
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "item.h"
using namespace std;
#define SIZE 5

void add_item(Item *item_list, double price, const char *sku, const char *category, const char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_all(Item *item_list, int size);
void print_item(Item *item_list, int index);
char* find_item(Item *item_list, char *search, int size);

int main (int argc, char *argv[]) {
    Item *items = new Item[SIZE]; // allocate memory for array of Items
    add_item(items, 3.39, "79862", "dairy", "Milk", 0); 
    add_item(items, 2.99, "43321", "beverages", "Mountain Dew: Major Melon", 1);
    add_item(items, 2.49, "52345", "bakery", "Double Chunk Chocolate Cookie", 2); 
    add_item(items, 3.59, "57298", "bakery", "Raisin Cinnamon Swirl Bread", 3); 
    add_item(items, 5.98, "12355", "condiments", "Frank's Red Hot", 4); 
    print_all(items, SIZE);
    double avg_price = average_price(items, SIZE);
    cout << "###############" << endl;
    cout << "average price = $" << avg_price << endl;
    
    
    char *input = argv[1]; //take the input and assign it to string input.
    find_item(items, input, SIZE);
}

char* find_item(Item *item_list, char *search, int size) {
    bool found = false;
    int founditem = -1;
    cout << "---------------" << endl;
    for (int i = 0; i < size; i++) {
    //cout << "sku current: " << item_list[i].sku << endl;
    //cout << "sku searching: " << search << endl;
        if (strcmp(item_list[i].sku, search) == 0) {
            founditem = i;
            cout << "found sku = " << item_list[founditem].sku << endl;
            cout << "---------------" << endl;
            print_item(item_list, i);
            cout << "---------------" << endl;
            return search;
        }
    }
    cout << "sku not found" << endl;
    cout << "---------------" << endl;
    return NULL;
}

void add_item(Item *item_list, double price, const char *sku, const char *category, const char *name, int index) {
    item_list[index].price = price;
    item_list[index].sku = new char[strlen(sku) + 1];
    strcpy(item_list[index].sku, sku);
    item_list[index].name = new char[strlen(name) + 1];
    strcpy(item_list[index].name, name);
    item_list[index].category = new char[strlen(category) + 1];
    strcpy(item_list[index].category, category);
}
void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        delete[] item_list[i].name;
        delete[] item_list[i].category;
        delete[] item_list[i].sku;
    }
    delete[] item_list;
}

double average_price(Item *item_list, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total = item_list[i].price + total;
    }
    return (total / size);
}

void print_all(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        print_item(item_list, i);
    }
}

void print_item(Item *item_list, int index) {
    cout << "###############" << endl;
        cout << "item name = " << item_list[index].name << endl;
        cout << "item sku = " << item_list[index].sku << endl;
        cout << "item category = " << item_list[index].category << endl;
        cout << "item price = $" << item_list[index].price << endl;
}