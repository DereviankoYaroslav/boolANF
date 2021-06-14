#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int raiseToPower(int num, int pow);

int *valueToBinary(int i, int rank);

int *elemsForN(int size);

int *binaryElements(int *arr, int size, int count);

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t);

int *toANF(const int *func, int size);

int HammingWeight(const int *function, int size);

void funcIsBalanced(int weight, int pow);

int algebraicDeg(const int *func, int size, int count);

int HammingDistance(const int *func1, const int *func2, int size);

int funcsIsEqual(const int *func1, const int *func2, int size);

int NLinearity(int *func, int size, int count);

int *toPolarTable(const int *function, int size);

int myModulus(int number, int mod);

int *HadamardCoefficients(int *func, int size, int count);

int HadamardMax(const int *arr, int size);

int HadamardNLinearity(int max, int count);

int main(__attribute__((unused)) int args, __attribute__((unused)) char **argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 3;
    /*printf("Enter N:");
    scan f("%d",&n);
    printf("N = %d",n);*/
    int size = raiseToPower(2, n);
    int *binElems = elemsForN(size);
    int f[] = {0, 0, 1, 0, 0, 1, 1, 0};
    /*int f[size];
    printf("\n");
    printf("Enter function using 0 and 1:");
    printf("\n");
    for (int i = 0; i < size; ++i){
        printf("Enter f[%d]:",i);
        scan f("%d",&f[i]);
    }*/

    /*for (int i = 0; i < size; ++i) {
        printf("%d ", binElems[i]);
    }*/

    //printf("\nBooleans\n");
    int *ar = binaryElements(binElems, size, n);
    /*
    for (int i = 0; i < n; ++i) {
        printf("x%d = ", i);
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar[i * size + j]);
        }
        printf("\n");
    }*/

    int *ar3 = calloc(size, sizeof(int));
    int modulus = 0;
    for (int t = 0, k = size - 1; t < size; ++t, k--) {
        int *ar2 = massToBooleanFunc(binElems, ar, size, n, t);
        for (int i = 0; i < size; ++i) {
            if (f[i] != 0) {
                //printf("%d ", ar2[i]);
                modulus = modulus ^ ar2[i];
            }
        }
        //printf("modulus = %d ", modulus);
        ar3[k] = modulus;
        modulus = 0;
    }

    printf("\n");
    printf("TRUTH TABLE FOR FUNCTION\n");

    for (int i = 0; i < size; ++i) {
        printf("%d ", ar3[i]);
    }

    printf("\n");
    printf("\n");
    printf("ANF REPRESENTATION\n");
    int *ar4 = toANF(ar3, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", ar4[i]);
    }

    printf("\n");
    printf("\n");

    int weight;
    weight = HammingWeight(ar3, size);
    printf("HAMMING WEIGHT = %d ", weight);
    printf("\n");
    funcIsBalanced(weight, n);


    int dec = algebraicDeg(f, size, n);
    printf("\n\nALGEBRAIC DEGREE = %d ", dec);

    /*int fun1[] = {0, 0, 1, 1};
    int fun2[] = {0, 1, 0, 0};

    int dist = HammingDistance(fun1, fun2, 4);
    printf("\nHD = %d ", dist);*/

    int fun11[] = {1, 0, 1, 1};
    int nel = NLinearity(fun11, 4, 2);
    printf("\nNON LINEARITY (DISTANCE) = %d", nel);

    printf("\n");

    printf("\nPOLAR TABLE");
    printf("\n");
    int *polFunc = toPolarTable(fun11, 4);
    for (int i = 0; i < 4; ++i) {
        printf(" %d", polFunc[i]);
    }

    /*int *result = malloc(8 * sizeof(int));
    int *test = malloc(8 * sizeof(int));
    int *functions2 = elemsForN(8);
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        int *bin = valueToBinary(functions2[i], 3);
        for (int j = 0; j < 3; ++j) {
            //printf(" bin j = %d", bin[j]);
            // *(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            test [i * 3 + j] = bin[j];
            printf(" %d",test [i * 3 + j]);
        }
        printf("\n");
    }
    int *w = malloc(3 * sizeof(int));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            w[j] = test[i * 3 + j];
            printf("w = %d", w[j]);
        }
        int res = 0;
        for (int j = 0; j < 8; ++j) {
            int r = 0;
            for (int k = 0; k < 3; ++k) {
                r += myModulus(w[k] * test[j * 3 + k], 2);
            }
            res += raiseToPower(-1, myModulus(fun11[j] + r, 2));
        }
        result[i] = res;
    }
    for (int i = 0; i < 8; ++i) {
        printf(" = %d", result[i]);
    }*/

    int *ar5 = HadamardCoefficients(fun11, 4, 2);
    /*for (int i = 0; i < 4; ++i) {
        printf(" %d", ar5[i]);
    }*/

    int max = HadamardMax(ar5, 4);
    //printf("\n max = %d", max);

    int nl = HadamardNLinearity(max, 2);
    printf("\nHADAMARD NON LINEARITY = %d", nl);
    printf("\n");

    free(binElems);
    free(ar);
    free(ar3);
    free(ar4);
    free(ar5);

    return 0;
}

