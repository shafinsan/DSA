let arr=[7,1,5,3,6,4]

const maxPrice=(arr)=>{
    let minValue=arr[0];
    let protentialValue=0;
    for(let i=1;i<arr.length;i++){
        let currentPrice=arr[i];
        protentialValue=Math.max(protentialValue,currentPrice-minValue);
        minValue=Math.min(currentPrice,minValue);
    }
    return protentialValue;
    
}
console.log(maxPrice(arr));