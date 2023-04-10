#include <iostream>
using namespace std;

#define MAX 10
 
class Deque {
  int arr[MAX];
  int front;
  int rear;
  int size;

public:
  Deque(int size) {
    front = -1;
    rear = 0;
    this->size = size;
  }

  void insertfront(int key);
  void insertrear(int key);
  void deletefront();
  void deleterear();
  bool isFull();
  bool isEmpty();
  int getFront();
  int getRear();
};

bool Deque::isFull() {
  return ((front == 0 && rear == size - 1) ||
      front == rear + 1);
}

bool Deque::isEmpty() {
  return (front == -1);
}

void Deque::insertfront(int key) {
  if (isFull()) {
    cout << "Overflow\n"
       << endl;
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (front == 0)
    front = size - 1;

  else
    front = front - 1;

  arr[front] = key;
  cout << "Pedido adicionado na frente da fila: " << key << endl;
}

void Deque::insertrear(int key) {
  if (isFull()) {
    cout << "Overflow\n"
       << endl;
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (rear == size - 1)
    rear = 0;

  else
    rear = rear + 1;

  arr[rear] = key;
  cout << "Pedido adicionado no final da fila: " << key << endl;
}

void Deque::deletefront() {
  if (isEmpty()) {
    cout << "Fila vazia\n"
       << endl;
    return;
  }

  int key = arr[front];

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == size - 1)
    front = 0;

  else
    front = front + 1;

  cout << "Pedido removido da frente da fila: " << key << endl;
}

void Deque::deleterear() {
  if (isEmpty()) {
    cout << "Fila vazia\n"
       << endl;
    return;
  }

  int key = arr[rear];

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (rear == 0)
    rear = size - 1;
  else
    rear = rear - 1;

  cout << "Pedido removido do final da fila: " << key << endl;
}

int Deque::getFront() {
  if (isEmpty()) {
    cout << "Fila vazia\n"
       << endl;
    return -1;
  }
  return arr[front];
}

int Deque::getRear() {
  if (isEmpty() || rear < 0) {
    cout << "Fila vazia\n"
       << endl;
    return -1;
  }
  return arr[rear];
}

int main() {
	
  int size;
  cout << "Qual a capacidade maxima do restaurante? ";
  cin >> size;
  
Deque dq(size);

int option, value;
do {
cout << "Escolha uma opcao:" << endl;
cout << "1. Adicionar pedido na frente da fila" << endl;
cout << "2. Adicionar pedido no final da fila" << endl;
cout << "3. Remover pedido da frente da fila" << endl;
cout << "4. Remover pedido do final da fila" << endl;
cout << "5. Verificar se a fila esta vazia" << endl;
cout << "6. Verificar se a fila esta cheia" << endl;
cout << "7. Obter o pedido na frente da fila" << endl;
cout << "8. Obter o pedido no final da fila" << endl;
cout << "9. Sair" << endl;
cin >> option;
switch (option) {
  case 1:
    cout << "Digite o numero do pedido: ";
    cin >> value;
    dq.insertfront(value);
    break;

  case 2:
    cout << "Digite o numero do pedido: ";
    cin >> value;
    dq.insertrear(value);
    break;

  case 3:
    dq.deletefront();
    break;

  case 4:
    dq.deleterear();
    break;

  case 5:
    if (dq.isEmpty())
      cout << "Fila vazia\n";
    else
      cout << "Fila nao esta vazia\n";
    break;

  case 6:
    if (dq.isFull())
      cout << "Fila cheia\n";
    else
      cout << "Fila nao esta cheia\n";
    break;

  case 7:
    cout << "Pedido na frente da fila e: ";
    cout << dq.getFront() << endl;
    break;

  case 8:
    cout << "Pedido no final da fila e: ";
    cout << dq.getRear() << endl;
    break;

  case 9:
    cout << "Encerrando o programa...\n";
    break;

  default:
    cout << "Opção invalida, tente novamente.\n";
    break;
}
} while (option != 9);

return 0;
}
