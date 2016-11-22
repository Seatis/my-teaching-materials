package workshop;

import javax.swing.*;
import java.awt.*;

/**
 * Created by kicsen on 2016. 11. 22..
 */
public class WindowProperties extends JFrame {

    public WindowProperties() {
        // Define the size of the frame
        this.setSize(400, 400);

        // Toolkit is the super class for the Abstract Window Toolkit
        // It allows us to ask questions of the OS
        Toolkit toolkit = Toolkit.getDefaultToolkit();

        // A Dimension can hold the width and height of a component
        // getScreenSize returns the size of the screen
        Dimension screenDimension = toolkit.getScreenSize();

        // screenDimension.width returns the width of the screen
        // this.getWidth returns the width of the frame you are making
        int xPos = (screenDimension.width / 2) - (this.getWidth() / 2);
        int yPos = (screenDimension.height / 2) - (this.getHeight() / 2);

        // You could also define the x, y position of the frame
        this.setLocation(xPos, yPos);


        // Define how the user exits the program
        // This closes when they click the close button

        // Define if the user can resize the frame (true by default)
        this.setResizable(false);

        // Define how the frame exits (Click the Close Button)
        // Without this Java will eventually close the app
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Define the title for the frame
        this.setTitle("User defined Frame title");

        // Makes the frame show on the screen
        this.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new WindowProperties();
            }
        });
    }
}
