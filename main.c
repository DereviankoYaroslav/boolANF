#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int raiseToPower(int num, int pow);

int *valueToBinary(int i, int rank);

int *elemsForN(int size);

int *binaryElements(int *arr, int size, int count);

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t);

int *toANF(const int *func, int size);

int HammingWeight(const int *function, int size);

int funcIsBalanced(int weight, int pow);

int algebraicDeg(const int *func, int size, int count);

int HammingDistance(const int *func1, const int *func2, int size);

int funcsIsEqual(const int *func1, const int *func2, int size);

int NLinearity(int *func, int size, int count);

int *toPolarTable(const int *function, int size);

int myModulus(int number, int mod);

int *HadamardCoefficients(const int *func, int size, int count);

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

int *linearFunctions(int size, int count, int t);

int *arrayAdd(const int *arr1, int size1, const int *arr2, int size2);

int *improvementSet(const int func[], const int *linearFunctions, int size, int linearMassSize, int WHTPlusSize);

int *HillClimbing(const int f[], const int *improvementSet, int size, int count);

int *roundableHillClimbing(const int f[], int size, int count);

int main(__attribute__((unused)) int args, __attribute__((unused)) char **argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 3;
    /*printf("Enter N:");
    scan f("%d",&n);
    printf("N = %d",n);*/
    int size = raiseToPower(2, n);
    int *binElems = elemsForN(size);
    int f[] = {0,0,1,0,0,1,1,0};
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

    /*for (int i = 0; i < n; ++i) {
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
            //printf("%d ", ar2[i]);
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
    int flag = funcIsBalanced(weight, n);


    int dec = algebraicDeg(f, size, n);
    printf("\n\nALGEBRAIC DEGREE = %d ", dec);

    printf("\n");

    /*int fun1[] = {0, 0, 1, 1};
    int fun2[] = {0, 1, 0, 0};

    int dist = HammingDistance(fun1, fun2, 4);
    printf("\nHD = %d ", dist);*/

    int fun11[] = {1, 1, 1, 1};
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

    /*n = 8;
    size = raiseToPower(2,n);
    int fx[size];

    srand ( time(NULL) );

    for (int i = 0; i < size; ++i){
        fx[i] = rand() % 2;
    }

    printf("\nMY FUNCTION 2^8");
    printf("\n");
    for (int i = 0; i < size; ++i){
        printf("%d, ", fx[i]);
    }
    printf("\n");*/

    //int fx[] = {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};
    //int fx[] = {1,0,1,1};
    //int fx[] = {1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0};
    /*int fx[] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1,
                0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1,
                0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
                0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0,
                1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1,
                1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0};*/
    /*printf("\nTRUTH TABLE");
    printf("\n");
    //size = 256;
    //size = 16;
    //n = 4;
    //size = 4;
    //n = 2;
    //n = 8;
    for (int i = 0; i < size; ++i) {
        printf("%d ", fx[i]);
    }
    int *fxarr = HadamardCoefficients(fx, size, n);
    printf("\nHADAMARD COEFFICIENTS");
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", fxarr[i]);
    }
    int max1 = HadamardMax(fxarr, size);
    //printf("\n max = %d", max1);
    int nl2 = HadamardNLinearity(max1, n);
    printf("\n");
    printf("\nHADAMARD NON LINEARITY = %d", nl2);
    printf("\n");

    int sizeWHT1P = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == max1) {
            sizeWHT1P++;
        }
    }

    printf("\nW1 PLUS");
    printf("\n");
    int *WHT1Plus = WHT1PlusSet(fxarr, size, sizeWHT1P, max1);
    if (WHT1Plus) {
        for (int i = 0; i < sizeWHT1P; ++i) {
            printf("%d ", WHT1Plus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    int sizeWHT1M = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == -max1) {
            sizeWHT1M++;
        }
    }

    printf("\nW1 MINUS");
    printf("\n");
    int *WHT1Minus = WHT1MinusSet(fxarr, size, sizeWHT1M, max1);
    if (WHT1Minus) {
        for (int i = 0; i < sizeWHT1M; ++i) {
            printf("%d ", WHT1Minus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    int sizeWHT2P = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == (max1 - 2)) {
            sizeWHT2P++;
        }
    }

    printf("\nW2 PLUS");
    printf("\n");
    int *WHT2Plus = WHT2PlusSet(fxarr, size, sizeWHT2P, max1);
    if (WHT2Plus) {
        for (int i = 0; i < sizeWHT2P; ++i) {
            printf("%d ", WHT2Plus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    int sizeWHT2M = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == (max1 - 2)) {
            sizeWHT2M++;
        }
    }

    printf("\nW2 MINUS");
    printf("\n");
    int *WHT2Minus = WHT2MinusSet(fxarr, size, sizeWHT2M, max1);
    if (WHT2Minus) {
        for (int i = 0; i < sizeWHT2M; ++i) {
            printf("%d ", WHT2Minus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");

    // Отримання об'єднання WHT1P та WHT2P
    if (!WHT1Plus && !WHT2Plus) {
        printf("SET WHT PLUS IS NULL");
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

    // Отримання об'єднання WHT1M та WHT2M
    if (!WHT1Minus && !WHT2Minus) {
        printf("\nSET WHT MINUS IS NULL");
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


    int c1[(sizeWHT1P + sizeWHT2P)];
    int c2[(sizeWHT1M + sizeWHT2M)];
    int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
    int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);


    int linearMassSize = m1 + m2;


    int *c = arrayAdd(c1, m1, c2, m2);
    //printf("Linear mass size %d ", linearMassSize);
    printf("\nOMEGA LINEAR FUNCTIONS TO FIND");
    printf("\n");
    for (int i = 0; i < linearMassSize; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");

    int *linearFunctionsMass = calloc(linearMassSize * 16, sizeof(int));
    for (int i = 0; i < linearMassSize; ++i) {
        int t = c[i];
        int *arr = linearFunctions(size, n, t);
        for (int j = 0; j < size; ++j) {
            //printf("%d ", arr[j]);
            linearFunctionsMass[i * size + j] = arr[j];
            //printf("%d ", linearFunctionsMass[j]);
        }
    }

    printf("\nLINEAR FUNCTIONS");
    printf("\n");

    for (int i = 0; i < linearMassSize; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", linearFunctionsMass[i * size + j]);
        }
        printf("\n");
    }


    printf("\nIMPROVEMENT SET:");
    int *ar8 = improvementSet(fx, linearFunctionsMass, size, linearMassSize, m1);
    printf("\n");
    for (int j = 0; j < size; ++j) {
        printf("%d ", ar8[j]);
    }

    printf("\n");*/


    //HillClimbing(fx, ar8, size, n);

    //n = 2;
    //size = raiseToPower(2,n);

    //int fx2[] = {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};

    //int fx2[] = {1,0,1,1};

    n = 8;
    size = raiseToPower(2,n);
    int fx2[size];

    srand ( time(NULL) );

    for (int i = 0; i < size; ++i){
        fx2[i] = rand() % 2;
    }

    printf("\nMY FUNCTION 2^8");
    printf("\n");
    for (int i = 0; i < size; ++i){
        printf("%d, ", fx2[i]);
    }
    printf("\n");

    int *ar9 = roundableHillClimbing(fx2, size, n);

    /*if (ar9 != NULL) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar9[j]);
        }
    } else {
        printf("\nIMPROVEMENT SET:");
    }*/




    free(binElems);
    free(ar);
    free(ar3);
    free(ar4);
    free(ar5);
    free(ar6);
    //free(fxarr);
    //free(WHT1Plus);
    //free(WHT2Plus);
    //free(WHT1Minus);
    //free(WHT2Minus);
    //free(ar7);
    //free(ar8);
    //free(ar9);

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

int funcIsBalanced(int weight, int pow) {
    int flag = 1;
    if (weight == raiseToPower(2, pow - 1)) {
        printf("\nFunction is BALANCED!");
        return flag;
    } else {
        printf("\nFunction is NOT BALANCED!");
        int flag = 0;
        return flag;
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
    int minimumNL1;
    int minimumNL2;
    int matrixColumns = size;
    int matrixRows = raiseToPower(2, matrixColumns);
    int *functions = calloc(matrixRows * matrixColumns, sizeof(int));
    int *functions2 = elemsForN(matrixRows);
    int *testfunc = calloc(size,sizeof(int));
    /*for (int i = 0; i < matrixRows; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    //printf("\n");
    for (int i = 0; i < matrixRows; ++i) {
        int *bin = valueToBinary(functions2[i], matrixColumns);
        for (int j = 0; j < matrixColumns; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            functions[i * matrixColumns + j] = bin[j];
            //printf(" %d",functions [i * matrixColumns + j]);
        }
        //printf("\n");
    }
    //minimumNL = HammingDistance(func, functions, size);
    minimumNL1 = HammingDistance(func, functions, size);
    int *bin = valueToBinary(matrixRows-1, matrixColumns);
    for (int j = 0; j < matrixColumns; ++j) {
        testfunc[j] = bin[j];
    }
    /*for (int i = 0; i < size; ++i) {
        printf(" %d",testfunc[i]);
    }*/
    //printf(" %d",minimumNL1);
    minimumNL2 = HammingDistance(func, testfunc, size);
    minimumNL = minimumNL1;
    if (minimumNL2 < minimumNL1){
        minimumNL = minimumNL2;
    }
    for (int i = 0; i < matrixRows; ++i) {
        if (algebraicDeg(functions + matrixColumns * i, size, count) <= 1 &&
            !funcsIsEqual(func, functions + matrixColumns * i, size)) {
            int newMinHD = HammingDistance(func, functions + matrixColumns * i, matrixColumns);
            //printf(" NEW MIDHD%d",newMinHD);
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

int *HadamardCoefficients(const int *func, int size, int count) {
    int *result = calloc(size, sizeof(int));
    int *test = calloc(size * count, sizeof(int));
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
    int maxCoefficient = abs(arr[0]);
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i] > maxCoefficient)) {
            maxCoefficient = abs(arr[i]);
        }
    }
    //printf("max coef %d", maxCoefficient);
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

//Функція визначення множини W1+

int *WHT1PlusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == max) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція визначення множини W1-

int *WHT1MinusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == -max) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція визначення множини W2+

