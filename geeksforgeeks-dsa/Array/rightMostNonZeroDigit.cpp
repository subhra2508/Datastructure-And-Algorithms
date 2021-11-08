int rightmostNonZero(int a[], int n)
{
    // To store the count of times 5 can
    // divide the array elements
    int c5 = 0;
 
    // Divide the array elements by 5
    // as much as possible
    for (int i = 0; i < n; i++) {
        while (a[i] > 0 && a[i] % 5 == 0) {
            a[i] /= 5;
            // increase count of 5
            c5++;
        }
    }
 
    // Divide the array elements by
    // 2 as much as possible
    for (int i = 0; i < n; i++) {
        while (c5 && a[i] > 0 && !(a[i] & 1)) {
            a[i] >>= 1;
 
            // Decrease count of 5, because a '2' and
            // a '5' makes a number with last digit '0'
            c5--;
        }
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * a[i] % 10) % 10;
    }
 
    // If c5 is more than the multiplier
    // should be taken as 5
    if (c5)
        ans = (ans * 5) % 10;
 
    if (ans)
        return ans;
 
    return -1;
}