/**
 * 参考灵神题解写的代码
 */
import java.util.*;

class Node {
    Node[] son = new Node[26];
    int cnt = 0;
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        
        Node root = new Node();
        while (q-- > 0) {
            String op = sc.next();
            char[] w = sc.next().toCharArray();
            
            if ("I".equals(op)) {
                Node cur = root;
                for (int i = 0; i < w.length; i++) {
                    char c = w[i];
                    if (cur.son[c - 'a'] == null) {
                        cur.son[c - 'a'] = new Node();
                    }
                    cur = cur.son[c - 'a'];
                }
                cur.cnt++;
            } else {
                int res = -1;
                Node cur = root;
                for (int i = 0; i < w.length; i++) {
                    char c = w[i];
                    if (cur.son[c - 'a'] == null) {
                        // 找前缀时符合要求；找完整字符串时不符合要求；还是写成一个函数方便
                        res = 0; 
                        break;
                    }
                    cur = cur.son[c - 'a'];
                }
                if (res == -1) res = cur.cnt; 
                System.out.println(res);
            }  
        }
        
    }
} 

