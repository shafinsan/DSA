let array=[9,1,2,4,5,3,7,5,8]
const bubbleSort=(array)=>{
    for(let i=0;i<array.length-1;i++){
        var flag=false;
        for(let j=0;j<array.length-1-i;j++){
            if(array[j]>array[j+1]){
                let temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                flag=true;
            }   
        }
        if(flag==false){
            return array;
        }
    }
}
console.log(bubbleSort(array));