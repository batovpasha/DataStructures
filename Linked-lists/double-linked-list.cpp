#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int COUNT = 1000000;

struct Node {
 int data;
 Node *prev;
 Node *next;
};

class List {
  public:
      void print_list(Node *head) {
        Node *mid = head;
        while(mid) {
            cout << mid->data << endl;
            mid = mid->next;
        }
      }
      void add_to_begin(Node **head, int element) {
        Node *el = new Node;
        el->data = element;
        el->prev = NULL;
        el->next = *head;
        (*head)->prev = el;
        *head = el;
      }
};

int main() {
  Node *head = NULL;
  Node *first_el = new Node;
  srand(time(NULL));
  first_el->data = rand() % 10000 + 1;
  first_el->prev = NULL;
  first_el->next = NULL;
  head = first_el;
  Node *tail = head;
  tail->next = NULL;
  tail->prev = NULL;
  List lists;
  for (int i = 0; i < COUNT; i++) {
    int random_number = rand() % 10000 + 1;
    lists.add_to_begin(&head, random_number);
  }
  lists.print_list(head);
  return 0;
}
