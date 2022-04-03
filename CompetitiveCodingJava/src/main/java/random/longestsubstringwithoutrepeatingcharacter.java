import java.util.HashSet;
import java.util.Set;

public class longestsubstringwithoutrepeatingcharacter {

    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0)   return 0;
        int lptr=0, rptr=1, len=s.length(), res=1, curr_len=1;
        int[] arr = new int[128];
        arr[s.charAt(0)] = 1;
        while(rptr<len) {
            while (arr[s.charAt(rptr)] == 1) {
                arr[s.charAt(lptr)] = 0;
                curr_len-=1;
                lptr++;
            }
            arr[s.charAt(rptr)] = 1;
            rptr++;
            curr_len+=1;
            res = Math.max(res, curr_len);
        }
        return res;
    }
}
