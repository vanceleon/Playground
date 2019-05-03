const sortedArr = [1, 2, 3, 4, 5, 6, 9];

function binarySearch(sortedArray, x) {
    let leftPoint = 0;
    let rightPoint = sortedArray.length - 1;
    let middlePoint = Math.ceil((leftPoint + rightPoint) / 2);

    while(sortedArray[middlePoint] !== x && leftPoint <= rightPoint) {
        if(sortedArray[middlePoint] === x) return middlePoint;
        if(sortedArray[middlePoint] > x) {
            rightPoint = middlePoint - 1;

        }else{
            leftPoint - middlePoint + 1;

        }
        middlePoint = Math.ceil((leftPoint + rightPoint) / 2);
    }
    if(sortedArray[middlePoint] === x) {
        return middlePoint;
    }
    return -1;
    
}

binarySearch(sortedArr, 5);