/*
 * Simulates the operation of a vending machine by creating an operation
 * that receives money (array of coins) and a number that indicates the selection
 * of the product.
 * - The program will return the name of the product and an array with the money
 * back (with the smallest number of coins).
 * - If the money is insufficient or the product number does not exist,
 * must be indicated with a message and return all coins.
 * - If there is no money returned, the array will be returned empty.
 * - To make it simpler, we will work in cents with coins
 * of 5, 10, 50, 100 and 200.
 * - We must control that the currencies sent are within those supported.
 */