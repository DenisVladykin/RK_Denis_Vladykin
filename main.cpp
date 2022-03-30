#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QList>
#include <QString>

using namespace std;
//Построение ёлочки
void elka(int n, int t) // Вызов функции - elka(размер самого большого яруса, 0);
{
    if(n<0)
        return;

    for(int i = 0; i < t; i++)
    {
        cout << " ";
    }
    if(n%2 == 0)
    {
        for(int i = 0; i <= n; i++)
        {
            cout << "*";
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << "*";
        }
    }
    for(int i = 0; i < t; i++)
    {
        cout << " ";
    }
    cout << endl;
    elka(n-2, t+1);
}

// Перевод в двоичную систему + запись в файл ConvertResult.txt
void per(int n)
{
    if(n>=2)
    {
        per(n/2);
    }
    FILE* f1;
    f1 = fopen("ConvertResult.txt", "a");
    fprintf(f1, "%d", n%2);
    fclose(f1);
    return;
}

//Определение частоты вхождения символов из файла d. Запись в файл r
void sksim (char*d, char* r)
{
    FILE* f1;
    FILE* f2;
    f1 = fopen(d, "r");
    f2 = fopen(r, "a");
    int size;
    fseek(f1, 0, SEEK_END);
    size = ftell(f1);
    fseek(f1,0,SEEK_SET);
    bool flag = false;
    QVector<char> symb;
    for(int i = 0; i < size; i++)
    {
        char tek_sim;
        fread(&tek_sim, sizeof(char), 1, f1);
        flag = false;
        for(int t = 0; t < symb.size(); t++)
        {
            if(tek_sim==symb.at(t))
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            symb.push_back(tek_sim);
            int kolvo = 0;
            for(int z = 0; z < size; z++)
            {
                char tek_sim2;
                fread(&tek_sim2, sizeof(char), 1, f1);
                if(tek_sim==tek_sim2)
                {
                    kolvo++;
                }
            }
            fprintf(f2, "%c\t%d", tek_sim, kolvo);
            fprintf(f2, "\n");
        }
    }
}

//Среднее по строкам.
int sredmas(int arr[], int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum = sum + arr[i];
    }
    return sum/len;
}

int* sreddvummas(int* arr[], int i, int j)
{
    int rez[i];
    for(int m = 0; m < i; m++)
    {
        rez[i] = sredmas(arr[m], j);
    }
    return rez;
}

//Класс студент с данными и функциями
class Student
{
private:
    char* name;
    QVector<char*> pr;
    QVector<int> score;


public:
    int addscore(char* pred, int _score)
    {
        int temp = -1;
        for(int i = 0; i < pr.size(); i++)
        {
            if(pr.at(i) == pred)
            {
                temp = i;
                break;
            }
        }
        if(temp == -1)
        {
            return -1;
        }
        else
        {
            score[temp] = _score;
            return 0;
        }
    }
    int addpr(char* _pr)
    {
        pr.push_back(_pr);
        score.push_back(0);
    }
    int sred()
    {
        int srb = 0;
        for(int i = 0; i < score.size(); i++)
        {
            srb = srb + score.at(i);
        }
        return srb/score.size();
    }
    int vivod()
    {
        cout << "Name: " << name << sred() << endl;
    }

    Student(char* _name)
    {
        name = _name;
    }
};


//void zapis(LinkedList info)
//{
//    FILE* f1;
//    f1 = fopen("DataFromTail.txt", "w");
//    if (info.head != nullptr)
//        {

//        }
//        else
//            fprintf(f1, "Список пуст.");
//}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
