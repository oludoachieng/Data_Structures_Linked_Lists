#include<iostream>
#include<string>

template <typename T>
class Node
{
public:
	Node<T>* nextptr;
	T data;

	Node(T data)
	{
		this->nextptr = nullptr;
		this->data = data;
	};
	~Node()
	{
		delete this->nextptr;
	};
};


template <typename T>
class LinkedList
{
private:
	Node<T>* root;
	int nodeNmbr;

public:
	LinkedList();
	~LinkedList();
	void insertEnd(T data);
	void printLinkedList();
};


int main()
{
	LinkedList<std::string> myLinkedList;
	myLinkedList.insertEnd("Name ");
	myLinkedList.insertEnd("Surname");
	myLinkedList.printLinkedList();

	return 0;
}

template<typename T>
LinkedList<T>::LinkedList()
{
	this->nodeNmbr = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	this->nodeNmbr = 0;
}

template<typename T>
void LinkedList<T>::insertEnd(T data)
{
	if (this->nodeNmbr == 0)
	{
		this->root = new Node<T>(data);
		this->nodeNmbr = nodeNmbr++;
	}
	else
	{
		Node<T>* temp = this->root;

		while (temp->nextptr != 0)
		{
			temp = temp->nextptr;
		}
		temp->nextptr = new Node<T>(data);
		this->nodeNmbr = nodeNmbr++;
	}
}

template<typename T>
void LinkedList<T>::printLinkedList()
{
	if (this->nodeNmbr == 0)
	{
		std::cout << "Empty List" << std::endl;
		return;
	}
	else
	{
		Node<T>* temp = this->root;
		int indx = nodeNmbr;
		while (indx > 0)
		{
			std::cout << temp->data << std::endl;
			indx--;
			temp = temp->nextptr;
		}
	}
}
