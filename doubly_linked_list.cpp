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
void delete_first_node();
void delete_last_node();
void delete_selected_node();
void display();

int main() {
  int ch;
  while (1) {
    std::cout << "\n\n--- Doubly Linked List ---";
    std::cout << "\n1. Create";
    std::cout << "\n2. Insert at beginning";
    std::cout << "\n3. Insert at last";
    std::cout << "\n4. Insert in between";
    std::cout << "\n5. Display";
    std::cout << "\n6. Delete first node";
    std::cout << "\n7. Delete last node";
    std::cout << "\n8. Delete selected node";
    std::cout << "\n0. Exit";
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
      delete_first_node();
      break;
    case 7:
      delete_last_node();
      break;
    case 8:
      delete_selected_node();
      break;
    case 0:
      return 0;
    default:
      std::cout << "Invalid choice!\n";
    }
  }
}

void create() {
  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  if (head == NULL) {
    head = newnode;
    std::cout << "Doubly linked list created successfully!\n";
  } else {
    std::cout << "List already created. Use insert operations.\n";
  }
  display();
}

void insert_at_beginning() {
  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  if (head == NULL) {
    head = newnode;
  } else {
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
  }
  std::cout << "Inserted at the beginning.\n";
  display();
}

void insert_at_last() {
  if (head == NULL) {
    create();
    return;
  }

  node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  curr->next = newnode;
  newnode->prev = curr;
  std::cout << "Inserted at the last.\n";
  display();
}

void insert_in_between() {
  if (head == NULL) {
    std::cout << "\nList is empty. Creating a new list...\n";
    create();
    return;
  }

  int position;
  std::cout << "\nEnter the position to insert: ";
  std::cin >> position;

  if (position <= 1) {
    insert_at_beginning();
    return;
  }

  node *curr = head;
  int i = 1;
  while (i < position - 1 && curr->next != NULL) {
    curr = curr->next;
    i++;
  }

  if (curr->next == NULL) {
    std::cout << "Position out of range. Inserting at the end.\n";
    insert_at_last();
    return;
  }

  node *newnode = new node;
  newnode->next = newnode->prev = NULL;
  std::cout << "\nEnter the data: ";
  std::cin >> newnode->data;

  newnode->next = curr->next;
  if (curr->next != NULL) {
    curr->next->prev = newnode;
  }
  curr->next = newnode;
  newnode->prev = curr;

  std::cout << "Inserted at position " << position << ".\n";
  display();
}

void delete_first_node() {
  if (head == NULL) {
    std::cout << "\nDoubly does not double!";
  } else {
    node *curr = head;
    head = head->next;
    head->prev = NULL;
    delete curr;
    std::cout << "\nFirst node removed successfully!";
    display();
  }
}

void delete_last_node() {
  if (head == NULL) {
    std::cout << "\nDoubly does not double!";
  } else {
    node *curr = head;
    while (curr->next != NULL)
      curr = curr->next;
    curr->prev->next = NULL;
    delete curr;
    std::cout << "\nLast node removed successfully!";
    display();
  }
}

void delete_selected_node() {
  if (head == NULL) {
    std::cout << "\nDoubly does not double!";
    return;
  }

  int position;
  std::cout << "\nEnter the position to delete: ";
  std::cin >> position;

  if (position <= 1) {
    delete_first_node();
    return;
  }

  node *curr = head;
  int i = 1;
  while (i < position && curr->next != NULL) {
    curr = curr->next;
    i++;
  }

  if (curr == NULL) {
    std::cout << "Position out of range. Deleted the last node insetead.\n";
    delete_last_node();
    return;
  }

  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  delete curr;

  std::cout << "Deleted at position " << position << ".\n";
  display();
}

void display() {
  if (head == NULL) {
    std::cout << "\nList is empty.\n";
    return;
  }

  node *curr = head;
  std::cout << "\nDoubly Linked List: ";
  while (curr != NULL) {
    std::cout << curr->data << " <-> ";
    curr = curr->next;
  }
  std::cout << "NULL\n";
}
