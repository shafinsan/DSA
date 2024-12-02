let arr=[1,2,3,4,5,6,7,8];

const chunked=(arr,size)=>{
    let ans=[];
    for(let i=0;i<arr.length;){
        ans.push(arr.slice(i,i+size));
        i=i+size;
    }
    return ans;
}

console.log(chunked(arr,3));