let myString="ELIAS JABER SHAFIN";
const CapitalizeValue=(myString)=>myString.toLowerCase().split(" ").map(value=>value[0].toUpperCase()+value.slice(1)).join(" ");
console.log(CapitalizeValue(myString));