int *WHT2PlusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == (max - 2)) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція визначення множини W2-

int *WHT2MinusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == -(max - 2)) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція виконання операції "об'єднання" над масивами

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]) {
    int n = 0, i = 0, j = 0;

    while ((i < n1) && (j < n2)) {
        if (a[i] < b[j])
            c[n++] = a[i++];
        else if (a[i] > b[j])
            c[n++] = b[j++];
        else {
            c[n++] = a[i++];
            ++j;
        }
    }

    while (i < n1)
        c[n++] = a[i++];
    while (j < n2)
        c[n++] = b[j++];
    return n;
}

//Функція обчислення лінійної функції для заданого омега

int *linearFunctions(int size, int count, int t) {
    int calc1 = 0;
    int calc2 = 0;
    int sum = 0;
    int *binElems = elemsForN(size);
    int *ar = binaryElements(binElems, size, count);
    int *bin = valueToBinary(t, count);
    /*for (int i = 0; i < count; ++i) {
        printf("%d ", bin[i]);
    }*/
    //printf("\n");
    int *result = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        for (int i = 0, k = count - 1; i < count, k >= 0; ++i, --k) {
            calc1 = ar[i * size + j] * bin[k];
            //printf("%d ", bin[k]);
            //printf("%d ", calc1);
            sum = sum ^ calc1;
            //printf("%d ", sum);
        }
        //printf("%d ", sum);
        result[j] = sum;
        sum = 0;
        //printf("\n");
    }
    return result;
}

