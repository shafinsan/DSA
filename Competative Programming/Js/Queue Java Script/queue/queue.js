const prompt = require("prompt-sync")();
class myqueue {
    constructor(size) {
        this.size = size;
        this.arr = new Array(this.size);
        this.front = -1;
        this.rear = -1;
    }
    push(x) {
        if (this.isFull()) {
            console.log("Queue is full");
            return;
        }
        if (this.isEmpty()) {
            this.front = 0;
            this.rear=0;
            this.arr[this.rear] = x;
            return;
        }
        this.rear = (this.rear + 1) % this.size;
        this.arr[this.rear] = x;
        return;
    }
    pop() {
        if (this.isEmpty()) {
            console.log("Queue is Empty")
            return;
        }
        if (this.rear === this.front) {
            this.rear = this.front = -1;
            return;
        }
        this.front = (this.front + 1) % this.size;
        return;
    }
    top() {
        if (this.isEmpty()) {
            return -1;
        }
        return this.arr[this.rear];
    }
    qfront() {
        if (this.isEmpty()) {
            return -1;
        }
        return this.arr[this.front];
    }
    isFull() {
        if ((this.rear + 1) % this.size == this.front) {
            return true;
        }
        return false;
    }
    isEmpty() {
        if (this.rear == -1 && this.front == -1) {
            return true;
        }
        return false;
    }
    display() {
        if (this.isEmpty()) {
            console.log("Queue is empty")
            return;
        }
        if (this.front <= this.rear) {
            for (let i = this.front; i <= this.rear; i++) {
                console.log("Queue value:" + this.arr[i]);
            }
            return;
        }
        else {
            for (let i = this.front; i < this.size; i++) {
                console.log("Queue value:" + this.arr[i]);
            }
            for (let i = 0; i < this.front; i++) {
                console.log("Queue value:" + this.arr[i]);
            }
            return;
        }
    }

}
const size = parseInt(prompt("Enter queue size: "));
const q = new myqueue(size);

let choice;

do {
    console.log("\n--- Menu ---");
    console.log("1. Push");
    console.log("2. Pop");
    console.log("3. Front element");
    console.log("4. Rear element");
    console.log("5. Display queue");
    console.log("6. Exit");
    choice = parseInt(prompt("Enter your choice: "));

    switch (choice) {
        case 1:
            const val = parseInt(prompt("Enter value to push: "));
            q.push(val);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            console.log("Front: ", q.qfront());
            break;
        case 4:
            console.log("Rear: ", q.top());
            break;
        case 5:
            q.display();
            break;
        case 6:
            console.log("Exiting...");
            break;
        default:
            console.log("Invalid choice.");
    }

} while (choice !== 6);