class Node {
    constructor(value) {
        this.head = value;
        this.next = null;
    }
}

class LinkedList {
    constructor(value) {
        this.head = new Node(value);
        this.tail = this.head;
        this.length = 1;
    }

    push(value) {
        const newNode = new Node(value);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
            this.length++;
            return;
        }
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
    }

    pop() {
        if (this.length === 0) return null;
        if (this.length === 1) {
            this.head = null;
            this.tail = null;
            this.length = 0;
            return;
        }
        let temp = this.head;
        while (temp.next && temp.next.next) {
            temp = temp.next;
        }
        this.tail = temp;
        this.tail.next = null;
        this.length--;
    }

    unshift(value) {
        const newNode = new Node(value);
        if (this.length === 0) {
            this.head = newNode;
            this.tail = newNode;
            this.length++;
            return;
        }
        newNode.next = this.head;
        this.head = newNode;
        this.length++;
    }

    shift() {
        if (this.length === 0) return null;
        const temp = this.head;
        this.head = this.head.next;
        this.length--;
        if (this.length === 0) {
            this.tail = null;
        }
    }

    getFirst() {
        return this.head;
    }

    getLast() {
        return this.tail;
    }

    getIndex(index) {
        if (index < 0 || index >= this.length) return null;
        let temp = this.head;
        let count = 0;
        while (count < index) {
            temp = temp.next;
            count++;
        }
        return temp;
    }

    setIndex(index, value) {
        const targetNode = this.getIndex(index);
        if (targetNode) {
            targetNode.head = value;
        }
    }

    clear() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    Insert(index, value) {
        if (index < 0 || index > this.length) return null;
        const newNode = new Node(value);
        if (index === 0) {
            newNode.next = this.head;
            this.head = newNode;
            if (this.length === 0) {
                this.tail = newNode;
            }
        } else if (index === this.length) {
            this.tail.next = newNode;
            this.tail = newNode;
        } else {
            let temp = this.head;
            let count = 0;
            while (count < index - 1) {
                temp = temp.next;
                count++;
            }
            newNode.next = temp.next;
            temp.next = newNode;
        }
        this.length++;
    }


    reverse(){
        let pre=null;
        let current;
        let temp=this.head;
        for(let i=0;i<this.length;i++){
            current=temp.next;
            temp.next=pre;
            pre=temp;
            temp=current;
        }
        let mytemp=this.head;
        this.head=this.tail;
        this.tail=mytemp;
    }
}

// Initialize linked list
const list = new LinkedList(1);

// 1. Unshift nodes
list.unshift(2); // Add 2 at the beginning
list.unshift(3); // Add 3 at the beginning
console.log("After unshift operations:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("\n");

// 2. Set specific indices
list.setIndex(0, 20);
list.setIndex(1, 10);
list.setIndex(2, 30);
console.log("After setIndex operations:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("\n");

// 3. Push new nodes
list.push(50); // Add 50 at the end
console.log("After push operation:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("\n");

// 4. Insert at specific indices
list.Insert(4, 40); // Insert 40 at index 4
list.Insert(1, 40); // Insert 40 at index 1
list.Insert(3, 40); // Insert 40 at index 3
console.log("After Insert operations:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("\n");

// 5. Pop a node
list.pop(); // Remove the last node
console.log("After pop operation:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("\n");

// 6. Shift a node
list.shift(); // Remove the first node
console.log("After shift operation:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("\n");

// 7. Clear the list
//list.clear(); // Clear all nodes
console.log("before reverse operation:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
list.reverse();
console.log("after reverse operation:");
for (let i = 0, current = list.head; i < list.length; i++) {
    console.log(current.head);
    current = current.next;
}
console.log("before clear operation:");
console.log(list)
list.clear();
console.log("after clear operation:");
console.log(list)
