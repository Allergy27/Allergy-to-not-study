package lesson;

public class Staffclass {
    public static void main(String[] args) {
        Staff qwq = new Staff("1", "张三 ", " 22 ", 5000);
        qwq.setAge("23");
        qwq.setNumb("0");
        qwq.show();
    }

}

class Staff {
    private String numb;
    private String name;
    private String age;
    private int salary;

    public Staff() {

    }

    public Staff(String numb, String name, String age, int salary) {
        this.numb = numb;
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    public void setNumb(String numb) {
        this.numb = numb;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public String getNumb(String numb) {
        return numb;
    }

    public String getName(String name) {
        return name;
    }

    public String getAge(String age) {
        return age;
    }

    public int getSalary(int salary) {
        return salary;
    }

    public void show() {
        System.out.println("编号\t姓名\t年龄\t工资");
        System.out.println(numb + '\t' + name + '\t' + age + '\t' + salary);
    }

}
