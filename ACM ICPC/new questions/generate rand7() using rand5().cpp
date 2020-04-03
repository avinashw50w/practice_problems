/*As an interview question, this is a terrible one. I don't like this question at all. That being said, there are three concepts, 
that once you understand will solve any question in this pattern.

Concept 1: Rolling again
Imagine you have a single six sided dice. If I wanted you to get "Heads or Tails" based on this dice, you can roll it, 
and if you get 1, say heads, if you get 2, say tails, and if you get anything else roll again. This approach will guarantee 
an equiprobable H/T, but notice how you may be rolling the die many times.

Concept 2: Folding to Map
In the above example of dice, you could have mapped the other values and minimized the waste. 
For example, 1,2,3 (= heads), 4,5,6 (= tails). Or mapping even numbers to heads, and odd numbers to tails. 
This way you can re-use and prevent re-rolls. 

Concept 3: Expanding Range
Assume you had rand10, that will give you one digit, if you wanted rand100 or rand1000, 
you can call rand10 to generate each digit. 
So 
rand100 = 10*rand10()+1*rand10(), and
rand1000 = 100*rand10()+10*rand10()+1*rand10()

Similarly, for rand25/rand125, You can call rand5 multiple times, and assemble the values 
rand25 = 5*rand5()+1*rand5()
rand125 = 25*rand5()+5*rand5()+1*rand5()

Putting it all together
If you are given rand5, then you can expand it to rand25 and then reduce it to rand7
*/
int rand25() {
 return 5*rand5() + rand5();
}
int rand7() {
  int r = Integer.MAX_INT;
  while (r > 6) r = rand25()/3;
  return r;
}


# or 

int rand7()
{
  int sum;
  do
  {
    sum = 5 * rand5() + rand5();
  } while (sum > 20);
  
  return sum % 7;
}
