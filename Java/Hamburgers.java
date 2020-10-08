//Solution code with fast IP/OP
//Full question and sample test cases at end

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;


public class A {
    final static long MOD = 1000000007;

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        char [] rec = fs.nextCharArray();
        long [] have = fs.nextLongArray(3);
        long [] price = fs.nextLongArray(3);
        long money = fs.nextLong();
        long [] recipe = new long[3];

        for (char c : rec) {
            if (c == 'B') {
                recipe[0]++;
            } else if (c == 'S') {
                recipe[1]++;
            } else if (c == 'C') {
                recipe[2]++;
            }
        }
        out.println(binary_search_function(recipe, have, price, money));
        out.flush();
        out.close();
    }

    static long binary_search_function(long [] recipe, long [] have, long [] price, long money){
        long l = 0;
        long r = 1;
        while(is_good(recipe, have, price, money, r)) r*=2;
        while(r > l+1) {
            long m = (r + l)/2;
            if(is_good(recipe, have, price, money, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }


    static boolean is_good(long [] recipe, long [] have, long [] price, long money, long hamburgers) {
        long total_B_money = (recipe[0] * hamburgers - have[0]) * price[0];
        long total_S_money= (recipe[1] * hamburgers - have[1]) * price[1];
        long total_C_money = (recipe[2] * hamburgers - have[2]) * price[2];
        long total_money = Math.max(0, total_B_money) + Math.max(0, total_S_money) + Math.max(0, total_C_money);
        return total_money <= money;
    }


    static double function_binary_search_real(double c){
        double l = 0;
        double r = 1;
        while (!good(r, c)) r *= 2;

        for(int i = 0; i < 100; i++) {
            double m = (r+l)/2;
            if(!good(m,c)) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    static boolean good(double m, double c){
        return ((m * m) + Math.sqrt(m)) >= c;
    }

    private static long solve(double t, double z, double y, long T) {
        long balloons = 0;
        while(true) {
            T -= t;
            if(T >=0) {
                balloons++;
                if(balloons % z == 0)
                    T-=y;
            } else
                break;
        }
        return balloons;
    }

    static int binary_search_upper (int [] a, int n, int x) {
        int l = -1; //
        int r = n; // a[r] >= x
        while(r > l + 1) {
            int m = (l+r)/2;
            if(a[m] < x) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    static int binary_search_lower(int [] a, int n, int x) {
        int l = -1; // a[l] <= x
        int r = n; //
        while(r > l + 1) {
            int m = (l+r)/2;
            if(a[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    static class ITEM {
        long value;
        public ITEM(long sum) {
            this.value = sum;
        }
    }

    static class SegmentTree {
        int size;
        ITEM [] calc;

        private ITEM NUETRAL_ELEMENT() {
            return new ITEM(0);
        }

        private ITEM MERGE(ITEM left, ITEM right) {
            return new ITEM(left.value + right.value);
        }

        private ITEM SINGLE_ELEMENT(int v) {
            return new ITEM(v);
        }

        SegmentTree(int n) {
            size = 1;
            while(size < n) size*=2;
            calc = new ITEM[2 * size];
        }

        public void build(int a[]) {
            build(a, 0, 0, size);
        }

        public void set(int i, int v) {
            set(i, v, 0, 0, size);
        }

        public ITEM calc(int l, int r) {
            return calc(l, r, 0, 0, size);
        }

        public ITEM find(int k) {
            return find(k, 0, 0, size);
        }

        private ITEM find(int k, int x, int lx, int rx) {
            //if(calc[x].value < k) return new ITEM(-1);
            if(rx - lx == 1) return new ITEM(lx);
            int m = (lx + rx) / 2;
            ITEM right = calc[2* x + 2];
            //ITEM left = calc[2 * x + 1];
            if(right.value > k) {
                return find(k, 2 * x + 2, m, rx);
            } else {
                return find(k - (int)right.value, 2 * x + 1, lx, m);
            }
        }

        private void build(int[] a, int x, int lx, int rx) {
            if(rx - lx == 1) {
                calc[x] = lx < a.length ? SINGLE_ELEMENT(a[lx]) : NUETRAL_ELEMENT();
                return;
            }
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            calc[x] = MERGE(calc[2 * x + 1], calc[2 * x + 2]);
        }

        private void set(int i, int v, int x, int lx, int rx) {
            if(rx - lx == 1) {
                calc[x] = new ITEM(SINGLE_ELEMENT(v).value);
                return;
            }
            int m = (lx + rx) / 2;
            if(i < m) {
                set(i, v, 2 * x + 1, lx, m);
            } else {
                set(i, v, 2 * x + 2, m, rx);
            }
            calc[x] = MERGE(calc[2 * x + 1], calc[2 * x + 2]);
        }

       private ITEM calc(int l, int r, int x, int lx, int rx) {
            if(lx >= r || l >= rx) return NUETRAL_ELEMENT();
            if(lx >= l && rx <= r) return calc[x];

            int m = (lx + rx) / 2;

            ITEM left = calc(l, r, 2 * x + 1, lx, m);
            ITEM right = calc(l, r, 2 * x + 2, m, rx);

            return MERGE(left, right);
        }

    }

    static void shuffleArray(long[] ar)
    {
        Random rnd = ThreadLocalRandom.current();
        for (int i = ar.length - 1; i > 0; i--)
        {
            int index = rnd.nextInt(i + 1);
            long a = ar[index];
            ar[index] = ar[i];
            ar[i] = a;
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
                // br = new BufferedReader(new FileReader("chat.txt"));
                st = new StringTokenizer("");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        public String next() {
            if (st.hasMoreTokens())
                return st.nextToken();
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            String line = "";
            try {
                line = br.readLine();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return line;
        }

        public char nextChar() {
            return next().charAt(0);
        }

        public Integer[] nextIntegerArray(int n) {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        public char[] nextCharArray() {
            return nextLine().toCharArray();
        }
    }

}

/*Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) and 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "BSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again.
Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese.
Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

input
BBBSSC
6 4 1
1 2 3
4

output
2
