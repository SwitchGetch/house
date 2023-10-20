#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Apartment
{
private:

    size_t apartment_area = 20 + rand() % 81;
    size_t hot_water_cost = rand() % 1000;
    size_t cold_water_cost = rand() % 1000;
    size_t electricity_cost = rand() % 1000;
    size_t gas_cost = rand() % 1000;
    size_t another_cost = rand() % 1000;
    size_t sum_cost = hot_water_cost + cold_water_cost + electricity_cost + gas_cost + another_cost;

public:

    size_t get_apartment_area()
    {
        return this->apartment_area;
    }

    size_t get_hot_water_cost()
    {
        return this->hot_water_cost;
    }

    size_t get_cold_water_cost()
    {
        return this->cold_water_cost;
    }

    size_t get_electricity_cost()
    {
        return this->electricity_cost;
    }

    size_t get_gas_cost()
    {
        return this->gas_cost;
    }

    size_t get_another_cost()
    {
        return this->another_cost;
    }

    size_t get_sum_cost()
    {
        return this->sum_cost;
    }

};

class Floor
{
private:

    Apartment apartment;
    size_t apartment_count;
    size_t floor_area;
    size_t floor_communal_bill;

public:

    Floor() = default;

    Floor(Apartment apartment, size_t apartment_count)
    {
        this->apartment_count = apartment_count;
        this->floor_area = apartment_count * apartment.get_apartment_area();
        this->apartment = apartment;
        this->floor_communal_bill = apartment_count * apartment.get_sum_cost();
    }

    size_t get_apartment_count()
    {
        return this->apartment_count;
    }

    size_t get_floor_area()
    {
        return this->floor_area;
    }

    size_t get_floor_communal_bill()
    {
        return this->floor_communal_bill;
    }

};

class House
{
private:

    Floor floor;
    size_t floor_count;
    size_t house_area;
    size_t house_height;
    size_t house_communal_bill;
    
public:

    House(Floor floor, size_t floor_count)
    {
        this->floor_count = floor_count;
        this->house_area = floor_count * floor.get_floor_area();
        this->house_height = floor_count * 3;
        this->floor = floor;
        this->house_communal_bill = floor_count * floor.get_floor_communal_bill();
    }

    size_t get_floor_count()
    {
        return this->floor_count;
    }

    size_t get_house_area()
    {
        return this->house_area;
    }

    size_t get_house_height()
    {
        return this->house_height;
    }

    size_t get_house_communal_bill()
    {
        return this->house_communal_bill;
    }

    void output()
    {
        system("cls");

        vector<string> apartment =
        {
             "-------------------",
            "|                   |",
            "|     ---------     |",
            "|     |   |   |     |",
            "|     |-------|     |",
            "|     |   |   |     |",
            "|     ---------     |",
            "|                   |",
             "-------------------"
        };

        for (size_t i = 0; i < this->floor_count; i++)
        {
            for (size_t j = 0; j < apartment.size(); j++)
            {
                for (size_t k = 0; k < this->floor.get_apartment_count(); k++)
                {
                    if (j == 0) cout << char(218) << apartment[j] << char(191);
                    else if (j == apartment.size() - 1) cout << char(192) << apartment[j] << char(217);
                    else cout << apartment[j];
                }

                cout << endl;
            }
        }
    }

};

// char(191) = вехний правый
// char(192) = нижний левый
// char(217) = нижний правый
// char(218) = верхний левый

int main()
{
    srand(time(NULL));

    size_t apartment_count, floor_count;

    cout << "apartment count (in floor): ";
    cin >> apartment_count;

    cout << "floor count (in house): ";
    cin >> floor_count;

    Apartment apartment;
    Floor floor(apartment, apartment_count);
    House house(floor, floor_count);

    house.output();

    cout << "\n" << endl;

    cout << "apartment area: " << apartment.get_apartment_area() << " m^2" << endl;
    cout << "floor area: " << floor.get_floor_area() << " m^2" << endl;
    cout << "house area: " << house.get_house_area() << " m^2" << endl;
    cout << "house height: " << house.get_house_height() << " m" << endl;
    cout << "house communal bill: " << house.get_house_communal_bill() << " rub" << endl;
    cout << "floor communal bill: " << floor.get_floor_communal_bill() << " rub" << endl;
    cout << "apartment communal bill: " << apartment.get_sum_cost() << " rub" << endl;
    cout << "- hot water: " << apartment.get_hot_water_cost() << " rub" << endl;
    cout << "- cold water: " << apartment.get_cold_water_cost() << " rub" << endl;
    cout << "- electricity: " << apartment.get_electricity_cost() << " rub" << endl;
    cout << "- gas: " << apartment.get_gas_cost() << " rub" << endl;
    cout << "- another: " << apartment.get_another_cost() << " rub" << endl;
}
