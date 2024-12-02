class Node{
    constructor(value){
        this.head=value;
        this.pre=null;
        this.next=null;
    }
}
class DoubleLinkedList{
    constructor(value){
        this.head=new Node(value);
        this.tail=this.head;
        this.length=1;
    }
    push(value){
        let newNode=new Node(value);
        if(this.length===0){
            this.head=newNode;
            this.tail=newNode;
        }
        else{
            this.tail.next=newNode;
            newNode.pre=this.tail;
            this.tail=newNode;
           
        }
        this.length++;
        return;
    }

    pop(){
        if(this.length===0){
            return null 
        }
        this.tail=this.tail.pre;
        this.tail.next=null;
        this.length--;
        return
    }
    shift(){
        if(this.length===0){
            return null 
        }
        this.head=this.head.next;
        this.head.pre=null;
        this.length--;
        return;
    }
    unshift(value){
        if(this.length===0){
            this.push(value);
            return;
        }
        let newValue=new Node(value)
        this.head.pre=newValue;
        newValue.pre=null;
        newValue.next=this.head;
        this.head=newValue;
        return;
    }

    printList() {
        let current = this.head;
        while (current) {
            console.log({
                value: current.head,
                prev: current.pre ? current.pre.head : null,
                next: current.next ? current.next.head : null,
            });
            current = current.next;
        }
    }
   
   
}
let list=new DoubleLinkedList(1);
list.push(2);
list.push(3);
list.push(3);
console.log("After pushing")
list.printList();
list.pop()
console.log("After poping")
list.printList()
console.log("After shifting")
list.shift();
list.printList()

console.log("After unshifting")
list.unshift(100);
list.unshift(101);
list.printList()