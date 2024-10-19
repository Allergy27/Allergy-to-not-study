package lesson;

public class Goods {
    public static void main(String[] args) {
        Commodity A = new Commodity("电视机AT-X03", 20, 1888.98, 12414, "Lenovo");
        Commodity B = new Commodity("电视机AT-X03", 20, 1999.88, 12414, "SAMSUMG");
        System.out.println(A.equals(B));
        System.out.println(A);
        System.out.println(B);
    }
}

class Commodity {
    private String name;
    private double weight;
    private double price;
    private int mountingSum;
    private String mountingCreator;

    public Commodity() {
    }

    public Commodity(String name, double weight, double price, int mountingSum, String mountingCreator) {
        this.name = name;
        this.weight = weight;
        this.price = price;
        this.mountingSum = mountingSum;
        this.mountingCreator = mountingCreator;
    }

    public boolean equals(Commodity commodity) {
        return this.name.equals(commodity.name) && this.weight == commodity.weight
                && this.mountingSum == commodity.mountingSum;
    }

    public String toString() {
        return "商品名称:" + name + "，重量:" + weight + "，价格:" + price + "，配件数量:" + mountingSum + "，配件制造厂商:"
                + mountingCreator;
    }
}