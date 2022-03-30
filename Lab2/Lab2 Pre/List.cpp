#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
  count = 0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
  //makeEmpty();
  //delete head;
  //delete tail; 
}
// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if(head->next == tail && tail->previous == head){
  return true;
  }else{return false;}
}

void List::makeEmpty() {
  if(isEmpty()==false){
  ListItr temp;
  while(temp.current != NULL){
    temp.current=head->next;
    delete head;
    head=temp.current; 
  }
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
  }
}

ListItr List::first(){
  return ListItr(head->next);
}
  
ListItr List::last(){
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position){
  ListNode * insert = new ListNode();
  insert->value = x;
  
  insert->previous  = position.current;
  insert->next = position.current->next;
  position.current->next->previous = insert;
  position.current->next = insert;
  
}

void List::insertBefore(int x, ListItr position){
  ListNode * insert = new ListNode();
  insert->value = x;
  insert->previous = position.current->previous;
  insert->next = position.current;
  position.current->previous->next = insert;
  position.current->previous = insert;
}

void List::insertAtTail(int x){
  ListNode * insert = new ListNode();
  insert->value=x;
  
  insert->previous = tail->previous;
  insert->next = tail;
  tail->previous->next = insert;
  tail->previous = insert;
}

ListItr List::find(int x){
  ListItr * find = new ListItr();
  find->current = head;
  while(find->current != NULL){
    if(find->current->value == x){
      return *find;
    }else{
      find->current = find->current->next;
    }
  }
    find->current = tail;
    return *find;
}

void List::remove(int x){
  ListItr * remove = new ListItr();
  *remove=find(x);
  remove->current->next->previous = remove->current->previous;
  remove->current->previous->next = remove->current->next;
}

int List::size() const {
  ListItr temp;
  temp.current = head;
  int size = 0;
  while(temp.current != tail){
    size = size + 1;
    temp.current = temp.current->next;
  }
  return size-1;
}

void printList(List& source, bool forward){

  ListItr* temp = new ListItr(source.first());
  
  if(forward){
    while(temp->isPastEnd()==false){
      cout << temp->retrieve() <<" ";
      temp->moveForward();
    }
    cout<<endl;
  }else{
  temp = new ListItr(source.last());
    while(temp->isPastBeginning()==false){
      cout << temp->retrieve() << " " ;
      temp->moveBackward();
    }
    cout<<endl;
  }
}

  
  
