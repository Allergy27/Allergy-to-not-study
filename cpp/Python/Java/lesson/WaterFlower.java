package lesson;

public class WaterFlower {
    public static void main(String[] args) {
        for (int i = 100; i < 1000; ++i) {
            int a = i % 10, b = i / 10 % 10, c = i / 100;
            if (a * a * a + b * b * b + c * c * c == i) {
                System.out.println(i);
            }
        }
    }
}
