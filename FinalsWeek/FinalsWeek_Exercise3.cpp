//Напишете функция, която приема като аргумент символен низ и връща броя на точните квадрати сред числата, записани в него.
//
// Вход: abc16fg20h9 -> Изход: 2 (числата са 16 и 9)
// Вход: test2test4test25 -> Изход: 2 (числата са 4 и 25)


// * Правим булева функция, която проверява дали едно число е точен квадрат isCube
// * Правим функция bool isDigit (char *arr), която проверява дали един елемент е цифра

/*  1. Приемаме низ, текущa сума, точни квадрати    int cubeCounter (char *str, int currSum, int cubeCount)
 *
 *  Ако (*str == '\0') { return cubeCount; }
 *  Ако !(isDigit(str)) { }
 *
 *
 *
 */

bool isDigit (char* array) {
    if (*array >= '0' && *array <= '9') {
        return true;
    }
    return false;
}

bool isCube (int number) {
    int counter = 0;
    int middle = number/2;


    for (int i=1; i<=middle; i++) {
        if (i*i == number) return true;
        if (i*i > number) return false;
    }
}

int cubeCounter (char *str, int currSum, int cubeCount) {           // test2test4test25

    if (*str == '\0') {
        if (isCube(currSum)) {
            return cubeCount + 1;
        }

        return cubeCount;
    }

    if (!(isDigit(str))) {

        if (isCube(currSum)) {
            return cubeCounter (str+1, 0, cubeCount + 1);
        }

        return cubeCounter (str+1, 0, cubeCount);
    }

    currSum = currSum*10 + (*str - '0');
    return cubeCounter(str+1, currSum, cubeCount);

}


#include <iostream>

int main() {

    char arr[] = "abc16fg20h9h16";

    std::cout << cubeCounter(arr, 0, 0);

}
