fun main(args: Array<String>) {
    val s = """22:55:32.940831: Actual Buffer: [A, B], size: 2
22:55:34.941064: Actual Buffer: [A, B, B], size: 3
22:55:36.941370: Actual Buffer: [A, B, B, A, A, B], size: 6
22:55:38.941571: Actual Buffer: [A, B, B, A, A, B, B], size: 7
22:55:40.941825: Actual Buffer: [A, B, B, A, A, B, B, A, A, B], size: 10
22:55:42.942024: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B], size: 11
22:55:44.942432: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 14
22:55:46.942694: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 15
22:55:48.942981: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 18
22:55:50.943212: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 19
22:56:28.743657: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, B], size: 20
22:56:30.743783: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 19
22:56:32.744240: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 18
22:56:34.744344: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 15
22:56:36.744700: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 14
22:56:38.744788: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B], size: 11
22:56:40.744994: Actual Buffer: [A, B, B, A, A, B, B, A, A, B], size: 10
22:56:42.745082: Actual Buffer: [A, B, B, A, A, B, B], size: 7
22:56:44.745289: Actual Buffer: [A, B, B, A, A, B], size: 6
22:56:46.745358: Actual Buffer: [A, B, B, B], size: 4
22:56:48.745576: Actual Buffer: [A, B, B, A, B], size: 5
22:56:50.745661: Actual Buffer: [A, B, B], size: 3
22:56:52.745926: Actual Buffer: [A, B, B, B], size: 4
22:56:54.746083: Actual Buffer: [A, B, B, B], size: 4
22:56:56.746434: Actual Buffer: [A, B, B, B], size: 4
22:56:58.746527: Actual Buffer: [A, B, B, B], size: 4
22:57:00.746795: Actual Buffer: [A, B, B, B], size: 4
22:57:02.746879: Actual Buffer: [A, B, B, B], size: 4
22:57:04.747209: Actual Buffer: [A, B, B, B], size: 4
22:55:05.434058: Actual Buffer: [A], size: 1
22:55:34.941160: Actual Buffer: [A, B, B, A], size: 4
22:55:36.941280: Actual Buffer: [A, B, B, A, A], size: 5
22:55:38.941629: Actual Buffer: [A, B, B, A, A, B, B, A], size: 8
22:55:40.941738: Actual Buffer: [A, B, B, A, A, B, B, A, A], size: 9
22:55:42.942210: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A], size: 12
22:55:44.942315: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A], size: 13
22:55:46.942779: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A], size: 16
22:55:48.942879: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A], size: 17
22:55:50.943304: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A], size: 20
22:56:27.743488: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A], size: 20
22:56:30.743984: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, A], size: 19
22:56:32.744103: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A], size: 17
22:56:34.744401: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A], size: 16
22:56:36.744561: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A], size: 13
22:56:38.744848: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A], size: 12
22:56:40.744941: Actual Buffer: [A, B, B, A, A, B, B, A, A], size: 9
22:56:42.745143: Actual Buffer: [A, B, B, A, A, B, B, A], size: 8
22:56:44.745230: Actual Buffer: [A, B, B, A, A], size: 5
22:56:46.745420: Actual Buffer: [A, B, B, B, A], size: 5
22:56:48.745513: Actual Buffer: [A, B, B, A], size: 4
22:56:50.745720: Actual Buffer: [A, B, B, A], size: 4
22:56:52.745804: Actual Buffer: [A, B, B, A], size: 4
22:56:54.746185: Actual Buffer: [A, B, B, A], size: 4
22:56:56.746288: Actual Buffer: [A, B, B, A], size: 4
22:56:58.746627: Actual Buffer: [A, B, B, A], size: 4
22:57:00.746712: Actual Buffer: [A, B, B, A], size: 4
22:57:02.746973: Actual Buffer: [A, B, B, A], size: 4
22:57:04.747065: Actual Buffer: [A, B, B, A], size: 4
22:56:27.743249: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 19
22:56:28.743472: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 19
22:56:29.743662: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 19
22:56:30.743861: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 18
22:56:31.744044: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A], size: 17
22:56:32.744283: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A], size: 17
22:56:33.744427: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 15
22:56:34.744541: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B], size: 15
22:56:35.744677: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A], size: 13
22:56:36.744888: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A], size: 13
22:56:37.745062: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B], size: 11
22:56:38.745177: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B], size: 11
22:56:39.745289: Actual Buffer: [A, B, B, A, A, B, B, A, A], size: 9
22:56:40.745411: Actual Buffer: [A, B, B, A, A, B, B, A, A], size: 9
22:56:41.745522: Actual Buffer: [A, B, B, A, A, B, B], size: 7
22:56:42.745644: Actual Buffer: [A, B, B, A, A, B, B], size: 7
22:56:43.745763: Actual Buffer: [A, B, B, A, A], size: 5
22:56:44.745883: Actual Buffer: [A, B, B, A, A], size: 5
22:56:45.746001: Actual Buffer: [A, B, B], size: 3
22:56:46.746124: Actual Buffer: [A, B, B], size: 3
22:56:48.745606: Actual Buffer: [A, B, B, A], size: 4
22:56:49.745716: Actual Buffer: [A, B], size: 2
22:56:52.745871: Actual Buffer: [A, B, B], size: 3
22:56:54.746149: Actual Buffer: [A, B, B], size: 3
22:56:56.746386: Actual Buffer: [A, B, B], size: 3
22:56:58.746595: Actual Buffer: [A, B, B], size: 3
22:57:00.746769: Actual Buffer: [A, B, B], size: 3
22:57:02.746937: Actual Buffer: [A, B, B], size: 3
22:57:04.747181: Actual Buffer: [A, B, B], size: 3
22:56:30.401807: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 18
22:56:31.402032: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 18
22:56:32.402136: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A], size: 16
22:56:33.402293: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B, B, A], size: 16
22:56:34.402892: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 14
22:56:35.403197: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A, A, B], size: 14
22:56:36.403296: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A], size: 12
22:56:37.403400: Actual Buffer: [A, B, B, A, A, B, B, A, A, B, B, A], size: 12
22:56:38.403513: Actual Buffer: [A, B, B, A, A, B, B, A, A, B], size: 10
22:56:39.403721: Actual Buffer: [A, B, B, A, A, B, B, A, A, B], size: 10
22:56:40.403937: Actual Buffer: [A, B, B, A, A, B, B, A], size: 8
22:56:41.404150: Actual Buffer: [A, B, B, A, A, B, B, A], size: 8
22:56:42.404268: Actual Buffer: [A, B, B, A, A, B], size: 6
22:56:43.404388: Actual Buffer: [A, B, B, A, A, B], size: 6
22:56:44.404524: Actual Buffer: [A, B, B, A], size: 4
22:56:45.404763: Actual Buffer: [A, B, B, A], size: 4
22:56:46.745451: Actual Buffer: [A, B, B, B], size: 4
22:56:48.745719: Actual Buffer: [A, B, B], size: 3
22:56:50.745786: Actual Buffer: [A, B, B], size: 3
22:56:52.746026: Actual Buffer: [A, B, B], size: 3
22:56:54.746230: Actual Buffer: [A, B, B], size: 3
22:56:56.746470: Actual Buffer: [A, B, B], size: 3
22:56:58.746655: Actual Buffer: [A, B, B], size: 3
22:57:00.746823: Actual Buffer: [A, B, B], size: 3
22:57:02.747010: Actual Buffer: [A, B, B], size: 3
22:57:04.747278: Actual Buffer: [A, B, B], size: 3"""

    s.split("\n")
    	.sortedBy { "${it.substring(0, 15)}" }
    	.forEach{ println(it) }
}