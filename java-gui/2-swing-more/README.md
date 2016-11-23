# Java Swing Listener/Event Handling

Having looked at how data is displayed, in this unit we look at how the events are communicated back to the program.  This leverages both the JFrames we learnt earlier and Interfaces.  Her, you'll now see how you (as a programmer) hook into the Java engine to tell it what to call if an event happens.  You'll be registering your code to be called by the Interface implemented.

Also, in this unit we set up for the Demo Project for the week.


## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[GUI Event Handling (Basic listener such as mouse, key & window), shortcut was to use Interfaces (Bana.21)](https://www.youtube.com/watch?v=3ifwR5feRQI)|11:00|


### Optional
| Material | Time |
|:-------- |-----:|
|[Form elements in Java Swing (Bana.22)](https://www.youtube.com/watch?v=qVdRxODXBcU)|13:56|
|[Handling them (Bana.23)](https://www.youtube.com/watch?v=wApG8SHBJ24)|11:03|

## Workshop

### Event counter
*Create a new or upgrade our counter which able to count mouse, keyboard and window events according to training material.*

- Initialize our event counter frame and put it to center of the screen.
- You need three label for counters (Mouse event counter, Key event counter, Window event counter) and you should add a JTextField too.
- Like the previous counter app you need counter variables (fields).
- Create ListenForKeys listener which implements KeyListener interface and increment the key event counter and update text of counter label too. You can count both events. (press and release). 
- Add this listener to text field.
- Create ListenForMouse listener which implements MouseListener interface and increment the mouse event counter and update text of counter label. You should handle multiple clicks.
- Add the ListenForMouse listener to JFrame.
- Create ListenForWindow listener which implements WindowListener interface and increment the window event counter and update text of counter label too. You sould handle activate, deactivate, deiconified, iconified, opened state changes.
- Add the ListenForWindow listener to JFrame.

```java
textField.addKeyListener(listenForKeys);
this.addMouseListener(listenForMouse);
this.addWindowListener(listenForWindow);
```

### Menu
*Application with menu and exit menu item*

- Create WrapperApp class which extends JFrame and implements ActionListener
- Initilaize it to 500x500 non resizable and put it center.
- You need JMenuBar, JMenu, and JMenuItem fields.
- MenuBar >> File >> Exit (build menu hierarchy)
- Call 'setJMenuBar(menubar);' in constructor of your frame.
- Add action listener to exit menu item and implement it to terminate the application.

```java
System.exit(0);
```

### Draw to image
*Show an image in Menu app and paint it a little bit*

- Create an ImagePanel class which extends JPanel.
- Download the image.jpg from repository and add it to the root of your project.
- Load it in the constructor of ImagePanel.
```java
Toolkit.getDefaultToolkit().createImage("image.jpg");
```
- Add panel to frame of Menu app.
- You should Override the paintComponent method of JPanel and inside of this block you can draw to this component.
```java
@Override
    public void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        requestFocus();
        graphics.drawImage(image, 7, 25, this);
    }
```
- If it is done, you should make some fun for example in the picture below. Let your imagination free!
![alt tag](https://raw.githubusercontent.com/greenfox-academy/teaching-materials/kicsen_java-gui_module_2/java-gui/2-swing-more/image_example.png)
- Use setColor, setFont, drawString, drawOval, fillRect methods of graphics.

```java
        // Example
        graphics.setColor(Color.BLACK);
        graphics.setFont(new Font("Ariel", Font.BOLD, 20));
        graphics.drawString("Heroes of Might and Magic V", 110, 420);

        graphics.setColor(new Color(200, 200, 100));
        graphics.drawOval(270, 45, 70, 120);

        graphics.setColor(Color.BLUE);
        graphics.fillRect(280, 100, 50, 10);

        graphics.setColor(Color.PINK);
        graphics.fillOval(230, 210, 15, 15);
        graphics.fillOval(290, 210, 15, 15);
```

### Workshop wrapper (Optional)
- Create differnet classes for your previous Swing tasks which extends from JPanel.
- Build menu hierarchy for these. (Say Hello to all the world, Counter app, UI Controls, Event counter, Draw to image)
- Set menu click event handlers to open slected task in main window.
```java
        if (event.getSource() == menuItemImage) {
            getContentPane().add(new ImagePanel());
        }
```
- Now you can present your previous UI work in single application.

### Complex layout (Optional)
