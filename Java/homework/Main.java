package homework;

public class Main {
    public static void main(String[] args) {
        Bus bus = new Bus("气式");
        bus.brake();
        bus.charge(2);

        Taxi taxi = new Taxi("油式");
        taxi.brake();
        taxi.charge(1);
        taxi.controlAirTemperature();
    }
}

abstract class MotorVehicles {
    String brake;

    abstract void brake();
}

interface MoneyFare {
    void charge(int kilometer);
}

interface ControlTemperature {
    void controlAirTemperature();
}

class Bus extends MotorVehicles implements MoneyFare {
    Bus(String brake) {
        this.brake = brake;
    }

    void brake() {
        System.out.println("公共汽车使用的刹车技术:" + brake);
    }

    public void charge(int kilometer) {
        System.out.println("公共汽车:" + kilometer + "元/张，不记公里数");
    }
}

class Taxi extends MotorVehicles implements MoneyFare, ControlTemperature {
    Taxi(String brake) {
        this.brake = brake;
    }

    void brake() {
        System.out.println("出租车使用的刹车技术:" + brake);
    }

    public void charge(int kilometer) {
        System.out.println("出租车:" + kilometer + "元/公里，起步价5公里10元");
    }

    public void controlAirTemperature() {
        System.out.println("出租车安装了嵌入式空调");
    }
}