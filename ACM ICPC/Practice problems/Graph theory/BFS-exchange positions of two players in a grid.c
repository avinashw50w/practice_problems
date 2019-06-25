/*A quick summary of the problem is that we want to exchange the positions of two players on a grid. There are impassable spaces 
represented by ‘X’ and spaces that we can walk in represented by ‘ ‘. Since we have two players our node structure becomes a bit more 
complicated, we have to represent the positions of person A and person B. Also, we won’t be able to simply use our array to represent 
visited positions any more, we will have an auxiliary data structure to do that. Also, we are allowed to make diagonal movements 
in this problem, so we now have 9 choices, we can move in one of 8 directions or simply stay in the same position. 
Another little trick that we have to watch for is that the players can not just swap positions in a single turn, so we have to do a 
little bit of validity checking on the resulting state.

First, we set up the node structure and visited array:  */

class node {
 int player1X, player1Y, player2X, player2Y;
 int steps; // The current number of steps we have taken to reach this step
}

bool visited[20][20][20][20];
/* Here a node is represented as the (x,y) positions of player 1 and player 2. It also has the current steps that we have taken to reach the current state, we need this because the problem asks us what the minimum number of steps to switch the two players will be. We are guaranteed by the properties of the Breadth First search that the first time we visit the end node, it will be as quickly as possible (as all of our edge costs are 1).

The visited array is simply a direct representation of our node in array form, with the first dimension being player1X, second player1Y, etc. Note that we don’t need to keep track of steps in the visited array.

Now that we have our basic structure set up, we can solve the problem (note that this code is not compilable): */
void pushToQueue(queue<node> q, node v) {
 if (visited[v.player1X][v.player1Y][v.player2X][v.player2Y]) return;
 q.push(v);
 visited[v.player1X][v.player1Y][v.player2X][v.player2Y] = true;
}

int minTurns(String[] board) {
 int width = board[0].length;
 int height = board.length;

 node start;
 // Find the initial position of A and B, and save them in start.

 queue<node> q;
 q.push(q, start)
 while (!q.empty()) {
  node top = q.front();
  q.pop();

  // Check if player 1 or player 2 is out of bounds, or on an X square, if so continue
  // Check if player 1 or player 2 is on top of each other, if so continue

  // Check if the current positions of A and B are the opposite of what they were in start.
  // If they are we have exchanged positions and are finished!
  if (top.player1X == start.player2X && top.player1Y == start.player2Y &&
      top.player2X == start.player1X && top.player2Y == start.player1Y)
      return top.steps;

  // Now we need to generate all of the transitions between nodes, we can do this quite easily using some
  // nested for loops, one for each direction that it is possible for one player to move.  Since we need
  // to generate the following deltas: (-1,-1), (-1,0), (-1,1), (0,-1), (0,0), (0,1), (1,-1), (1,0), (1,1)
  // we can use a for loop from -1 to 1 to do exactly that.
  // or rather we can use this: 
    int dxy[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int i=0;i<8;i++){
      int player1XDelta = dxy[i][0] , player1YDelta = dxy[i][1];
      for(int j=0;j<8;j++){
        int player2XDelta = dxy[j][0] , player2YDelta = dxy[j][1];
     // Careful though!  We have to make sure that player 1 and 2 are not on th same position
      if (top.player1X == top.player2X + player2XDelta && top.player1Y == top.player2Y + player2YDelta &&
         top.player2X == top.player1X + player1XDelta && top.player2Y == top.player1Y + player1YDelta)
        continue;

     // Add the new node into the queue
      pushToQueue(q, node(top.player1X + player1XDelta, top.player1Y + player1YDelta,
              top.player2X + player2XDelta, top.player2Y + player2YDelta,
              top.steps + 1));
     }
    }
   }
  }
 }

 // It is not possible to exchange positions, so
 // we return -1.  This is because we have explored
 // all the states possible from the starting state,
 // and haven't returned an answer yet.
 return -1;
}