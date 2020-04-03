/*1.Given a no. ‘n’, find posible no. of smart strings and input alphabet is a to z(26 chars).
Smart string means a string after applying following changes, resulting string is same as the original
string. smart string: given a string of size n, reverse it and again reverse it excluding the end chars 
at position 1 and n. Now again reverse it excluding next to end chars at 2 and n-1. continue this till 
you reach middle of string. eg. consider string “abcdcea”, aftet 1st reverse: “a ecdcb a”, after 2nd reverse: 
“ab cdc ea”, after 3rd reverse : “abc d cea”. now we reached middle of string and resulting string is same as
original string. so it is smart. after analysing the pattern i got the solution for this.*/

/*let's take the index of the chars of the string and check how they are changing
 even length : 1 2 3 4 5 6 =>  6 5 4 3 2 1 => 6 2 3 4 5 1 => 6 2 4 3 5 1
 observe that the chars at even positions remain at their initial positions, only the chars at odd positions have changed.
 this means that at even positions we can put any char from a to z, but at odd positons lets say x, 
 we can put 26 chars at x but only one char at n-x 

 sa, if n is even : total smart string possible = (n/2 + n/4) * 26  
  	  if n is odd : total smart string possible = (n/2 + 1 + n/4) * 26    */