import java.util.Arrays;

public class Dice {

    int[] dices = new int[6];

    public int[] roll() {
        for (int i = 0; i < dices.length; i++) {
            dices[i] = (int) (Math.random() * 6) + 1;
        }
        return dices;
    }

    public void getCurrent() {
        System.out.println(Arrays.toString(dices));
    }

    public void getCurrent(int i) {
        System.out.println(dices[i]);
    }

    public int[] reroll() {
        for (int i = 0; i < dices.length; i++) {
            dices[i] = (int) (Math.random() * 6) + 1;
        }
        return dices;
    }

    public int reroll(int k) {
        dices[k] = (int) (Math.random() * 6) + 1;
        return dices[k];
    }

    public static void main(String[] args) {
        Dice myDice = new Dice();
        myDice.getCurrent();
        myDice.roll();
        myDice.getCurrent();
        myDice.getCurrent(5);
        myDice.reroll();
        myDice.getCurrent();
        myDice.reroll(4);
        myDice.getCurrent();
    }
}
