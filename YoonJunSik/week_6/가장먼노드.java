import java.util.*;

class Solution {
    public int solution(int n, int[][] edge)
    {
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0; i <= n; i++) graph.add(new ArrayList<>());

        // 1) 인접 리스트 구성
        for(int[] e : edge)
        {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }

        // 2) 거리 배열
        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);
        dist[1] = 0;

        // 3) BFS
        Queue<Integer> q = new LinkedList<>();
        q.add(1);

        while (!q.isEmpty()) {
            int now = q.poll();

            for(int next : graph.get(now))
            {
                if(dist[next] == -1) { // 아직 방문하지 않은 노드
                    dist[next] = dist[now] + 1;
                    q.add(next);
                }
            }
        }

        // 4) 가장 큰 거리 찾기
        int maxDist = 0;
        for(int d : dist) {
            if (d > maxDist) maxDist = d;
        }

        // 5) maxDist와 같은 거리의 노드 수 세기
        int count = 0;
        for(int d : dist) {
            if (d == maxDist) count++;
        }
        return count;
    }
}