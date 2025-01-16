// Chatgpt limk: https://chatgpt.com/share/6788ce44-1014-8004-9344-b23465d7a670

// Left shift (<<) and Right shift (>>) operators

// Left shift (<<) operator multiplies the number by 2 for each shift.
// Like I I write 5 << 2 then 5 * 2^2 = 20
// 5 << 1 = 5 * 2^1 = 10

// Right shift (>>) operator divides the number by 2 for each shift.
// Like I I write 5 >> 2 then 5 / 2^2 = 1
// 5 >> 1 = 5 / 2^1 = 2

// Set the ith bit of a number to 1 using OR operator

// Like I have a number 7 and I want to set the 1st bit to 1
// Formula is: number | (1 << i)
// 5 = 0101
// 1 << 1 = 0010
// 0101 | 0010 = 0111

// Set the ith bit of a number to 0 using AND operator
// Formula is: number & ~(1 << i)
// 7 = 0111
// 1 << 1 = 0010
// 0111 & 1101 = 0101

// Toggle the ith bit of a number using XOR operator and bitmask
// Formula is: number ^ (1 << i)
// 7 = 0111
// 1 << 1 = 0010
// 0111 ^ 0010 = 0101

// Topic of Bitmasking is very important in competitive programming. It is used to solve many problems.

// Check a bit is set or not

// Formula is: number & (1 << i) != 0
// 7 = 0111
// 1 << 1 = 0010
// 0111 & 0010 = 0010 != 0
