// Question: on an infinite chess board, a knight starts from (0, 0) 
// and tries to jump to (x, y)
// it can only make L-shaped moves, i.e. move 1 step in one direction and 2 in the perpendicular
// or 2 then 1
// return the minimum steps it takes to get to (x, y)
// or -1 if impossible

private final int[][] DIRECTIONS = new int[][] {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

// this is : infinite board, starting from 0, 0
public int minKnightMoves(int x, int y) {
    // same moves for all four quadrants
    x = Math.abs(x);
    y = Math.abs(y);

    Queue<int[]> queue = new LinkedList<>();
    queue.add(new int[] {0, 0});
    // these should be actual start points
    Set<String> visited = new HashSet<>();
    visited.add("0,0");

    int result = 0;
    while (!queue.isEmpty()) {
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        int[] cur = queue.remove();
        int curX = cur[0];
        int curY = cur[1];
        if (curX == x && curY == y) {
          return result;
        }

        for (int[] d: DIRECTIONS) {
          int newX = curX + d[0];
          int newY = curY + d[1];
          // remove newX, newY >= -1 gives TLE, check with n in actual sol
          if (!visited.contains(newX + "," + newY) && newX >= -1 && newY >= -1) {
            queue.add(new int[] {newX, newY});
            visited.add(newX + "," + newY);
          }
        }
      }
      result++;
    }
    return -1;
}
