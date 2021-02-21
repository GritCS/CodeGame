# Week 212





## Q1631[. 最小体力消耗路径](https://leetcode-cn.com/problems/path-with-minimum-effort/)

你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

 

- 示例 1：

![ex1](ex1.png)

> 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
>
> 输出：2
> 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
> 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路劲差值最大值为 3 。

- 实例２

![ex2](ex2.png)

> 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
> 输出：1
> 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。

- 示例 3

![ex3](ex3.png)

> 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
> 输出：0
> 解释：上图所示路径不需要消耗任何体力。

### 解法１：最短路径(利用Dijkstra算法)

问题建模：

把每个坐标`(x,y)`看作一个结点，相邻坐标之间路径差值作为两个结点的之间的路径cost，

问题是要求`(0,0)`->`(m-1,n-1)`之间所有可能的路径中，求最小cost的路径，路径cost定义为路径中所有edge中最大的cost

用`dist`保存坐标`[i][j]`到起点的path cost

用`dir`保存顶点相邻的位置关系，本解法中没有完整的表示边的数据结构，仅仅在计算的过程中和计算结果　用一个长度为３的int数组表示

利用`Dijkstra`生成最短路径树－－`dist`保存每个坐标到起点的最短距离,`dist[m-1][n-1]`为最后结果



==自己的思路是　想着用　dp，递推关系也很简单，只是我没有办法自己确定先后顺序。以及我们没有往图论　问题思考==

- ==没有自己的解题方法库==
- ==对经典算法的应用没有很了解，算法没有吃透==
- ==后续相关知识点：java　PriorityQueue　API的使用，Dijkstra算法原理（参考算法４）==

```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        
        int[][] dist = new int[m][n];　//dist[i][j]表示　[i][j]结点到[0][0]最小path cost
        int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int[] d : dist)
            Arrays.fill(d, Integer.MAX_VALUE);
        dist[0][0] = 0;
        
        //采用优先级队列，维护一个小堆来待被visited的结点，指标 path cost
        Queue<int[]> queue = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        
        boolean[][] visited = new boolean[m][n];
        
        queue.offer(new int[]{0, 0, 0});
        
        while(!queue.isEmpty()) {
            
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1];
            //由于[x][y]为堆中距离起点[0][0]最近的节点，所以我们确定将该节点加入visited节点集合中(虽然加入了该顶点集合其path cost还有被更新的机会)
            if(visited[x][y])
                continue;
            visited[x][y] = true;
            
            //松弛结点[x][y]
            for(int[] d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                    int effort = Math.max(dist[x][y], Math.abs(heights[x][y] - heights[nx][ny]));
                    dist[nx][ny] = Math.min(dist[nx][ny], effort);
                    queue.offer(new int[]{nx, ny, dist[nx][ny]});
                }
            }
        }
        return dist[m-1][n-1];
    }   
}

作者：onion12138
链接：https://leetcode-cn.com/problems/path-with-minimum-effort/solution/javasi-chong-jie-fa-zui-duan-lu-zui-xiao-sheng-che/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

### 解法２　最小生成树(并查集实现)

- 问题建模

​		用数据结构`<Edge>`来保存边的信息：起点，终点，edge cost

​		同时利用`list<Edge>`保存所有边，起初将所有边都加入list中，按照　edge cost对边进行排序，每次选择index最小（排序后对应edge cost最小）的边，加入最小生成树中，成功加入的条件是　该边的起点和终点是不连通的(不能形成环路)[==选用list的原因是之后方便按序索引，堆也是可以的==]

​	由于依次加入生成树的边的权重是递增的，所以最后的结果就是最后一次加入最小生成树的边对应的权重

- ==后续知识点：　最小生成树，与单源最短路径之间的关系==

​		

```java
class Solution {
    private int m;
    private int n;
    public int minimumEffortPath(int[][] heights) {
        m = heights.length;
        n = heights[0].length;
        parent = new int[m * n];
        rank = new int[m * n];
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        List<Edge> list = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i + 1 < m){
                    list.add(new Edge(i*n+j, (i+1)*n+j, Math.abs(heights[i][j] - heights[i+1][j])));
                }
                if(j + 1 < n){
                    list.add(new Edge(i*n+j, i*n+j+1, Math.abs(heights[i][j] - heights[i][j+1])));
                }
            }
        }
        Collections.sort(list, (a, b) -> a.value - b.value);
        int ret = 0;
        for(Edge edge : list){
            if(isConnected(0, m*n-1))
                break;
            int v = edge.v, w = edge.w;
            if(!isConnected(v, w)){
                unionElements(v, w);
                ret = edge.value;
            }
        }
        return ret;
    }
    class Edge{
        int v;
        int w;
        int value;
        Edge(int v, int w, int value) {
            this.v = v;
            this.w = w;
            this.value = value;
        }
    }
    private int[] parent;
    private int[] rank;
    private int find(int p){
        if (p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }
    private boolean isConnected(int p, int q) {
        return find(p) == find(q);
    }
    public void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot)
            return;
        if(rank[pRoot] < rank[qRoot])
            parent[pRoot] = qRoot;
        else if(rank[pRoot] > rank[qRoot])
            parent[qRoot] = pRoot;
        else {
            parent[qRoot] = pRoot;
            rank[pRoot] += 1;
        }
    }
}

作者：onion12138
链接：https://leetcode-cn.com/problems/path-with-minimum-effort/solution/javasi-chong-jie-fa-zui-duan-lu-zui-xiao-sheng-che/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

