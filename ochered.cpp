# ochered
/*! \file main.cpp
Главный файл проекта
*/
#include <iostream>
using namespace std;
const int N=4; 

/** 
Структура
*/

struct Queue
{
int data[N]; 
int last; 
};

/** fn void Creation(Queue *Q)
Очередь
*/

void Creation(Queue *Q) 
{ Q->last=0; }
bool Full(Queue *Q) 
{
if (Q->last==0) return true;
else return false;
}

/** fn void Add(Queue *Q)
Добавление элемента
*/

void Add(Queue *Q)
{
if (Q->last==N)
{ 
cout<<"\n Очередь заполнена \n\n"; return; }
int value;
cout<<"\n Значение > "; cin>>value;
Q->data[Q->last++]=value;
cout<<endl<<"Элемент добавлен в очередь\n\n";
}

/** fn void Delete(Queue *Q)
Удаление элемента
*/

void Delete(Queue *Q) 
{
for (int i=0; i<Q->last && i<N; i++) 
Q->data[i]=Q->data[i+1]; Q->last--;
}
int Top(Queue *Q) 
{ return Q->data[0]; }
int Size(Queue *Q) 
{ return Q->last; }

/** \fn void main()
Главная функция проекта
*/

void main()
{
setlocale(LC_ALL,"Rus");
Queue Q;
Creation(&Q);
char number;
do
{
cout<<"1. Добавить элемент"<<endl;
cout<<"2. Удалить элемент"<<endl;
cout<<"3. Вывести верхний элемент"<<endl;
cout<<"4. Узнать размер очереди"<<endl;
cout<<"0. Выйти\n\n";
cout<<"Номер команды > "; cin>>number;
switch (number)
{
case '1': Add(&Q);
break;

case '2':
if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
else
{
Delete(&Q);
cout<<endl<<"Элемент удален из очереди\n\n";
} break;

case '3':
if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
else cout<<"\nНачальный элемент: "<<Top(&Q)<<"\n\n";
break;

case '4':
if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
else cout<<"\nРазмер очереди: "<<Size(&Q)<<"\n\n";
break;

case '0': break;
default: cout<<endl<<"Команда не определена\n\n";
break;
}
} while(number!='0');
system("pause");
}
