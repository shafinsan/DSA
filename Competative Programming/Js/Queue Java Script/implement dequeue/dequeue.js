const prompt = require("prompt-sync")();

class Deque {
    constructor(size) {
        this.n = size;
        this.arr = new Array(size);
        this.front = -1;
        this.rear = -1;
    }

    isEmpty() {
        return this.front === -1 && this.rear === -1;
    }

    isFull() {
        return ((this.rear + 1) % this.n) === this.front;
    }

    pushFront(x) {
        if (this.isFull()) return false;

        if (this.isEmpty()) {
            this.front = this.rear = 0;
        } else {
            this.front = (this.front - 1 + this.n) % this.n;
        }

        this.arr[this.front] = x;
        return true;
    }

    pushRear(x) {
        if (this.isFull()) return false;

        if (this.isEmpty()) {
            this.front = this.rear = 0;
        } else {
            this.rear = (this.rear + 1) % this.n;
        }

        this.arr[this.rear] = x;
        return true;
    }

    popFront() {
        if (this.isEmpty()) return -1;

        const val = this.arr[this.front];
        if (this.front === this.rear) {
            this.front = this.rear = -1;
        } else {
            this.front = (this.front + 1) % this.n;
        }

        return val;
    }

    popRear() {
        if (this.isEmpty()) return -1;

        const val = this.arr[this.rear];
        if (this.front === this.rear) {
            this.front = this.rear = -1;
        } else {
            this.rear = (this.rear - 1 + this.n) % this.n;
        }

        return val;
    }

    getFront() {
        return this.isEmpty() ? -1 : this.arr[this.front];
    }

    getRear() {
        return this.isEmpty() ? -1 : this.arr[this.rear];
    }
}

// Main driver code
const size = parseInt(prompt("Enter size of Deque: "));
const dq = new Deque(size);
let choice, value;

do {
    console.log("\n--- Deque Menu ---");
    console.log("1. Push Front");
    console.log("2. Push Rear");
    console.log("3. Pop Front");
    console.log("4. Pop Rear");
    console.log("5. Get Front");
    console.log("6. Get Rear");
    console.log("7. Check if Empty");
    console.log("8. Check if Full");
    console.log("9. Exit");
    choice = parseInt(prompt("Enter your choice: "));

    switch (choice) {
        case 1:
            value = parseInt(prompt("Enter value to push at front: "));
            console.log(dq.pushFront(value) ? "Pushed at front." : "Deque is Full!");
            break;
        case 2:
            value = parseInt(prompt("Enter value to push at rear: "));
            console.log(dq.pushRear(value) ? "Pushed at rear." : "Deque is Full!");
            break;
        case 3:
            value = dq.popFront();
            console.log(value === -1 ? "Deque is Empty!" : `Popped from front: ${value}`);
            break;
        case 4:
            value = dq.popRear();
            console.log(value === -1 ? "Deque is Empty!" : `Popped from rear: ${value}`);
            break;
        case 5:
            value = dq.getFront();
            console.log(value === -1 ? "Deque is Empty!" : `Front element: ${value}`);
            break;
        case 6:
            value = dq.getRear();
            console.log(value === -1 ? "Deque is Empty!" : `Rear element: ${value}`);
            break;
        case 7:
            console.log(dq.isEmpty() ? "Deque is Empty" : "Deque is NOT Empty");
            break;
        case 8:
            console.log(dq.isFull() ? "Deque is Full" : "Deque is NOT Full");
            break;
        case 9:
            console.log("Exiting...");
            break;
        default:
            console.log("Invalid Choice! Try again.");
    }
} while (choice !== 9);
