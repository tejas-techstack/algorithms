/*
  date : 28/05/25
  https://leetcode.com/problems/water-and-jug-problem/description/

*/

bool dfs(int x, int y, int curX, int curY, bool **visited, int target) {
    if (curX + curY == target || curX == target || curY == target) return true;
    if (visited[curX][curY]) return false;

    visited[curX][curY] = true;

    if (dfs(x,y,x,curY,visited,target)) return true;
    if (dfs(x,y,curX,y,visited,target)) return true;
    if (dfs(x,y,0,curY,visited,target)) return true;
    if (dfs(x,y,curX,0,visited,target)) return true;
    
    int transfer = 0;
    if (curX < y - curY) {
        transfer = curX;
    } else {
        transfer = y-curY;
    }

    if (dfs(x,y,curX-transfer,curY+transfer,visited,target)) return true;

    if (curY < x - curX) {
        transfer = curY;
    } else {
        transfer = x-curX;
    }

    if (dfs(x, y, curX+transfer, curY-transfer, visited, target)) return true;
    return false;
}

bool canMeasureWater(int x, int y, int target) {
    bool **visited = malloc((x+1)*sizeof(bool *));
    for (int i = 0; i <= x; i++) {
        visited[i] = calloc((y+1),sizeof(bool)); 
    }

    return dfs(x, y, 0, 0, visited, target);    
}

