//
//  main.cpp
//  KnapsackProblem
//
//  Created by Woo Sung Jahng on 2024/04/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class for single element in set V
class Object {
private:
    int num; // Object No.
    int size; // Size of object
    int price; // Price of object
public:
    Object(int num, int size, int price) {
        this->num = num;
        this->size = size;
        this->price = price;
    }
    // Read object no.
    int objnum() {
        return num;
    }
    // Read the size of object
    int objsize() {
        return size;
    }
    // Read the price of object
    int objprice() {
        return price;
    }
};

// Function for comparing price per size of two objects
bool PricePerSize(Object& a, Object& b) {
    return a.objprice()/a.objsize() > b.objprice()/b.objsize();
}

int main(int argc, const char * argv[]) {
    int n, b, i, j;
    
    // Input n(size of set V)
    n = 4;
    
    // Input b(size of knapsack)
    b = 13;
    
    vector<int> sizes(n);
    vector<int> prices(n);
    
    // Input size and price of objects
    sizes = {2, 3, 5, 7};
    prices = {500, 1000, 800, 900};
    
    vector<Object> obj;
    for (i=0; i<n; i++) {
        obj.emplace_back(i, sizes[i], prices[i]);
    }
    
    // Sort objects by price per size by higher to lower
    sort(obj.begin(), obj.end(), PricePerSize);
    
    
//    // Check sorted vector obj
//    cout << "Order of sorted obj : ";
//    for (auto& object : obj) cout << object.objnum() << " ";
//    cout << endl;
    
    int currentSize = 0;
    int totalPrice = 0;
    int maxPrice = 0;
    
    for (j=0; j<n; j++) {
        for (i=j; i<n; i++) {
            if (currentSize + obj[i].objsize() <= b) {
                currentSize += obj[i].objsize();
                totalPrice += obj[i].objprice();
//                // Track calculation
//                cout << '+' << obj[i].objprice() << endl;
            }
        }
        if (totalPrice >= maxPrice) maxPrice = totalPrice;
    }

    // Print the maximum price value
    cout << maxPrice << endl;
}
