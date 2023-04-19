#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <chrono>

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

        Animal() {};

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

void vector_data()
{
    std::ofstream file;
    file.open("vector.txt");  
     
    if (file.is_open())
    {
        for (int i = 1000; i <= 1000000; i += 1000)
        {   
            file << i << ' ';
            
            auto start = std::chrono::steady_clock::now();
            std::vector<Cat> cv(i);
            for (int j = 0; j < i; j++)
            {
                Cat tmp_cat{};
                cv.push_back(tmp_cat);
            }
            auto fin = std::chrono::steady_clock::now();
            auto duration = fin - start;

            file << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;
        }
    }
    else
    {
        throw std::runtime_error("Not able to open a file!");
    }
    
    file.close();
}

void list_data()
{
    std::ofstream file;
    file.open("list.txt");
    
    if (file.is_open())
    {
        for (int i = 1000; i <= 1000000; i += 1000)
        {
            auto start = std::chrono::steady_clock::now();
            std::list<Cat> cl(i);
            for (int j = 0; j < i; j++)
            {
                Cat tmp_cat{};
                cl.push_back(tmp_cat);
            }
            auto fin = std::chrono::steady_clock::now();
            auto duration = fin - start;

            file << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;
        }
    }
    else
    {
        throw std::runtime_error("Not able to open a file!");
    }
    
    file.close();
}

void deque_data()
{
    std::ofstream file;
    file.open("deque.txt");

    if (file.is_open())
    {
        for (int i = 1000; i <= 1000000; i += 1000)
        {
            auto start = std::chrono::steady_clock::now();
            std::list<Cat> cd(i);
            for (int j = 0; j < i; j++)
            {
                Cat tmp_cat{};
                cd.push_back(tmp_cat);
            }
            auto fin = std::chrono::steady_clock::now();
            auto duration = fin - start;

            file << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;
        }
    }
    else
    {
        throw std::runtime_error("Not able to open a file!");
    }

    file.close();
}

int main()
{   
    vector_data();
    list_data();
    deque_data();

    return 0;
}