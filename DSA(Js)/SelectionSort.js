let array = [9, 1, 2, 4, 5, 3, 7, 5, 8];

const SelectionSort = (array) => {
    for (let i = 0; i < array.length - 1; i++) {

        let minIndex = i;


        for (let j = i + 1; j < array.length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

    
        if (minIndex !== i) {
            let temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
    return array;
};

console.log(SelectionSort(array));
