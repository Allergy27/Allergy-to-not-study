package lesson;

public class Employee {
    public static void main(String[] args) {
        Employees[] emps = new Employees[6];
        emps[0] = new Employees("20232882", "叶俊捷", 7000);
        emps[1] = new Managers("20232883", "叶捷俊", 6499, "软件开发部");
        emps[2] = new Director("20232884", "俊叶捷", 7000, 500);
        emps[3] = new Employees("20232885", "捷叶俊", 6799);
        emps[4] = new Managers("20232886", "捷俊叶", 7000, "系统维护部");
        emps[5] = new Director("20232887", "俊捷叶", 8000, 800);
        System.out.println("所有员工:");
        for (int i = 0; i < emps.length; i++) {
            emps[i].show();
        }
    }
}

class Employees {
    protected String number;
    protected String name;
    protected double salary;

    public Employees() {
    };

    public Employees(String number, String name, double salary) {
        this.number = number;
        this.name = name;
        this.salary = salary;
    }

    public void show() {
        System.out.println("员工编号:" + number + "，姓名:" + name + "，工资:" + salary);
    }
}

class Managers extends Employees {
    private String managePlace;

    public Managers() {
    }

    public Managers(String number, String name, double salary, String managePlace) {
        super(number, name, salary);
        this.managePlace = managePlace;
    }

    public void show() {
        System.out.println("员工编号:" + number + "，姓名:" + name + "，工资:" + salary + "，管理部门:" + managePlace);
    }
}

class Director extends Employees {
    private double bonus;

    public Director() {
    }

    public Director(String number, String name, double salary, double bonus) {
        super(number, name, salary);
        this.bonus = bonus;
    }

    public void show() {
        System.out.println("员工编号:" + number + "，姓名:" + name + "，工资:" + salary + "，津贴:" + bonus);
    }
}
