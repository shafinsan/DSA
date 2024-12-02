let arr=["1","2","3"];
const searchElement=(arr,element)=>{
    if(arr[element]){
        console.log(`found ${arr[element]}`);
    }
    else{
        console.log(`not found ${arr[element]}`);
    }
    
}
searchElement(arr,2)