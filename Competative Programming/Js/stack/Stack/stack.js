class stack{
    constructor(size){
        this.size=size;
        this.arr=new Array(size);
        this.top=-1;
    }
    push(value){
        if(!this.isExcced()){
            this.top++;
            this.arr[this.top]=value;
            return;
        }
        console.log("stack is overflow");
        return;
    }
    pop(){
        if(!this.isEmpty()){
            this.top--;
            return;
        }
        console.log("stack is underflow");
    }
    peek(){
         if(!this.isEmpty()){
            return this.arr[this.top];
        }
         console.log("stack is underflow");
         return;
        
    }
    isEmpty(){
        return this.top==-1?true:false;    
    }
    isExcced(){
        return this.top==this.size-1?true:false;
    }
    display() {
        if(!this.isEmpty()){
          for(let i=0;i<=this.top;i++){
            console.log("stack value is :"+this.arr[i]+" ");
           }
        }
        else{
             console.log("stack is underflow");
        }
    }

}

const st=new stack(5);
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);
st.push(6);
st.display();
st.pop()
console.log("after pop top stack value is :",st.peek())
st.pop()
st.display()
st.pop()
st.pop()
st.display()
st.pop()
st.pop()
st.display()

