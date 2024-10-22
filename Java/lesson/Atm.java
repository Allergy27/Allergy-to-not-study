package lesson;

public class Atm {
    public static void main(String[] args) {
        Account qwq = new Account(100);
        qwq.query();
    }
}

class Account {
    private int res;

    public Account() {
    }

    public Account(int res) {
        this.res = res;
    }

    public void query() {
        System.out.println("当前余额：" + res + "元");
    }

    public void saveMoney(int x) {
        res += x;
        System.out.println("成功存入" + res + "元");
    }

    public int takeMoney(int x) {
        if (x > res) {
            System.out.println("余额不足，取款失败");
            return 0;
        } else {
            res -= x;
            System.out.println("成功取出" + x + "元");
            return x;
        }
    }

}