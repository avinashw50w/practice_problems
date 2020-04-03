/*      
Recently, Alice had to take a test. The test consisted of a sequence of true/false questions. Alice was completely unprepared for the test, so she just guessed each answer.

You are given the following inputs:

an int questions: the number of questions on the test.
an int guessed: the number of questions for which Alice guessed that the answer is "true".
an int actual: the actual number of questions for which the answer is "true".
In the test, each correct answer was worth 1 point and each incorrect answer was worth 0 points. Compute the largest possible number of points Alice could have received.

 
Definition
        
Class:  TestTaking
Method: findMax
Parameters: int, int, int
Returns:    int
Method signature:   int findMax(int questions, int guessed, int actual)
(be sure your method is public)
    
 
Constraints
-   questions will be between 1 and 50, inclusive.
-   guessed, actual will be between 0 and questions, inclusive.
 
Examples
0)  
        
3
1
2
Returns: 2
The test consisted of 3 statements.
Alice guessed that 1 of them is true.
Actually, there were 2 true statements on the test.
There are multiple possible outcomes of the test.

For example, it is possible that Alice wrote down the sequence of answers (false,true,false), but the correct sequence of answers is (true,false,true). In this case Alice would have received 0 points.

One possible best scenario for Alice looks as follows: Alice guessed that the answers are (false,false,true), and the correct answers are (true,false,true). In this scenario Alice would have received 0+1+1 = 2 points.*/

/*To maximize our number of points, we maximize the number of true answers that are correct and false answers that are correct. The number of true answers that are correct is at most min(guessed, actual). Symmetrically, the max number of false answers that are correct is min(questions-guessed, questions-actual).

Another way of looking at it is to minimize the number of responses that are different. There are a minimum of abs(guessed-actual) responses that can be different, so the answer can also be computed as questions-abs(guessed-actual)

*/

int findMax(int questions, int guessed, int actual) {

    return min(guessed, actual) + min(questions - guessed, questions - actual);
}