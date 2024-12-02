let myString="abba";
const checkPalindromes=(myString)=>myString.split("").reverse().join("")===myString;
console.log(checkPalindromes(myString));