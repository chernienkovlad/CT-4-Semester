#include <iostream>
#include <string>
#include <vector>

class Food
{
public:
    int calories;
    std::string name;
    std::string type;
};

// class Meat: public Food
// {

// };

// class Fruit: public Food
// {

// };

class Animal
{
public:
    std::string name;
    int age;
    int satiety;  // сытность
    int max_food;
    std::string type;

    Animal() {}
    
    Animal(std::string name_, int age_, int satiety_, int max_food_, std::string type_)
    {
        name = name_;
        age = age_;
        satiety = satiety_;
        max_food = max_food_;
        type = type_;
    }

    void eat(std::vector<Parrot>& parrots_v, int i, Food food)
    {
        if (food.type == "Meat")
        {
            throw std::runtime_error("Parrots don't eat meat.");
        }

        satiety += food.calories;
        if (satiety > max_food)
        {
            parrots_v.erase(parrots_v.begin() + i);
        }
    }

    template <typename T>
    void run(std::vector<T>& animals_v, int i, int minutes)
    {
        satiety -= minutes;
        if (satiety < 0)
        {
            animals_v.erase(animals_v.begin() + i);
        }
    }

    template <typename T1, typename T2>
    void multiply(std::vector<T1>& animals_v, T2 animal)
    {
        if (*this == animal)
        {
            throw std::runtime_error("You can't multiply same objects");
        }
    }
};

class Cat: public Animal
{
public:
    int canines_length;
    std::string fav_meat;

    Cat(std::string name_, int age_, int satiety_, int max_food_, int canines_length_, std::string fav_meat_)
    {
        name = name_;
        age = age_;
        satiety = satiety_;
        max_food = max_food_;
        type = "Cat";
        canines_length = canines_length_;
        fav_meat = fav_meat_;
    }

    void eat(std::vector<Cat>& cats_v, int i, Food food)
    {
        if (food.type == "Fruit")
        {
            throw std::runtime_error("Cats don't eat fruits.");
        }

        if (food.name == fav_meat)
        {
            satiety += 2 * food.calories;
            if (satiety > max_food)
            {
                cats_v.erase(cats_v.begin() + i);
            }

            return;
        }
        satiety += food.calories;
        if (satiety > max_food)
        {
            cats_v.erase(cats_v.begin() + i);
        }
    }
};

class Parrot: public Animal {};

int main()
{
    std::vector<Cat> cats_v;
    std::vector<Parrot> parrots_v;

    return 0;
}