//Функція приведення числа за модулем дуякого числа

int myModulus(int number, int mod) {
    if (number < 0) {
        while (number < 0) {
            number = number + mod;
        }
    }
    return number % 2;
}

//Функція перетворення елементів з десяткової СЧ у двійкову СЧ, для певного ступеня N

int *binaryElements(int *arr, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            result[j * size + i] = bin[k];
        }
    }
    return result;
}

//Функція перетворення масиву чисел у двійковій системі до таблиці істиності

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t) {
    int calc;
    int calc2 = 1;
    //printf("\n");
    //printf("t = %d", t);
    //printf("\n");
    int *calculation = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            //printf("\n");
            //printf("bin k = %d", bin[k]);
            //printf("\n");
            //printf("arr2 i = %d", arr2[j*size+t]);
            calc = raiseToPower(arr2[j * size + t], bin[k]);
            //printf("\n");
            //printf("raised to power = %d", calc);
            //printf("%d\n",bin[j]);
            calc2 = calc2 * calc;
            //printf("\n");
            //printf("calc2 = %d", calc2);
            calculation[arr[i]] = calc2;
        }
        calc2 = 1;
        /*for (int r = 0; r<size; ++r){
            if(arr3[r]!=0){
                printf(" rrr %d", calculation[r]);
                calc3 = calc3^calculation[r];
                printf("\n");
                printf("calc3 = %d", calc3);
            }
        }*/
        //printf("\n");
        //printf("calc3 = %d", calc3);
        //printf("\n");
    }
    return calculation;
}

//Функція перетворення числа з десяткової СЧ у двійкову СЧ

int *valueToBinary(int i, int rank) {
    int *res = calloc(rank, sizeof(int));
    for (int j = 0; j < rank; ++j) {
        res[rank - 1 - j] = i >> j & 1;
    }
    return res;
}

//Функція зведення до ступеня

int raiseToPower(int num, int pow) {
    int res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= num;
    }
    return res;
}

//Функція генерації чисел для вхідних векторів ступеня N

int *elemsForN(int size) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = i;
    }
    return result;
}

//Функція переведення з таблиці істиності до АНФ

int *toANF(const int *func, int size) {
    int *matrix = calloc(size * size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        matrix[i] = func[size - 1 - i];
    }
    /*for (int k = 0; k < size; ++k) {
        for (int l = 0; l < size; ++l) {
            printf(" %d", matrix[k*size+l]);
        }
        printf("\n");
    }*/
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            matrix[i * size + j] = (matrix[size * (i - 1) + j] + matrix[size * (i - 1) + (j + 1)]) % 2;
            //printf(" %d", matrix[i * size + j]);
        }
        //printf("\n");
    }
    int *coefficients = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        coefficients[i] = matrix[i * size];
    }
    free(matrix);
    return coefficients;
}

//Функція обчислення ваги Хеммінга

int HammingWeight(const int *function, int size) {
    int weight = 0;
    for (int i = 0; i < size; ++i) {
        if (function[i]) {
            weight++;
        }
    }
    return weight;
}

//Функція визначення збалансованості функції

void funcIsBalanced(int weight, int pow) {
    if (weight == raiseToPower(2, pow - 1)) {
        printf("\nFunction is BALANCED!");
    } else {
        printf("\nFunction is NOT BALANCED!");
    }
}

//Функція визначення алгебраїчного ступеня функції

