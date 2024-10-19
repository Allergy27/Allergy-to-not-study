package lesson;

public class Penalty {
    public static void main(String[] args) {
        Ford ford = new Ford(200, 100, 130);
        QQ qq = new QQ(150, 100, 90);
        ford.stop();
        qq.stop();
    }
}

abstract class Car {
    protected int maxSpeed;
    protected int exceed;
    protected int speed;

    abstract void stop();
}

class Ford extends Car {

    public Ford(int maxSpeed, int exceed, int speed) {
        this.maxSpeed = maxSpeed;
        this.exceed = exceed;
        this.speed = speed;
    }

    public void stop() {
        if (speed > exceed) {
            System.out.println("Ford超速,扣1分,罚款200元");
        }
        if (speed > maxSpeed) {
            System.out.println("Ford停车");
        }
    }
}

class QQ extends Car {

    public QQ(int maxSpeed, int exceed, int speed) {
        this.maxSpeed = maxSpeed;
        this.exceed = exceed;
        this.speed = speed;
    }

    public void stop() {
        if (speed > exceed) {
            System.out.println("QQ超速,扣1分,罚款200元");
        }
        if (speed > maxSpeed) {
            System.out.println("QQ停车");
        }
    }
}