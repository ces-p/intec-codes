
function abs(n){
    mask = n>>31;
    mask ^ n;  
    return (mask^n) - mask ;
}
function isPos(x){
    return !((x&(1<<31)) | !x);
}
function isNeg(x){
    return !(!((x&(1<<31)) | !x));
}
function isOdd(x){
    if((x & 1) == 0)
        return false;
    else
        return true;
}
function isEven(x){
    if((x & 1) == 1)
        return false;
    else
        return true;
}
console.log(isEven(21));
