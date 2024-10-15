/*

For optimal solution look here:
https://gist.github.com/vedantbothikar/cb32f43345c62f7aeb8a2fe1987a8423

*/


int calculateNewIndex(int oldIndex, int rotation, int sizeOfArray) {

    int lastIndex = sizeOfArray;

    if(oldIndex - rotation < 0) {
        return lastIndex - (rotation - oldIndex);
    }
    else {
        return oldIndex - rotation;
    }
    
}

vector<int> rotateArray(vector<int>arr, int k) {
    
    vector<int> duplicate = arr;

    for(int i=0; i<arr.size(); i++) {

        int newIndex = calculateNewIndex(i, k, duplicate.size());
        arr[newIndex] = duplicate[i];
    }

    return arr;
}