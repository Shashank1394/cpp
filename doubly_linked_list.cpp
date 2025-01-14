#include <iostream>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;

void create();
void insert_at_beginning();
void insert_at_last();
void insert_in_between();
void display();

int main() {
  int ch;
  while (1) {
    std::cout << "\n\n--- Doubly Linked List --";
    std::cout << "\n1. Create";
    std::cout << "\n2. Insert at beginning";
    std::cout << "\n3. Insert at last";
    std::cout << "\n4. Insert in between";
    std::cout << "\n5. Display";
    std::cout << "\n6. Exit";
    std::cout << "\nEnter your choice: ";
    std::cin >> ch;

    switch (ch) {
    case 1:
      create();
      break;
    case 2:
      insert_at_beginning();
      break;
    case 3:
      insert_at_last();
      break;
    case 4:
      insert_in_between();
      break;
    case 5:
      display();
      break;
    case 6:
      return (0);
      break;
    default:
      std::cout << "Invalid choice!\n";
    }
  }
  return 0;
}

void create() {
  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  if (head == NULL) {
    head = newnode;
    std::cout << "Doubly linked list created successfully!\n";
    return;
  }
}

void insert_at_beginning() {
  if (head == NULL) {
    create();
    return;
  }

  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  newnode->next = head;
  head = newnode;
  return;
}

void insert_at_last() {
  if (head == NULL) {
    create();
    return;
  }

  struct node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  curr->next = newnode;
  newnode->prev = curr;
}

void insert_in_between() {
  if (head == NULL) {
    create();
    return;
  }

  int insert_here;
  std::cout << "\nWhere do you wanna insert it: ";
  std::cin >> insert_here;

  if (insert_here <= 1) {
    insert_at_beginning();
    return;
  }

  node *curr = head;
  int i = 1;
  while (i < insert_here - 1 && curr->next != NULL) {
    curr = curr->next;
    i++;
  }

  if (i > insert_here) {
    std::cout << "Position out of range. Inserting at the end.\n";
    insert_at_last();
    return;
  } else {
    std::cout << "Fool!";
  }

  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  newnode->next = curr->next;
  newnode->prev = curr;
  curr->next->prev = newnode;
  curr->next = newnode;

  std::cout << "Inserted at position " << insert_here << ".\n";
}

void display() {
  node *curr = head;
  std::cout << "\nDoubly Linked List: ";
  while (curr != NULL) {
    std::cout << curr->data << " -> ";
    curr = curr->next;
  }
  std::cout << "NULL\n";
}
