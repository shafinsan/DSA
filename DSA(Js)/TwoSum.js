let arr=[2,7,11,15]

const checkTagetFullfill=(arr,target)=>{
    let i=0;let j=arr.length-1;
    while(j>i){
        let currentSum=arr[i]+arr[j];
        if(currentSum===target){
            return true;
        }
        else if(currentSum>target){
            j--;
        }
        else{
            i++;
        }
    }
return false;
}
console.log(checkTagetFullfill(arr,18));