class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    // Insert at the beginning (head)
    insertAtHead(data) {
        const newNode = new Node(data);
        if (!this.head) {
            this.head = this.tail = newNode;
            return;
        }
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
    }

    // Insert at the end (tail)
    insertAtTail(data) {
        const newNode = new Node(data);
        if (!this.tail) {
            this.head = this.tail = newNode;
            return;
        }
        newNode.prev = this.tail;
        this.tail.next = newNode;
        this.tail = newNode;
    }

    // Delete from the beginning (head)
    deleteAtHead() {
        if (!this.head) {
            console.log("List is empty");
            return;
        }
        if (this.head === this.tail) {
            this.head = this.tail = null;
            return;
        }
        this.head = this.head.next;
        this.head.prev = null;
    }

    // Delete from the end (tail)
    deleteAtTail() {
        if (!this.tail) {
            console.log("List is empty");
            return;
        }
        if (this.head === this.tail) {
            this.head = this.tail = null;
            return;
        }
        this.tail = this.tail.prev;
        this.tail.next = null;
    }

    // Insert at any position (1-based indexing)
    insertAtPosition(position, data) {
        if (position <= 1) {
            this.insertAtHead(data);
            return;
        }

        let current = this.head;
        let count = 1;

        // Traverse to the node just before the desired position
        while (count < position - 1 && current.next) {
            current = current.next;
            count++;
        }

        // If position exceeds list length, insert at tail
        if (!current.next) {
            this.insertAtTail(data);
            return;
        }

        // Insert new node in the middle
        const newNode = new Node(data);
        newNode.next = current.next;
        newNode.prev = current;
        current.next.prev = newNode;
        current.next = newNode;
    }

    // Delete at any position (1-based indexing)
    deleteAtPosition(position) {
        if (position <= 1) {
            this.deleteAtHead();
            return;
        }

        let current = this.head;
        let count = 1;

        // Traverse to the node to delete
        while (count < position && current) {
            current = current.next;
            count++;
        }

        // If position exceeds list length, do nothing (or throw error)
        if (!current) {
            console.log("Position out of bounds");
            return;
        }

        // If deleting the tail
        if (!current.next) {
            this.deleteAtTail();
            return;
        }

        // Delete from the middle
        current.prev.next = current.next;
        current.next.prev = current.prev;
        current.next = current.prev = null; // Cleanup
    }

    // Print list (forward and backward)
    display() {
        if (!this.head) {
            console.log("List is empty");
            return;
        }

        // Forward traversal
        let current = this.head;
        let forwardStr = "Forward: ";
        while (current) {
            forwardStr += current.data;
            if (current.next) forwardStr += " → ";
            current = current.next;
        }
        console.log(forwardStr);

        // Backward traversal
        current = this.tail;
        let backwardStr = "Backward: ";
        while (current) {
            backwardStr += current.data;
            if (current.prev) backwardStr += " → ";
            current = current.prev;
        }
        console.log(backwardStr);
    }
}
const list = new DoublyLinkedList();

list.insertAtPosition(3, 30); 
list.insertAtTail(20);        
list.insertAtPosition(3, 40); 
list.insertAtPosition(2, 25); 

list.deleteAtPosition(2);     
list.deleteAtPosition(5);     