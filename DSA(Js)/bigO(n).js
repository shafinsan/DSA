let arr=["1","2","3"];
const searchElement=(arr,element)=>{
    for(let i=0;i<arr.length;i++){
        if(arr[i]===element){
            console.log(`found ${arr[i]}`);
            return;
        }
    }
}
searchElement(arr,"2")