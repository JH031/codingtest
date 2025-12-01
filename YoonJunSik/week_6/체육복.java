import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        Arrays.sort(lost);
        Arrays.sort(reserve);

        // 리스트로 관리
        List<Integer> lostList = new ArrayList<>();
        for(int l : lost) lostList.add(l);

        List<Integer> reserveList = new ArrayList<>();
        for(int r : reserve) reserveList.add(r);

        // 1) 본인이 도난 + 여벌 있는 경우 제거
        Iterator<Integer> itLost = lostList.iterator();
        while(itLost.hasNext())
        {
            int l = itLost.next();
            if(reserveList.contains(l))
            {
                itLost.remove();
                reserveList.remove(Integer.valueOf(l));
            }
        }

        // 2) 빌려주기 (앞번호 → 뒷번호)
        for(int r : reserveList)
        {
            if(lostList.contains(r - 1))
            {
                lostList.remove(Integer.valueOf(r - 1));
            } else if(lostList.contains(r + 1))
            {
                lostList.remove(Integer.valueOf(r + 1));
            }
        }

        // 3) 체육수업 가능한 학생 수
        return n - lostList.size();
    }
}