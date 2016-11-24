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

### Material Review
- ActionListener
- KeyListener
- MouseListener


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
- Initialize it to 500x500 non resizable and put it center.
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
*Wrapper app for your previous tasks*
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
![alt tag](https://raw.githubusercontent.com/greenfox-academy/teaching-materials/kicsen_java-gui_module_2/java-gui/2-swing-more/complexpanel.png)
- You need left and right JPanel.
- Set layout of left panel to GridLayout.
- Add buttons to left panel.
- Set layout of right panel to BorderLayout.
- Add buttons to right panel too.
- Set layout of conctet pane to FlowLayout and add panels to conctet pane.
- It is done.

```java
        left.setLayout(new GridLayout(3, 1, 5, 5));
        ...
        right.setLayout(new BorderLayout(10, 10));
        ...
        getContentPane().setLayout(new FlowLayout());
```

## Individual Workshop Review
Neatness counts in coding.

Please be sure you're well acquainted with the guidelines on coding: [GreenFox Academy's Java Styleguide](../../styleguide/java.md)

Key questions to consider:
- Are the directory structure and the names of the files correct?
- Are the includes placed at the top of the file?
- Does the code follow the right level of indentation?
- Are all of the brackets positioned correctly?
- Are the whitespaces where they should be; and not where they shouldn't?
- Is the code *pithy* (meaning to the point, not superfluous or un-necessary)?
  - Not using extra variables (unless needed to understand the logic)
  - Not confusingly or overly commented
  - Does the computation instead of repeating stuff (aka *code duplication*)?
  - Does not contain empty blocks
  - Non repetitive and where needing to repeat a block instead, carved out to a function?
- Are there un-used variables - added during development but later made surplus to requirements through simplification?
- Is the commentary in the code at the right level?
  - Can one deduce the purpose of a block from the variable naming combined with the explanation
  - Are there *Watch outs* warnings just in case somebody later maintains the code and needs to beware of something tricky (or not obvious)?
- Are the data types used right for the purpose
- Is the "commit message" meaningful?
- Do the names conform to the Styleguide?
    - Classes: UpperCamelCase
    - variables: lowerCamelCase
    - functions: lowerCamelCase(paramsLowerCase)