int algebraicDeg(const int *func, int size, int count) {
    int result;
    int flag = 0;
    int k = 0;
    int highestDec;
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (func[i]) {
            newSize++;
        }
    }
    //printf("\n newSize  = %d",newSize);
    int *deg = calloc(newSize, sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (func[i]) {
            //printf("\ni = %d",i);
            int *bin = valueToBinary(i, count);
            for (int j = 0; j < count; ++j) {
                if (bin[j] == 1) {
                    ++flag;
                }
            }
            deg[k] = flag;
            //printf("\n deg k  = %d",deg[k]);
            flag = 0;
            ++k;
        }
    }
    highestDec = deg[0];
    for (int l = 0; l < newSize; ++l) {
        if (deg[l] > highestDec) {
            highestDec = deg[l];
        }
    }
    //printf("\nH deg   = %d",highestDec);
    result = highestDec;
    return result;
}

//Функція визначення відстані Хемінга

int HammingDistance(const int *func1, const int *func2, int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) {
        if ((func1[i] ^ func2[i]) != 0) res++;
    }
    return res;
}

//Функція визначення рівності між функціями

int funcsIsEqual(const int *func1, const int *func2, int size) {
    int flag = 0;
    for (int i = 0; i < size; ++i) {
        if (func1[i] == func2[i]) {
            flag++;
        }
    }
    return flag == size;
}

//Функція визначення нелінійності функції

int NLinearity(int *func, int size, int count) {
    int minimumNL;
    int matrixColumns = size;
    int matrixRows = raiseToPower(2, matrixColumns);
    int *functions = calloc(matrixRows * matrixColumns, sizeof(int));
    int *functions2 = elemsForN(matrixRows);
    /*for (int i = 0; i < rows; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    printf("\n");
    for (int i = 0; i < matrixRows; ++i) {
        int *bin = valueToBinary(functions2[i], matrixColumns);
        for (int j = 0; j < matrixColumns; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            functions[i * matrixColumns + j] = bin[j];
            //printf(" %d",functions [i * cols + j]);
        }
        //printf("\n");
    }
    minimumNL = HammingDistance(func, functions, size);
    for (int i = 0; i < matrixRows; ++i) {
        if (algebraicDeg(functions + matrixColumns * i, size, count) <= 1 &&
            !funcsIsEqual(func, functions + matrixColumns * i, size)) {
            int newMinHD = HammingDistance(func, functions + matrixColumns * i, matrixColumns);
            if (newMinHD < minimumNL) {
                minimumNL = newMinHD;
            }
        }
    }
    int result = minimumNL;
    return result;
}

//Функція представлення таблиці істиності в полярному вигляді

int *toPolarTable(const int *function, int size) {
    int *res = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        res[i] = raiseToPower(-1, function[i]);
    }
    return res;
}

//Функція визначення коефіцієнтів перетворення Уолдша-Адамара

int *HadamardCoefficients(int *func, int size, int count) {
    int *result = calloc(size, sizeof(int));
    int *test = calloc(size, sizeof(int));
    int *functions2 = elemsForN(size);
    /*for (int i = 0; i < rows; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    printf("\n");
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(functions2[i], count);
        for (int j = 0; j < count; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            test[i * count + j] = bin[j];
            //printf(" %d",test [i * count + j]);
        }
        //printf("\n");
    }
    int *w = calloc(count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < count; ++j) {
            w[j] = test[i * count + j];
            //printf("w = %d", w[j]);
        }
        int res = 0;
        for (int j = 0; j < size; ++j) {
            int r = 0;
            for (int k = 0; k < count; ++k) {
                r += myModulus(w[k] * test[j * count + k], 2);
            }
            res += raiseToPower(-1, myModulus(func[j] + r, 2));
        }
        result[i] = res;
    }
    return result;
}

//Функція визначення найбільшого коефіцієнта перетворення Уолдша-Адамара

int HadamardMax(const int *arr, int size) {
    int maxCoefficient = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] > maxCoefficient) {
            maxCoefficient = arr[i];
        }
    }
    return maxCoefficient;
}

//Функція визначення нелінійності функції через коефіцієнти Уолдша-Адамара

int HadamardNLinearity(int max, int count) {
    int nl = (raiseToPower(2, count) - max) / 2;
    return nl;
}

