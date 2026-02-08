// 1. Напишете функция, която приема символен низ и връща сумата на всички числа в него.

//    Вход	            Изход
//    ab37c10x	        47

#include <iostream>

bool isDigit (char *current) {
    if (*current >= '0' && *current <= '9') {
        return true;
    }
    return false;
}

/*int conv (char *current, int sum) {

    if (*current == '\0') {
        return sum;
    }

    sum = sum*10 + (*current - '0');
    return conv(current+1, sum);
}*/

// ab37c10x - 47       5\0   37abc10x
// 215 \0           (*curr, 0)

int summer (char *array, int currentSum, int totalSum) {            // ab37c10x    a 0 0

    if (*array == '\0') {
        return totalSum + currentSum;
    }

    if (!(isDigit(array))) {
        return summer(array+1, 0, totalSum + currentSum);
    }

    currentSum = currentSum*10 + (*array - '0');
    return summer(array + 1, currentSum, totalSum);

}


int main() {

    char arr[] = "ab37c10";
    std::cout << summer(arr, 0, 0);

}
