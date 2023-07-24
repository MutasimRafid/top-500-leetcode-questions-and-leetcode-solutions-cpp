solution but TLE, but important(3 approaches): https://youtu.be/DhFh8Kw7ymk
Solution but no TLE(4th approaches): https://youtu.be/TeegtfmEhTY
​
**code is not from video****: **disscuss section**
Approach for this Problem:
Sort the input array
1.Initialize a set to store the unique triplets and an output vector to store the final result
2.Iterate through the array with a variable i, starting from index 0.
3.Initialize two pointers, j and k, with j starting at i+1 and k starting at the end of the array.
4.In the while loop, check if the sum of nums[i], nums[j], and nums[k] is equal to 0. If it is, insert the triplet into the set and increment j and decrement k to move the pointers.
5.If the sum is less than 0, increment j. If the sum is greater than 0, decrement k.
6.After the while loop, iterate through the set and add each triplet to the output vector.
Return the output vector
​