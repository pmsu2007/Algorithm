## 그래프 탐색 (DFS와 BFS)



### 그래프 탐색이란 ?

​	하나의 정점으로부터 시작하여 차례대로 모든 정점을 한 번씩 방문하는 것

- ### DFS : Depth First Search (깊이 우선 탐색) 

  <img src="https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif" alt="img" style="zoom:80%;" />

  시작 정점에서 다음 브랜치로 넘어가기 전에 해당 브랜치를 완벽하게 탐색하고 넘어가는 방법

  **스택** 또는 **재귀함수**로 구현한다.

  

  ### 과정 

  1. 탐색 시작 노드를 스택에 삽입하고 방문 처리한다
  2. 스택의 최상단 노드에 방문하지 않은 인접한 노드가 하나라도 있다면 그 노드를 스택에 넣고 방문처리한다. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
  3. 2번의 과정을 수행할 수 없을 때 까지 반복한다.

  

  ### 주의사항

  ​	노드 방문 시 **방문여부를 반드시 검사**해야 한다. (무한루프에 빠질 수 있음)

  ​	탐색 과정이 시작 노드에서 한없이 깊이 진행되는 것을 막기 위해 깊이 제한을 사용.

  ​	깊이 제한에 도달할 때 까지 목표노드가 발견되지 않으면 최근에 첨가된 노드의 부모노드로 돌아와서, 부모노드에 	이전과는 다른 동작자를 적용하여 새로운 자식노드 생성

  

  ### 장점

  ​	 1. 단지 현 경로상의 노드만을 기억하면 되므로 메모리가 비교적 적게 든다.

  ​	2. 목표노드가 깊은 단계에 있을 경우 해를 빨리 구할 수 있다.

  

  ### 단점

  ​	1. 해가 없는 경로에 깊이 빠질 가능성이 있다. 따라서, 실제의 경우 미리 지정한 임의의 깊이까지만 탐색하고 목표		노드를 발견하지 못한다면 다음 경로를 따라 탐색하는 방법이 유용할 수 있다.

  ​	2. 얻어진 해가 최단 경로가 된다는 보장이 없다. 목표에 이르는 경로가 다수인 문제에 대해 DFS는 해에 다다르면 		탐색을 끝내버리므로, 이때 얻어진 해는 최적이 아닐 수 있다.

  ### 코드

  ```c++
  #include <iostream>
  #include <vector>
  #include <stack>
  
  // index 0은 사용하지 않으므로 배열 크기를 하나 크게 잡자
  bool visited[9];
  std::vector<int> graph[9];
  
  void dfs(int start) // 재귀 ver.
  {
      visited[start] = true;
      std::cout << x << " ";
      for (int i = 0; i < graph[start].size(); i++) // 인접 정점만큼 탐색
      {
          int y = graph[start][i]; 
          if(!visited[y]) 
              dfs(y); // 재귀적으로 방문
      }
  }
  
  void dfs(int start) // 스택 ver.
  {
  	std::stack<int> s;
  	s.push(start);
  	dfs_visited[start] = true;
  	std::cout << start << " ";
  
  	while (!s.empty())
  	{
  		int y = s.top(); // 스택의 최상단 노드
  		
  		int i;
  		for (i = 0; i < graph[y].size(); i++)
  		{
  			int z = graph[y][i];
  			if (!dfs_visited[z])
  			{
  				dfs_visited[z] = true;
  				s.push(z); 
  				std::cout << z << " ";
  				break;
  			}
  
  			if (i == graph[y].size() - 1) // 모두 방문한 경우
  			{
  				s.pop();
  			}
  		}
  	}
  }
  
  int main()
  {
      graph[1].push_back(2);
  	graph[1].push_back(3);
  	graph[1].push_back(8);
  
  
  	graph[2].push_back(1);
  	graph[2].push_back(7);
  
  	graph[3].push_back(1);
  	graph[3].push_back(4);
  	graph[3].push_back(5);
  
  	graph[4].push_back(3);
  	graph[4].push_back(5);
  
  	graph[5].push_back(3);
  	graph[5].push_back(4);
  
  	graph[6].push_back(7);
  
  	graph[7].push_back(2);
  	graph[7].push_back(6);
  	graph[7].push_back(8);
  
  	graph[8].push_back(1);
  	graph[8].push_back(7);
  
  	dfs(1);
  }
  ```

  

- ### BFS : Breadth First Search (너비 우선 탐색)

  <img src="https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif" alt="img" style="zoom:80%;" />

  시작 정점으로부터 가장 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 방법

  **큐**를 이용해서 구현한다.

  

  ### 과정 

  1. 탐색 시작 노드를 큐에 삽입하고 방문 처리한다
  2. 큐에서 노드를 꺼낸 뒤에 해당 노드의 인접 노드 중 방문하지 않은 노드를 모두 큐에 삽입 후 방문 처리한다
  3. 2번의 과정을 수행할 수 없을 때 까지 반복한다.

  

  ### 장점

  ​	1. 출발노드에서 목표노드까지의 최단 길이 경로를 보장한다

  

  ### 단점

  ​	1. 경로가 매우 길 경우에는 탐색 가지가 급격히 증가함에 따라 많은 메모리를 필요로 한다.

  ​	2. 해가 존재하지 않는다면 유한 그래프의 경우, 모든 그래프를 탐색한 후에 실패로 끝난다.

  ​	3. 무한 그래프의 경우에는 해를 찾지도 못하고, 끝내지도 못한다

  

  ###  코드

  ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  
  // index 0은 사용하지 않으므로 배열을 하나 크게 잡자
  bool visited[9];
  std::vector<int> graph[9];
  
  void bfs(int start)
  {
      std::queue<int> q;
     	q.push(start); // 첫 노드를 큐에 삽입
      visited[start] = true; // 첫 노드를 방문처리
      
      while(!q.empty())
      {
          int x = q.front();// 큐에서 하나의 원소를 뽑아 출력
        	q.pop();
          std::cout << x << " ";
        	for (int i = 0; i < graph[x].size(); i++)
          {
              int y = graph[x][i];
              if (!visited[y])
              {
                  q.push(y);
                  visited[y]= true;
              }
          }
      }
  }
  
  int main()
  {
      graph[1].push_back(2);
      graph[1].push_back(3);
      graph[1].push_back(8);
  
      graph[2].push_back(1);
      graph[2].push_back(7);
  
      graph[3].push_back(1);
      graph[3].push_back(4);
      graph[3].push_back(5);
  
      graph[4].push_back(3);
      graph[4].push_back(5);
  
      graph[5].push_back(3);
      graph[5].push_back(4);
  
  
      graph[6].push_back(7);
  
      graph[7].push_back(2);
      graph[7].push_back(6);
      graph[7].push_back(8);
  
  
      graph[8].push_back(1);
      graph[8].push_back(7);
  
      bfs(1);
  }
  ```

  