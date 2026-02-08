//2. Напишете функция, която приема символен низ и връща нов низ, за който е заделено точно количество памет,
//   който съдържа всички символи от подадения низ, които се срещат само веднъж в него.

//  Вход                    Изход
//  akalhk3g#5ggkkks	    lh3#5s

/*
 * 1. Правим функция int occurences (char *array, int current)
 *      - counter = 0;
 *      - Взимаме символа на current позиция -> циклим масива от 0 до arrsize-1 позиция и за всяко съвпадение с array[current] -> counter++;
 *      - return counter;
 *
 * 2. В мейна dynamicsize = 1;
 *      Пускаме цикъл от 0 до arrsize-1 позиция, и за всяка позиция рънваме  *** occurences (char *array, int позиция) ***
 *          Ако occurences (char *array, int позиция) == 1 { dynamicssize++;}
 *
 *  3. char newArray = new char[dynamicsize];
 *
 *  4. int newCurrPos = 0;
 *        С още един цикъл
 *        Пускаме цикъл от 0 до arrsize-1 позиция, и за всяка позиция рънваме  *** occurences (char *array, int позиция) ***
 *        Ако occurences (char *array, int позиция) == 1 { newArray[newCurrPos] == array[позиция]; newCurrPos++;
 *
*/


#include <iostream>



int occurences (char *array, int current) {
    int occurencesCount = 0;
    int index = 0;

    while (array[index] != '\0') {
        if (array[index] == array[current]) {
            occurencesCount++;
        }
        index++;
    }

    return occurencesCount;
}

char* createNewArray (char* array) {


    int dynamicSize = 1;



    int index = 0;
    while (array[index] != '\0') {
        if (occurences(array, index) == 1) {
            dynamicSize++;
        }
        index++;
    }

    char *newArray = new char[dynamicSize];

    index = 0;
    int newIndex = 0;
    while (array[index] != '\0') {
        if (occurences(array, index) == 1) {
            newArray[newIndex] = array[index];
            newIndex++;
        }
        index++;
    }

    newArray[dynamicSize-1] = '\0';
    return newArray;
}


int main() {

    char array[] = "akalhk3g#5ggkkks";

    char* shortArray = createNewArray(array);

    for (int i=0; shortArray[i] != '\0'; i++) {
        std::cout << shortArray[i];
    }

    delete[] shortArray;
    shortArray = nullptr;


}
