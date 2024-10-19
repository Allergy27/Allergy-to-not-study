package class_program;

public class show {
    public static void start() {
        MediaLibrary qwq = new MediaLibrary("好看的视频", ".mp4", 102341);
        MediaLibrary qaq = new MediaLibrary("有趣的视频", ".mp4", 1233);
        MediaLibrary qvq = new MediaLibrary("惊喜的视频", ".mp4", 5213);
        MediaLibrary qcq = new MediaLibrary("有用的视频", ".mp4", 12321);
        qwq.setName("不好看的视频");
        qaq.setName("不有趣的视频");
        qvq.setName("不惊喜的视频");
        qcq.setName("不有用的视频");
        MediaLibrary.showRest();
    }
}
