#include <iostream>

using namespace std;


class Node 
{
public:
	int value;  // Значение узла
	Node * next; // Указатель на следующий узел
	Node * prev; // Указатель на предыдущий узел

	// Конструктор узла
	Node(int val) : value(val), next(nullptr), prev(nullptr) {}
	
};

// Класс двусвязного списка
class DoubleLinkedList 
{
private:
	Node* head; // Указатель на первый узел списка
	Node* tail; // Указатель на последний узел списка

public:
	// Конструктор списка
	DoubleLinkedList() : head(nullptr), tail(nullptr) {}
	
			    // Метод для печати значений в списке
	void PrintValuesInList() const 
	{
		cout << endl << "Values in the list: ";
		Node * current = head;
			    // Проходим по списку и печатаем значения узлов
		while (current != nullptr) 
		{
			cout << current->value << " ";
			current = current->next;
			
		}
		cout << endl;		
	}
	
		// Метод для добавления элемента в конец списка
	void PushBack(int value) 
	{
		Node * newNode = new Node(value); // Создаем новый узел
		if (!head) // Если список пуст		 
			head = tail = newNode; // Новый узел становится и головой, и хвостом	
		else 
		{
			tail->next = newNode; // Связываем текущий хвост с новым узлом
			newNode->prev = tail; // Устанавливаем предыдущий узел для нового узла
			tail = newNode; // Новый узел становится новым хвостом			
		}		
	}	
	// Метод для получения значения последнего элемента
	int GetLastValue() 
	{
		if (!tail) 
			return -1; // Возвращаем -1

		return tail->value; // Возвращаем значение последнего узла		
	}

	// Метод для получения узла по значению
	Node * GetNodeByValue(int targetValue) 
	{
		Node * current = head;
		// Проходим по списку и ищем узел с заданным значением
		while (current) 
		{
			if (current->value == targetValue) 
				return current; // Возвращаем узел, если найден		
			
			current = current->next;
			
		}
		return nullptr; // Возвращаем nullptr, если узел не найден
		
	}
	
			    // Метод для добавления элемента в начало списка
		void PushTop(int value);
	
			    // Метод для удаления узла по указателю
		bool EraseElementByPointer(Node * pointer);
		   // может принимать на вход результат GetNodeByValue(..)
		
			    // Метод для получения размера списка
		size_t size();
	
			    // Метод для проверки, пуст ли список
		bool isEmpty();	
};
//-----------------------------------------------

int main()
{
	DoubleLinkedList myList;
	myList.PushBack(1);
	myList.PushBack(3);
	myList.PushBack(5);
	myList.PrintValuesInList();

	myList.PushTop(7);
	myList.PrintValuesInList();

	myList.EraseElementByPointer(myList.GetNodeByValue(3));
	myList.PrintValuesInList();

	cout << "List size: " << myList.size() << endl;

	cout << "List is Empty? " << myList.isEmpty() << endl;


	return 0;
}
//-----------------------------------------------

void DoubleLinkedList::PushTop(int value) 
{
	Node* newNode = new Node(value);

	if (!head) 
		head = tail = newNode;
	
	else 
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
//-----------------------------------------------

bool DoubleLinkedList::EraseElementByPointer(Node* pointer) 
{
	if (!pointer) 
		return false;  // Неверный указатель
	

	if (pointer == head) 
		head = pointer->next;
	else 	
		pointer->prev->next = pointer->next;	

	if (pointer == tail) 	
		tail = pointer->prev;	
	else 
		pointer->next->prev = pointer->prev;
	

	delete pointer;
	return true;
}
//-----------------------------------------------

size_t DoubleLinkedList::size() 
{
	size_t count = 0;
	Node* current = head;

	while (current) 
	{
		count++;
		current = current->next;
	}

	return count;
}
//-----------------------------------------------

bool DoubleLinkedList::isEmpty() 
{
	return head == nullptr;
}


