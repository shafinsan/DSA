class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class CircularSinglyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    // Insert at the beginning
    insertAtHead(data) {
        const newNode = new Node(data);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
            newNode.next = newNode; // Points to itself
            return;
        }
        newNode.next = this.head;
        this.tail.next = newNode;
        this.head = newNode;
    }

    // Insert at the end
    insertAtTail(data) {
        const newNode = new Node(data);
        if (!this.head) {
            this.insertAtHead(data);
            return;
        }
        newNode.next = this.head;
        this.tail.next = newNode;
        this.tail = newNode;
    }

    // Delete from the beginning
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
        this.tail.next = this.head;
    }

    // Delete from the end
    deleteAtTail() {
        if (!this.head) {
            console.log("List is empty");
            return;
        }
        if (this.head === this.tail) {
            this.head = this.tail = null;
            return;
        }
        let current = this.head;
        while (current.next !== this.tail) {
            current = current.next;
        }
        current.next = this.head;
        this.tail = current;
    }

    // Insert at a given position (1-based)
    insertAtPosition(position, data) {
        if (position <= 1) {
            this.insertAtHead(data);
            return;
        }

        let current = this.head;
        let count = 1;

        while (count < position - 1 && current.next !== this.head) {
            current = current.next;
            count++;
        }

        if (current.next === this.head) {
            this.insertAtTail(data);
            return;
        }

        const newNode = new Node(data);
        newNode.next = current.next;
        current.next = newNode;
    }

    // Delete at a given position (1-based)
    deleteAtPosition(position) {
        if (!this.head) {
            console.log("List is empty");
            return;
        }
        if (position <= 1) {
            this.deleteAtHead();
            return;
        }

        let current = this.head;
        let prev = null;
        let count = 1;

        while (count < position && current.next !== this.head) {
            prev = current;
            current = current.next;
            count++;
        }

        if (current.next === this.head && count < position) {
            console.log("Position out of bounds");
            return;
        }

        prev.next = current.next;
        if (current === this.tail) {
            this.tail = prev;
        }
    }

    // Display the list
    display() {
        if (!this.head) {
            console.log("List is empty");
            return;
        }

        let current = this.head;
        let result = "";
        do {
            result += current.data + " → ";
            current = current.next;
        } while (current !== this.head);

        console.log(result.slice(0, -3)); 
    }
}
const csll = new CircularSinglyLinkedList();
csll.insertAtHead(10);
csll.insertAtTail(20);
csll.insertAtPosition(2, 15);
csll.display(); 
csll.deleteAtPosition(2);
csll.display();