//Функція з'єднання двох масивів

int *arrayAdd(const int *arr1, int size1, const int *arr2, int size2) {
    int linearMassSize = size1 + size2;
    int *result = calloc(linearMassSize, sizeof(int));
    for (int i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }
    if (size2 != 0) {
        for (int j = 0; j < size2; ++j) {
            result[j + size1] = arr2[j];
        }
    }
    return result;
}

//Функція знаходження набору покращень

int *improvementSet(const int func[], const int *linearFunctions, int size, int linearMassSize, int WHTPlusSize) {
    int counter = 0;
    int k = 0;
    int flag = 1;
    int *result = calloc(size, sizeof(int));
    int *result1 = calloc(size, sizeof(int));
    int *result2 = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < WHTPlusSize; ++i) {
            if ((func[j] == linearFunctions[i * size + j])) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        //printf("flag %d ", flag);
        if (flag == 1) {
            result1[j] = 1;
        } else {
            result1[j] = 0;
        }

    }
    /*for (int j = 0; j < size; ++j) {
        printf("%d ", result1[j]);
    }*/
    if (WHTPlusSize < linearMassSize) {
        for (int j = 0; j < size; ++j) {
            for (int i = WHTPlusSize; i < linearMassSize; ++i) {
                if ((func[j] != linearFunctions[i * size + j])) {
                    flag = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
            //printf("flag %d ", flag);
            if (flag == 1) {
                result2[j] = 1;
            } else {
                result2[j] = 0;
            }

        }
        /*for (int j = 0; j < size; ++j) {
            printf("%d ", result2[j]);
        }*/
        for (int j = 0; j < size; ++j) {
            if ((result1[j] == 1) && (result2[j] == 1) && (result1[j] == result2[j])) {
                result[j] = 1;
            } else {
                result[j] = 0;
            }
        }
    } else {
        for (int j = 0; j < size; ++j) {
            result[j] = result1[j];
        }
    }
    for (int j = 0; j < size; ++j) {
        if (result[j] == 1){
            counter++;
        }
    }
    if (counter == 0){
        printf("\nIMPROVEMENT IS UNAVAILABLE");
    }

    return result;
}

//Функція підвищення нелінійності методом Градієнтного Підйому

int *HillClimbing(const int f[], const int *improvementSet, int size, int count) {
    int *ftemp = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ftemp[j] = f[j];
        }
        if (improvementSet[i] == 1) {
            if (ftemp[i] == 0) {
                ftemp[i] = 1;
            } else {
                ftemp[i] = 0;
            }
            printf("\n|---------------------------------|");
            printf("\nCHANGED COEFFICIENT NUMBER %d ", i);
            printf("\n");
            printf("\nNEW TRUTH TABLE");
            printf("\n");
            for (int k = 0; k < size; ++k) {
                printf("%d ", ftemp[k]);
            }
            int *farr = HadamardCoefficients(ftemp, size, count);
            printf("\nNEW HADAMARD COEFFICIENTS");
            printf("\n");
            for (int l = 0; l < size; ++l) {
                printf("%d ", farr[l]);
            }
            int max = HadamardMax(farr, size);
            //printf("\n max = %d", max);
            int nl = HadamardNLinearity(max, count);
            printf("\n");
            printf("\nNEW HADAMARD NON LINEARITY = %d", nl);
            printf("\n");
            return ftemp;
            break;
        }
    }
}

