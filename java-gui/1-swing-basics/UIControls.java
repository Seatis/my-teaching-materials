package workshop;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by kicsen on 2016. 11. 22..
 */
public class UIControls extends JFrame implements ActionListener {
    public static final String TEXT_TITLE = "Text : ";
    public static final String MEMORY_TITLE = "Memory : ";

    protected final JPanel panel = new JPanel();
    protected final JTextField textField = new JTextField("Type here", 30);
    protected final JLabel textLabel, memoryLabel;
    protected final JButton clearMemoryButton;

    public UIControls() {
        setTitle("UI Controls sample");
        setSize(400, 200);
        setResizable(false);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Set the boxLayout to be Y_AXIS from top to down
        BoxLayout boxLayout = new BoxLayout(panel, BoxLayout.Y_AXIS);

        panel.setLayout(boxLayout);
        // Set border for the panel
        panel.setBorder(new EmptyBorder(new Insets(20, 20, 20, 20)));

        textLabel = new JLabel(TEXT_TITLE);
        memoryLabel = new JLabel(MEMORY_TITLE);
        clearMemoryButton = new JButton("Clear memory");
        textField.addActionListener(this);
        clearMemoryButton.addActionListener(this);
        clearMemoryButton.setEnabled(false);

        panel.add(textField);
        // Add separator space after text field
        panel.add(Box.createRigidArea(new Dimension(0, 20)));
        panel.add(textLabel);
        // Add smaller separator space after text label
        panel.add(Box.createRigidArea(new Dimension(0, 10)));
        panel.add(memoryLabel);
        panel.add(Box.createRigidArea(new Dimension(0, 10)));
        panel.add(clearMemoryButton);
        add(panel);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent actionEvent) {
        if (actionEvent.getSource() == clearMemoryButton) {
            memoryLabel.setText(MEMORY_TITLE);
            clearMemoryButton.setEnabled(false);
        } else {
            String previousText = textLabel.getText();
            String previousValue = previousText.split(":")[1].trim();
            textLabel.setText(TEXT_TITLE + textField.getText());
            memoryLabel.setText(MEMORY_TITLE + previousValue);
            if (previousValue != null && !previousValue.isEmpty()) {
                clearMemoryButton.setEnabled(true);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new UIControls();
            }
        });
    }
}
