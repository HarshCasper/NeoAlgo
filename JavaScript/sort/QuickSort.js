
function quickSort(myArray){
	if(myArray.length ===0){
    return [];
    }
    let leftSide = [];
    let rightside = [];
    let pivot = myArray[0];
    for(let i = 1; i < myArray.length; i++){
    	if(myArray[i]<pivot){
        	leftSide.push(myArray[i]);
        }
        else rightside.push(myArray[i]);
    }
    return quickSort(leftSide).concat(pivot,quickSort(rightside));
}
	let ourArray = [];
    for(let i = 0; i < 10; i++){
    	ourArray[i] = Math.floor(Math.random() * 100 +1 );
    }
    console.log(ourArray)
    console.log(quickSort(ourArray));


