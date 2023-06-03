#include <functional>
#include<iostream> 
#include<string> 
#include <list>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class car {
    string name;
    int year;
    double volume;
    double price;
public:
    car() {
        name = ' ';
        year = 0;
        volume = 0;
        price = 0;
    }
    int get_year() { return year; }
    double get_price() { return price; }
    double get_volume() { return volume; }
    string get_name() { return name; }
    void set() {
        cout << "enter name: ";
        cin >> name;
        cout << "enter year: ";
        cin >> year;
        cout << "enter volume: ";
        cin >> volume;
        cout << "enter price: ";
        cin >> price;
    }
    void print()const {
        cout << "name: " << name << endl;
        cout << "year: " << year << endl;
        cout << "volume: " << volume << endl;
        cout << "price: " << price << endl;

    }
    friend bool operator > (car a, car b);
    friend bool operator < (car a, car b);
};

bool operator > (car a, car b) {
    return a.get_price() > b.get_price();
}
bool operator < (car a, car b) {
    return a.get_price() < b.get_price();
}

class dealership {
    list<car> cars;
public:
    void add() {
        car tmp;
        tmp.set();
        cars.push_back(tmp);
    }
    void delete_car(string name) {
        cars.remove_if([name](car c) {
            return c.get_name() == name;
            });
    }
    void print()const {
        for (auto it : cars)
        {
            it.print();
            cout << endl;
        }
    }
    void sort() {

        cars.sort();
    }
    void find_name(string name) {
        for (auto it : cars)
            if (it.get_name() == name)
            {
                cout << endl;
                it.print();
                cout << endl;

            }
    }
    void find_volume(double volume) {
        for (auto it : cars)
            if (it.get_volume() == volume) it.print();
    }
};

int main()
{
    dealership shop;
    for (int i = 0; i < 5; i++)
    {
        shop.add();
    }
    shop.print();
    shop.delete_car("mazda");
    shop.print();
    shop.sort();
    shop.print();
    shop.find_name("audi");
}