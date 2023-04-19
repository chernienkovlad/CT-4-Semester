#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Food
{
    public:
        std::string type;
        std::string name;
        int calories;
};

class Animal
{
    public:
        std::string type;
        std::string name;
        int age;
        int satiety;
        int max_size;

        template <typename T>
        void eat(std::vector<T>& animals_v, Food food)
        {
            if (food.type == "Meat")
            {
                throw std::runtime_error("Parrots don't eat meat!");
            }

            satiety += food.calories;
            if (satiety > max_size)
            {
                animals_v.erase(std::find(animals_v.begin(), animals_v.end(), *this));
            }
        }

        template <typename T>
        void run(std::vector<T>& animals_v, int minutes)
        {
            satiety -= minutes;
            if (satiety < 0)
            {
                animals_v.erase(std::find(animals_v.begin(), animals_v.end(), *this));
            }
        }

        template <typename T>
        void multiply(std::vector<T>& animals_v, T animal)
        {
            if (animal == *this)
            {
                throw std::runtime_error("Animals can't multiply with themselves!");
            }
            if (animal.type != this->type)
            {
                throw std::runtime_error("Parrots can't multiply with cats!");
            }

            T new_animal{};
            animals_v.push_back(new_animal);
        }

        bool operator==(const Animal& animal) const
        {
            return (type == animal.type &&
                    name == animal.name &&
                    age == animal.age &&
                    satiety == animal.satiety &&
                    max_size == animal.max_size);
        }
};

class Cat: public Animal
{
    public:
        std::string fav_meat;
        int fangs_len;

        Cat()
        {
            type = "Cat";
            name = "Poltorashka";
            age = 7;
            satiety = 30;
            max_size = 3000;
            fav_meat = "Beef";
            fangs_len = 2;
        }

        Cat(std::string name_, int age_, int satiety_, int max_size_, std::string fav_meat_, int fangs_len_)
        {
            type = "Cat";
            name = name_;
            age = age_;
            satiety = satiety_;
            max_size = max_size_;
            fav_meat = fav_meat_;
            fangs_len = fangs_len_;
        }

        void eat(std::vector<Cat>& cats_v, Food food)
        {
            if (food.type == "Fruit")
            {
                throw std::runtime_error("Cats don't eat fruits!");
            }

            if (food.name == fav_meat)
            {
                satiety += 2 * food.calories;
                if (satiety > max_size)
                {
                    cats_v.erase(std::find(cats_v.begin(), cats_v.end(), *this));
                }
                return;
            }

            satiety += food.calories;
            if (satiety > max_size)
            {
                cats_v.erase(std::find(cats_v.begin(), cats_v.end(), *this));
            }
        }
};

class Parrot: public Animal
{
    public:
        Parrot()
        {
            type = "Parrot";
            name = "Kesha";
            age = 1;
            satiety = 15;
            max_size = 50;
        }

        Parrot(std::string name_, int age_, int satiety_, int max_size_)
        {
            type = "Parrot";
            name = name_;
            age = age_;
            satiety = satiety_;
            max_size = max_size_;
        }
};

void cats_print(std::vector<Cat>& cats_v)
{
    for (auto cat: cats_v)
    {
        std::cout << cat.name << "; ";
        std::cout << cat.age << "; ";
        std::cout << cat.satiety << "; ";
        std::cout << cat.max_size << "; ";
        std::cout << cat.fav_meat << "; ";
        std::cout << cat.fangs_len << std::endl;
    }
    std::cout << std::endl;
}

void parrots_print(std::vector<Parrot>& parrots_v)
{
    for (auto parrot: parrots_v)
    {
        std::cout << parrot.name << "; ";
        std::cout << parrot.age << "; ";
        std::cout << parrot.satiety << "; ";
        std::cout << parrot.max_size << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    Cat cat1{"Masya", 5, 50, 100, "Chicken", 4};
    Cat cat2{"Rita", 9, 75, 150, "Beef", 6};
    Cat cat3{"Rita", 9, 75, 150, "Chicken", 3};

    Parrot parrot1{"Grisha", 3, 35, 75};
    Parrot parrot2{"Matvey", 5, 15, 47};

    std::vector<Cat> cats_v = {cat1, cat2, cat3};
    std::vector<Parrot> parrots_v = {parrot1, parrot2};

    Food chicken{"Meat", "Chicken", 50};
    cats_print(cats_v);
    cats_v[2].run(cats_v, 76);
    cats_print(cats_v);

    return 0;
}