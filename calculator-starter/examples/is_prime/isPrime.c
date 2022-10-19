int checkPrime(int number) {
    int isPrime = 1;
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}
