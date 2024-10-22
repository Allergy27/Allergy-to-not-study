package class_program;

class MediaLibrary {
    protected String type, name;
    protected int occupytion;
    private static MediaLibrary all[] = new MediaLibrary[100];
    public static int capacity = 8 * 1024 * 1024;
    public static int count = 0;

    private static String transToXB(int num) {
        int show = num;
        String type = "bit";
        if (num >= 8 * 1024 * 1024) {
            show = num / 8 / 1024 / 1024;
            type = "MB";
        } else if (num >= 8 * 1024) {
            show = num / 8 / 1024;
            type = "KB";
        } else if (num >= 8) {
            show = num / 8;
            type = "Byte";
        }
        return show + type;
    }

    public void read() {
        // todo
    }

    public void save() {
        // todo
    }

    public MediaLibrary() {
        all[count++] = this;
    }

    public MediaLibrary(String name, String type, int occupytion) {
        this.type = type;
        this.name = name;
        this.occupytion = occupytion;
        capacity -= occupytion;
        all[count++] = this;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setOccupytion(int occupytion) {
        this.occupytion = occupytion;
    }

    public String getType() {
        return type;
    }

    public String getName() {
        return name;
    }

    public int getOccupytion() {
        return occupytion;
    }

    public void showSystem() {
        System.out.println("文件:" + name + type + "\n占用:" + transToXB(occupytion));
    }

    public static void showRest() {
        System.out.println("媒体库中文件:");
        for (int i = 0; i < count; ++i) {
            all[i].showSystem();
        }
        System.out.println("剩余容量:" + transToXB(capacity));
    }
}

class photo extends MediaLibrary {

    public void showSystem() {
        // Todo
    }
}