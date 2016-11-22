package workshop;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by kicsen on 2016. 11. 22..
 */
public class Counter implements ActionListener {

    protected JFrame frame = new JFrame("BasicExample Application");
    protected JPanel panel = new JPanel();
    protected JButton button = new JButton("Press me!");
    protected JLabel label = new JLabel("Not pressed yet.");

    protected int pressed = 0;

    public Counter() {

        panel.add(button);
        panel.add(label); // Add button to panel

        frame.add(panel);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        button.addActionListener(this); // Set action listener of button
    }

    /*
     * Event handler function
     */
    public void actionPerformed(ActionEvent actionEvent) {
        if (actionEvent.getSource() == button) {
            this.pressed++;

            // Modify the content of counter label.
            label.setText("Pressed: " + pressed);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Counter();
            }
        });
    }
}