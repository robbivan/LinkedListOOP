#include <iostream>
#include <string>
using std::cout;
using std::endl;

template <class T>
class LinkedList
{
private:

    class Node
    {
    public:
        Node(T data=T(),Node*link= nullptr)
        {
            this->data=data;
            this->link=link;
        }
        T data;
        Node*link;
    };
    Node *head;
    int size;
    Node*SearchElement(T data)
    {
        Node*forSearchingElement=head;

        while(forSearchingElement!= nullptr)
        {
            if (forSearchingElement->data==data)
            {
                return forSearchingElement;
            }
            forSearchingElement=forSearchingElement->link;
        }
        return nullptr;
    };
    Node*SearchElementIndex(int index)
    {
        Node*step=head;
        int counter=0;
        while(counter<size)
        {
            if (counter==index)
            {
                return step;
            }
            counter++;
            step=step->link;
        }
        return nullptr;
    };

public:
    LinkedList();
    void CreationNode(T data);//создание и добавление элементов
    void DeleteNode(T data);//удаление узлов
    int GetSize()//размер
    {
        return size;
    }
    void Printer();
    bool ChangeData(T data, T newData);
    void InsertNode(int indexData, T newData);
    T& operator[](const int index);
    ~LinkedList();
};



template<class T>
LinkedList<T>::LinkedList()
{
    size=0;
    head = nullptr;
}
template<class T>
void LinkedList<T>::Printer()
{
    Node*step=head;
    while(step!= nullptr)
    {
        cout<<"Объект: "<<step->data<<endl;
        step=step->link;
    }
}
template <class T>
void LinkedList<T>::CreationNode(T data)
{
    if (size == 0)
    {
        head = new Node(data);
    }
    else
    {
        Node*dop=head;
        while(dop->link!= nullptr)
        {
            dop=dop->link;
        }
        dop->link=new Node(data);
    }
    size++;
}
template<class T>
void LinkedList<T>::InsertNode(int indexData, T newData)
{
    Node*insertRight= SearchElementIndex(indexData);
    if(!insertRight)
    {
        cout<<"Нет!"<<endl;
        return;
    }

    if (insertRight==head)
    {
        head=new Node(newData,insertRight);
    }
    else
    {
        Node*saveRight=head;
        while(saveRight->link!=insertRight)
        {
            saveRight=saveRight->link;
        }
        saveRight->link=new Node(newData,insertRight);
    }
    size++;
}

template<class T>
void LinkedList<T>::DeleteNode(T data)
{
    Node*curForDelete=SearchElement(data);//curForDelete == nullptr
    if (!curForDelete)
    {
        cout<<"Такого нет"<<endl;
        return;
    }
    if (curForDelete == head)
    {
      head=head->link;
      delete curForDelete;
      size--;
      return;
    }

    Node*prevForDelete=head;
    while(prevForDelete->link != curForDelete)
    {
        prevForDelete=prevForDelete->link;
    }
    if (curForDelete->link == nullptr)
    {
       delete curForDelete;
       prevForDelete->link= nullptr;
    }
    else
    {
        prevForDelete->link=curForDelete->link;
        delete curForDelete;
    }
    size--;
}
template<class T>
bool LinkedList<T>::ChangeData(T data, T newData)
{
    Node*res=SearchElement(data);
    if(res)
    {
        res->data=newData;
    }
    else
    {
        cout<<"Нет такого"<<endl;
    }
}

template <class T>
T&LinkedList<T>::operator[](const int index)// оператор перегрузки для удобного взаимодействия со списком
{

    int counter=0;
    Node*step=head;
    while (counter<this->size)
    {
        if (counter==index)
        {
            return step->data;
        }
        step=step->link;
        counter++;
    }
}



template<class T>
LinkedList<T>::~LinkedList<T>()//Деструктор
{
    Node*useForDelete=head;
    while(head!= nullptr)
    {
        head=head->link;
        delete useForDelete;
        useForDelete=head;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    LinkedList<int>firstLinkedList;
    ////Методы
    firstLinkedList.CreationNode(6);
    firstLinkedList.Printer();

    return 0;
}

