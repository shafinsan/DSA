//in this scenario no exception is handle like if array is empty or if i try to access of out the array

class MyArray{
    constructor(){
        this.length=0;
        this.data={};
    }
    push(vlaue){
        this.data[this.length]=vlaue;
        this.length++;
    }
    get(index){
        return this.data[index];
    }
    pop(){
        delete this.data[this.length-1];
        this.length--;
    }
    shift(){
        for(let i=0;i<this.length-1;i++){
            this.data[i]=this.data[i+1];
        }
        this.pop();

    }
    delete(index){
        for(let i=index;i<this.length-1;i++){
            this.data[i]=this.data[i+1];
        }
        this.pop();
    }

}
newArray=new MyArray();
newArray.push("elias");
newArray.push("jaber");
newArray.push("shafin");
newArray.push("mango");
newArray.push("hero");
console.log(newArray);
console.log("get index 2 = ",newArray.get(2))
newArray.pop();
console.log(newArray);
newArray.shift();
console.log(newArray);
newArray.delete(2);
console.log(newArray);
