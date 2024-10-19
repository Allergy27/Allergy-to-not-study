package lesson;

public class Huahua {
    public static void main(String[] args) {
        TrustCard aCard = new TrustCard(5000);
        BorrowCard bCard = new BorrowCard(2000);
        double ans = aCard.takeMoney(3500) + bCard.takeMoney(110);
        System.out.println("一共花费" + ans + "元");
        aCard.show();
        bCard.show();

    }
}

abstract class Card {
    protected double res;

    public Card() {
    }

    public Card(double res) {
        this.res = res;
    }

    public double takeMoney(double x) {
        return x;
    }

    public void show() {
    }

}

class TrustCard extends Card {
    public TrustCard() {
    }

    public TrustCard(double res) {
        this.res = res;
    }

    public double takeMoney(double x) {
        if (x * 1.01 > res) {
            System.out.println("信用卡额度不足");
            return 0;
        } else {
            res -= x * 1.01;
            System.out.println("成功取出" + x + "元");
            return x * 1.01;
        }
    }

    public void show() {
        System.out.println("信用卡内余额：" + res + "元");
    }
}

class BorrowCard extends Card {
    public BorrowCard() {
    }

    public BorrowCard(double res) {
        this.res = res;
    }

    public double takeMoney(double x) {
        if (x > res) {
            System.out.println("信用卡额度不足");
            return 0;
        } else {
            res -= x;
            System.out.println("成功取出" + x + "元");
            return x;
        }
    }

    public void show() {
        System.out.println("信用卡内余额：" + res + "元");
    }
}