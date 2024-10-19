package luogu;

import java.util.Scanner;

public class P1035 {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            int num = input.nextInt();
            double Sn = 0;
            int i = 1;
            while (Sn <= num) {
                Sn += 1.0 / i;
                i += 1;
            }
            System.out.println(i - 1);
        }
    }
}
