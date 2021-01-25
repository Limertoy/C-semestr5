public class Main {

    public static void printArr(String[][][] tab) {
        int n = 0;
        for (int i = 0; i < tab.length; i++) {
            for (int j = 0; j < tab[i].length; j++) {
                n++;
                for (int k = 0; k < tab[i][j].length; k++) {
                    for (int l = 1; l < n; l++) {
                        System.out.print("-");
                    }
                    System.out.print(tab[i][j][k]);
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {

        String[][][] tab = {{{"A"}, {"B", "C", "D", "f1"}, {"D", "f1", "E"}}};

        String[][][] tab2 = {{{"X"}, {"Y", "Z", "f1"}, {"X", "f1", "Z", "f1"}}};

        printArr(tab);
        printArr(tab2);
    }
}