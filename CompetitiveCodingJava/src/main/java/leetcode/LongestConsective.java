package leetcode;

import java.util.HashMap;

public class LongestConsective {
    public static void main(String[] args) {
        int[] nums ={100,4,200,1,3,2};
        HashMap<Integer, Integer> map = new HashMap<>();
        int res = Integer.MIN_VALUE;
        for(int i=0 ;i<nums.length; i++) {
            int curr = nums[i];
            if(!map.containsKey(curr)) {
                int left = map.containsKey(curr-1) ? map.get(curr-1) : 0;
                int right = map.containsKey(curr+1) ? map.get(curr+1) : 0;
                int sum = left + right + 1;
                res = Math.max(res, sum);
                map.put(curr, sum);
                map.put(curr-left, sum);
                map.put(curr+right, sum);
            }
        }
        System.out.println(res);
    }
}