int *roundableHillClimbing(const int f[], int size, int count){
        int weight;
        weight = HammingWeight(f, size);
        int flag = funcIsBalanced(weight, count);
        printf("\n");
        printf("\nTRUTH TABLE");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", f[i]);
        }
        int *fxarr = HadamardCoefficients(f, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", fxarr[i]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");

        int sizeWHT1P = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == max1) {
                sizeWHT1P++;
            }
        }

        printf("\nW1 PLUS");
        printf("\n");
        int *WHT1Plus = WHT1PlusSet(fxarr, size, sizeWHT1P, max1);
        if (WHT1Plus) {
            for (int i = 0; i < sizeWHT1P; ++i) {
                printf("%d ", WHT1Plus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT1M = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == -max1) {
                sizeWHT1M++;
            }
        }

        printf("\nW1 MINUS");
        printf("\n");
        int *WHT1Minus = WHT1MinusSet(fxarr, size, sizeWHT1M, max1);
        if (WHT1Minus) {
            for (int i = 0; i < sizeWHT1M; ++i) {
                printf("%d ", WHT1Minus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT2P = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == (max1 - 2)) {
                sizeWHT2P++;
            }
        }

        printf("\nW2 PLUS");
        printf("\n");
        int *WHT2Plus = WHT2PlusSet(fxarr, size, sizeWHT2P, max1);
        if (WHT2Plus) {
            for (int i = 0; i < sizeWHT2P; ++i) {
                printf("%d ", WHT2Plus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT2M = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == (max1 - 2)) {
                sizeWHT2M++;
            }
        }

        printf("\nW2 MINUS");
        printf("\n");
        int *WHT2Minus = WHT2MinusSet(fxarr, size, sizeWHT2M, max1);
        if (WHT2Minus) {
            for (int i = 0; i < sizeWHT2M; ++i) {
                printf("%d ", WHT2Minus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        // Отримання об'єднання WHT1P та WHT2P
        if (!WHT1Plus && !WHT2Plus) {
            printf("SET WHT PLUS IS NULL");
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

        // Отримання об'єднання WHT1M та WHT2M
        if (!WHT1Minus && !WHT2Minus) {
            printf("\nSET WHT MINUS IS NULL");
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

        /*int *ar7 = linearFunctions(size, n, 5);
        printf("\nLINEAR FUNCTION");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", ar7[i]);
        }
        printf("\n");*/

        int c1[(sizeWHT1P + sizeWHT2P)];
        int c2[(sizeWHT1M + sizeWHT2M)];
        int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
        int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);

        //printf("%d ", m1);
        //printf("%d ", m2);

        int linearMassSize = m1 + m2;
        /*int c3[1] = {7};
        int c[linearMassSize];
        for (int i = 0; i < m1; ++i) {
                c[i] = c1[i];
        }
        if (m2!=0) {
            for (int j = 0; j < m2; ++j) {
                c[j + m1] = c3[j];
            }
        }*/

        int *c = arrayAdd(c1, m1, c2, m2);
        printf("Linear mass size %d ", linearMassSize);
        printf("\nOMEGA LINEAR FUNCTIONS TO FIND");
        printf("\n");
        for (int i = 0; i < linearMassSize; ++i) {
            printf("%d ", c[i]);
        }
        printf("\n");

        int *linearFunctionsMass = calloc(linearMassSize * 16, sizeof(int));
        for (int i = 0; i < linearMassSize; ++i) {
            int t = c[i];
            int *arr = linearFunctions(size, count, t);
            for (int j = 0; j < size; ++j) {
                //printf("%d ", arr[j]);
                linearFunctionsMass[i * size + j] = arr[j];
                printf("%d ", linearFunctionsMass[j]);
            }
        }

        printf("\nLINEAR FUNCTIONS");
        printf("\n");

        for (int i = 0; i < linearMassSize; ++i) {
            for (int j = 0; j < size; ++j) {
                printf("%d ", linearFunctionsMass[i * size + j]);
            }
            printf("\n");
        }


        printf("\nIMPROVEMENT SET:");
        int *ar8 = improvementSet(f, linearFunctionsMass, size, linearMassSize, m1);
        int k;
        printf("\n");
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar8[j]);
        }

        int *ar9 = HillClimbing(f, ar8, size, count);
        printf("\n");
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar9[j]);
        }

    return ar9;
    free(fxarr);
    free(WHT1Plus);
    free(WHT2Plus);
    free(WHT1Minus);
    free(WHT2Minus);
    free(ar8);
    free(ar9);
}



