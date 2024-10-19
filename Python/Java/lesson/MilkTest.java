package lesson;

abstract class Milk {
    protected int month, day, deadline;

    public Milk() {
    }

    public Milk(int m, int d) {
        this.month = m;
        this.day = d;
    }

    protected int trans(int m, int d) {
        return m * 30 + d;
    }

    public abstract void calDate(Milk m);

    public abstract void show();
}

class MNMilk extends Milk {
    public MNMilk(int m, int d) {
        super(m, d);
    }

    public void calDate(Milk m) {
        this.deadline = trans(m.month, m.day) + 14;
    }

    public void show() {
        int m = deadline / 30;
        int d = deadline % 30;
        System.out.println("该批次蒙牛牛奶保质期截至" + m + "月" + d + "日");
    }
}

class YLMilk extends Milk {
    public YLMilk(int m, int d) {
        super(m, d);
    }

    public void calDate(Milk m) {
        this.deadline = trans(m.month, m.day) + 10;
    }

    public void show() {
        int m = deadline / 30;
        int d = deadline % 30;
        System.out.println("该批次伊利牛奶保质期截至" + m + "月" + d + "日");
    }
}

public class MilkTest {
    public static void main(String[] args) {
        Milk m1 = new MNMilk(11, 20);
        m1.calDate(m1);
        Milk m2 = new YLMilk(11, 25);
        m2.calDate(m2);
        if (m1.deadline > m2.deadline) {
            System.out.println("蒙牛牛奶保质期较长");
            m1.show();
        } else {
            System.out.println("伊利牛奶保质期较长");
            m2.show();
        }
    }
}