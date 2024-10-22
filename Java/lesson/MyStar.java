package lesson;

import java.util.Scanner;

public class MyStar {
    public static void main(String[] args) {
        try (Scanner scn = new Scanner(System.in)) {
            int n = scn.nextInt();
            showStar(n);
        }
    }

    static void showStar(int n) {
        for (int i = 0; i < n; ++i) {
            int k = Math.abs(i - n / 2);
            for (int j = 0; j < k; ++j) {
                System.out.print("  ");
            }
            for (int j = 0; j < n - 2 * k; ++j) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
