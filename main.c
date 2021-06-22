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

int *autoCorrelation(int *func, int size, int count);

int autoCorrelationMax(const int *arr, int size);

int expansionCriterion(const int *func, int size, int k);

int *WHT1PlusSet(const int *func, int size, int newSize, int max);

int *WHT1MinusSet(const int *func, int size, int newSize, int max);

int *WHT2PlusSet(const int *func, int size, int newSize, int max);

int *WHT2MinusSet(const int *func, int size, int newSize, int max);

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]);

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
        printf("%d ", polFunc[i]);
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

    int fun22[] = {1, 0, 1, 1};

    int *ar6 = autoCorrelation(fun22, 4, 2);

    printf("\nAUTO CORRELATING FUNCTION");
    printf("\n");
    for (int i = 3; i >= 0; i--) {
        printf("%d ", ar6[i]);
    }
    printf("\n");

    int AC = autoCorrelationMax(ar6, 4);
    printf("\nAUTO CORRELATION = %d", AC);
    printf("\n");

    int ec = expansionCriterion(fun22, 4, 1);
    printf("\n");
    printf("\nW = %d", ec);
    printf("\n");

    int fx[] = {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};
    printf("\nTRUTH TABLE");
    printf("\n");
    for (int i = 0; i < 16; ++i) {
        printf("%d ", fx[i]);
    }
    int *fxarr = HadamardCoefficients(fx, 16, 4);
    printf("\nHADAMARD COEFFICIENTS");
    printf("\n");
    for (int i = 0; i < 16; ++i) {
        printf("%d ", fxarr[i]);
    }
    int max1 = HadamardMax(fxarr, 16);
    //printf("\n max = %d", max);
    int nl2 = HadamardNLinearity(max1, 4);
    printf("\n");
    printf("\nHADAMARD NON LINEARITY = %d", nl2);
    printf("\n");

    int sizeWHT1P = 0;
    for (int i = 0; i<16; ++i){
        if (fxarr [i] == max1){
            sizeWHT1P++;
        }
    }

    printf("\nW1 PLUS");
    printf("\n");
    int *WHT1Plus = WHT1PlusSet(fxarr,16,sizeWHT1P,max1);
    if (WHT1Plus) {
        for (int i = 0; i < sizeWHT1P; ++i) {
            printf("%d ", WHT1Plus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    int sizeWHT1M = 0;
    for (int i = 0; i<16; ++i){
        if (fxarr [i] == -max1){
            sizeWHT1M++;
        }
    }

    printf("\nW1 MINUS");
    printf("\n");
    int *WHT1Minus = WHT1MinusSet(fxarr,16,sizeWHT1M,max1);
    if (WHT1Minus) {
        for (int i = 0; i < sizeWHT1M; ++i) {
            printf("%d ", WHT1Minus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    int sizeWHT2P = 0;
    for (int i = 0; i<16; ++i){
        if (fxarr [i] == (max1-2)){
            sizeWHT2P++;
        }
    }

    printf("\nW2 PLUS");
    printf("\n");
    int *WHT2Plus = WHT2PlusSet(fxarr,16,sizeWHT2P,max1);
    if (WHT2Plus) {
        for (int i = 0; i < sizeWHT2P; ++i) {
            printf("%d ", WHT2Plus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    int sizeWHT2M = 0;
    for (int i = 0; i<16; ++i){
        if (fxarr [i] == (max1-2)){
            sizeWHT2M++;
        }
    }

    printf("\nW2 MINUS");
    printf("\n");
    int *WHT2Minus = WHT2MinusSet(fxarr,16,sizeWHT2M,max1);
    if (WHT2Minus) {
        for (int i = 0; i < sizeWHT2M; ++i) {
            printf("%d ", WHT2Minus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    // Отримання об'єднання WHT1P та WHT2P
    if (!WHT1Plus && !WHT2Plus)
    {
        printf("SET IS NULL");
    } else {
        int c1[(sizeWHT1P + sizeWHT2P)];
        //printf("%d ", (sizeWHT1P + sizeWHT1P));

        int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
        printf("\nSET WHT PLUS");
        printf("\n");
        for (int i = 0; i < m1; ++i) {
            printf("%d ", c1[i]);
        }
    }

    printf("\n");
    printf("\n");

    // Отримання об'єднання WHT1M та WHT2M
    if (!WHT1Minus && !WHT2Minus)
    {
        printf("SET WHT MINUS IS NULL");
    } else {
        int c2[(sizeWHT1M + sizeWHT2M)];
        //printf("%d ", (sizeWHT1P + sizeWHT1P));

        int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);
        printf("\nSET WHT MINUS");
        printf("\n");
        for (int i = 0; i < m2; ++i) {
            printf("%d ", c2[i]);
        }
    }

    printf("\n");

    free(binElems);
    free(ar);
    free(ar3);
    free(ar4);
    free(ar5);
    free(ar6);
    free(fxarr);
    free(WHT1Plus);
    free(WHT2Plus);
    free(WHT1Minus);
    free(WHT2Minus);

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
    int *test = calloc(size*count, sizeof(int));
    int *functions2 = elemsForN(size);
    /*for (int i = 0; i < size; ++i) {
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

//Функція обчислення автокореляційної функції

int *autoCorrelation(int *func, int size, int count) {
    int *acFunc = calloc(size, sizeof(int));
    int *polFunc = toPolarTable(func, size);
    acFunc[0] = raiseToPower(2, count);
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int temp = polFunc[j] * polFunc[j ^ i];
            //printf("j^i = %d", j^i);
            acFunc[i] = acFunc[i] + temp;
        }
        //printf("ac i = %d", acFunc[i]);
    }
    return acFunc;
}

//Функція обчислення автокореляції з функції автокореляції

int autoCorrelationMax(const int *arr, int size) {
    int maxCoefficient = arr[1];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxCoefficient) {
            maxCoefficient = arr[i];
        }
    }
    return maxCoefficient;
}

//Функція визначення відповідності критеріям

int expansionCriterion(const int *func, int size, int k) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += func[i] ^ func[i ^ k];
    }
    if (result == size / 2) {
        printf("\nComply with Criterion KP(%d)", k);
    } else {
        printf("\nNot comply with Criterion KP(%d)", k);
    }
    return result;
}

int *WHT1PlusSet(const int *func, int size, int newSize, int max){
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j<size; ++j){
            if (func[j] == max){
                result[k]= j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

int *WHT1MinusSet(const int *func, int size, int newSize, int max){
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j<size; ++j){
            if (func[j] == -max){
                result[k]= j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

int *WHT2PlusSet(const int *func, int size, int newSize, int max){
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j<size; ++j){
            if (func[j] == (max-2)){
                result[k]= j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

int *WHT2MinusSet(const int *func, int size, int newSize, int max){
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j<size; ++j){
            if (func[j] == -(max-2)){
                result[k]= j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]){
    int n = 0, i = 0, j = 0;

    while((i < n1) && (j < n2)){
        if(a[i] < b[j])
            c[n++] = a[i++];
        else if(a[i] > b[j])
            c[n++] = b[j++];
        else {
            c[n++] = a[i++];
            ++j;
        }
    }

    while(i < n1)
        c[n++] = a[i++];
    while(j < n2)
        c[n++] = b[j++];
    return n;
}


