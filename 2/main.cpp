#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <pthread.h>

using namespace std;

#define N 5
#define FILENAME "workers.txt"
#define FILL_DOTS(FILE, WORD)   for (int i = 10-WORD.length(); i > 0; i--) \
                                    FILE << '.';

pthread_mutex_t m;

class Worker
{
public:
    Worker()
    {
        name = "Serega";
        age = 40;
        salary = 500;
    }
    Worker(string name_, int age_, int salary_)
    {
        name = name_;
        age = age_;
        salary = salary_;
    }
    void dowork() 
    { 
        pthread_mutex_lock(&m);
        salary--;
        ofstream file(FILENAME, ios::app);

        file << name;
        FILL_DOTS(file, name);
        file << '|' << age;
        FILL_DOTS(file, to_string(age));
        file << '|' << salary;
        FILL_DOTS(file, to_string(salary));
        file << '|' << endl;

        file.close();
        if (salary == 100) throw runtime_error("DIBIL");
        pthread_mutex_unlock(&m);
    }
    static void* thread(void* arg)
    {
        Worker* worker = (Worker*)arg;
        worker->dowork();
        pthread_exit(arg);
    }
private:
    string name;
    int age;
    int salary;
};

int main()
{
    ofstream file(FILENAME);
    file.close();

    Worker w1;
    Worker w2("Vlad", 19, 450);
    Worker w3("Volodya", 25, 300);
    Worker w4("Dima", 32, 200);
    Worker w5("Pavel", 40, 700);

    vector<Worker> workers;

    workers.push_back(w1);
    workers.push_back(w2);
    workers.push_back(w3);
    workers.push_back(w4);
    workers.push_back(w5);

    pthread_t t[N];
    pthread_mutex_init(&m, NULL);

    try
    {
        while(1)
        {
            for (int i = 0; i < N; i++)
                pthread_create(&t[i], NULL, &Worker::thread, &workers[i]);
        }   
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}
