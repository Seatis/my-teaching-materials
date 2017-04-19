package workshop;

import javax.swing.*;

/**
 * Created by kicsen on 2016. 11. 22..
 */
public class HelloWorld {

    //JFrame is the main frame with frame and exit button.
    protected JFrame frame = new JFrame("Hello World Application");
    //JPanel is an invisible container for organising other inner components.
    protected JPanel panel = new JPanel();
    protected JLabel label = new JLabel("Hello World!");

    public HelloWorld() {
        panel.add(label);
        frame.add(panel);

        // When you click to close button the program will terminate.
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Setup initial parameters of frame and draw it. You can use frame.setSize(800, 600); instead if you want set size of frame manually.
        frame.pack();
        // Display the frame - Mandatory
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new HelloWorld();
            }
        });
    }
}
