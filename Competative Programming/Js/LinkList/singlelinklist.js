// Node class
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

// Linked List class
class SinglyLinkedList {
  constructor() {
    this.head = null;
  }

  // Insert at the beginning
  insertAtHead(data) {
    const newNode = new Node(data);
    newNode.next = this.head;
    this.head = newNode;
  }

  // Insert at the end
  insertAtTail(data) {
    const newNode = new Node(data);
    if (this.head === null) {
      this.head = newNode;
      return;
    }

    let current = this.head;
    while (current.next !== null) {
      current = current.next;
    }

    current.next = newNode;
  }

  // Insert at a specific index
  insertAt(index, data) {
    if (index < 0) {
      console.log("Invalid index");
      return;
    }

    if (index === 0) {
      this.insertAtHead(data);
      return;
    }

    let newNode = new Node(data);
    let current = this.head;
    let previous = null;
    let count = 0;

    while (current !== null && count < index) {
      previous = current;
      current = current.next;
      count++;
    }

    if (count === index) {
      previous.next = newNode;
      newNode.next = current;
    } else {
      console.log("Index out of bounds");
    }
  }

  // Delete by value
  deleteByValue(value) {
    if (this.head === null) return;

    if (this.head.data === value) {
      this.head = this.head.next;
      return;
    }

    let current = this.head;
    let previous = null;

    while (current !== null && current.data !== value) {
      previous = current;
      current = current.next;
    }

    if (current === null) {
      console.log("Value not found");
      return;
    }

    previous.next = current.next;
  }

  // Delete at a specific index
  deleteAt(index) {
    if (index < 0 || this.head === null) {
      console.log("Invalid index or list is empty");
      return;
    }

    if (index === 0) {
      this.head = this.head.next;
      return;
    }

    let current = this.head;
    let previous = null;
    let count = 0;

    while (current !== null && count < index) {
      previous = current;
      current = current.next;
      count++;
    }

    if (current === null) {
      console.log("Index out of bounds");
      return;
    }

    previous.next = current.next;
  }

  // Search for a value
  search(value) {
    let current = this.head;
    let index = 0;
    while (current !== null) {
      if (current.data === value) return index;
      current = current.next;
      index++;
    }
    return -1;
  }

  // Display the linked list
  display() {
    let current = this.head;
    let result = "";
    while (current !== null) {
      result += current.data + " -> ";
      current = current.next;
    }
    result += "null";
    console.log(result);
  }
}



const list = new SinglyLinkedList();

list.insertAtHead(10);
list.insertAtTail(20);
list.insertAtTail(30);
list.insertAt(1, 15);       
list.display();            

list.deleteByValue(20);     
list.display();             

list.deleteAt(0);         
list.display();             

console.log("Index of 30:", list.search(30)); 
console.log("Index of 50:", list.search(50)); 
