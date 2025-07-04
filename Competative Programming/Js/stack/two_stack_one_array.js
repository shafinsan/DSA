class TwoStacks {
    // constructor for twoStacks()
    constructor() {
        this.size=100;
        this.top1=-1;
        this.top2=this.size;
        this.arr=new Array(this.size);
    }

    // Function to push an integer into the stack1.
    push1(x) {
        // code here
        if(this.top2-this.top1>1){
            this.top1++;
            this.arr[this.top1]=x;
            return;
        }
        return;
        
    }

    // Function to push an integer into the stack2.
    push2(x) {
        
        // code here
        if(this.top2-this.top1>1){
            this.top2--;
            this.arr[this.top2]=x;
            return;
        }
        return;
    }

    // Function to remove an element from top of the stack1.
        
    pop1() {
        // code here
        if(this.top1==-1){
            return -1;
        }
        let ans=this.arr[this.top1];
        this.top1--;
        return ans;
    }

        
    // Function to remove an element from top of the stack2.
    pop2() {
        // code here
        if(this.top2==this.size){
            return -1;
        }
        let ans=this.arr[this.top2];
        this.top2++;
        return ans;
    }
}