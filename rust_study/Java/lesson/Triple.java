package lesson;

public class Triple {
    public static void main(String[] args) {
        Triangle t1 = new Triangle(3, 4, 5);
        Triangle t2 = new Triangle(1, 2, 3);
        System.out.println(t1.Ciscum());
        System.out.println(t2.Ciscum());
        System.out.println(t1.Square());
        System.out.println(t2.Square());
    }
}

class Triangle {
    private double a, b, c;

    public Triangle() {
    }

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double Ciscum() {
        return (a + b + c);
    }

    public double Square() {
        double p = Ciscum() / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }

}