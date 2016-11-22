# Java Swing Basics
*Swing is a Java GUI framework*

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Swing Intro (Bana.20)](https://www.youtube.com/watch?v=3XB3in9Xqy8)|15:23|
|[JButtons and ActionListeners - Java GUI Building Tutorial #3](https://www.youtube.com/watch?v=lB0k6HuVgs8)|17:24|
|[Creating First Java Swing GUI Application with IntelliJ IDEA IDE](https://www.youtube.com/watch?v=5vSyylPPEko)|10:01|


### Optional
| Material | Time |
|:-------- |-----:|
|[SwingQuickGuide (tutorialspoint)](https://www.tutorialspoint.com/swing/swing_quick_guide.htm)||
|[JLabel - summary (tutorialspoint)](https://www.tutorialspoint.com/swing/swing_jlabel.htm)||
|[JButton](https://www.tutorialspoint.com/swing/swing_jbutton.htm)||
|[JText](https://www.tutorialspoint.com/swing/swing_jtextfield.htm)||
|[JTextArea](https://www.tutorialspoint.com/swing/swing_jtextarea.htm)||

## Material Review
- *Frames* - `JFrame` class
  - fields:
      - size (width, height)
      - visible
      - location (x, y)
      - resizeable
      - title
  - methods:
      - getters and setters
      - `.setLocationRelative()`
      - `.setDefaultClose(JFrame.EXIT_ON_CLOSE)`
- `awt.Toolkit`
  - what is a static?
  - static `.getDefaultToolkit()`
  - `.getScreenSize()`
- `Dimension` - holding the sizes of an object
- * Panels* - JPanel
  - `.add(object)` - the `object` would be the specific gui item created
- *GUI items on Panels*
  - common fields
      - text
      - tooltiptext
      - borders, fill the area
  - common methods
    - getters and setters
    - `.setColumns()`
    - `.requestFocus(boolean)` - the item to highlight
  - Types of Controls
    - `JLabel(String)`
    - `JButton (String)`
    - `JTextField(String defaultResponse, int width)`
- `ActionListener` interface
    - again, what is an interface?
    - how to use this?
    - `actionPerformed(ActionEvent event)`
- *Optional items*
    - `JTextArea(int, int)`
      - `.setLineWrap(boolean)`    
      - `.setWrapStyleWord(boolean)`
      - `.getLineCount()` - get the number of /n's
      - `.append(String)` - what to add to the JTextArea
    - `JScrollPane(control to which to associate, int VERTICAL, int HORIZONTAL )` - the control identified will be the one affected by the scroll bars
      - constants, default values
      
## Workshop
### Hello World
*Create first Hello World Swing application*
- Create HelloWorld class
- Add JFrame and JPanel
- Set title of JFrame
- Set visible the JFrame
- How to run a program

```java
public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new HelloWorld();
            }
        });
    }
```


*HelloWorld text*
- Add JLabel for HelloWorld text
- Add label to panel

### Customized Hello World
- Change the previous application to greet you. 
- Set DefaultCloseOperation

### Say Hello to all the world
*You are very happy and would say hello in different languages*
- Add new labels to your HelloWorld panel with Helo in different languages iteratively. (use for)
- Use the following greetings:
```java
String[] hellos = {"Mirëdita", "Ahalan", "Parev", "Zdravei", "Nei Ho", "Dobrý den", "Ahoj", "Goddag", "Goede dag, Hallo", "Hello", "Saluton", "Hei", "Bonjour",
                "Guten Tag", "Gia'sou", "Aloha", "Shalom", "Namaste", "Namaste", "Jó napot", "Halló", "Helló", "Góðan daginn", "Halo", "Aksunai", "Qanuipit", "Dia dhuit",
                "Salve", "Ciao", "Kon-nichiwa", "An-nyong Ha-se-yo", "Salvëte", "Ni hao", "Dzien' dobry", "Olá", "Bunã ziua", "Zdravstvuyte", "Hola", "Jambo", "Hujambo", "Hej",
                "Sa-wat-dee", "Merhaba", "Selam", "Vitayu", "Xin chào", "Hylo", "Sut Mae", "Sholem Aleychem", "Sawubona"};
```

### Window position and properties
*Fixed size window to center of your screen*
- Modify the previous app to open in the center of your screen with 400x400 non resizable window.
- JFrame
  - setSize
  - setResizable
  - setDefaultCloseOperation
  - setLocation

- AWT Toolkit
  - getScreenSize
  - get the width and height of window
  - calculate the center of screen
  - center the window
![alt tag](https://raw.githubusercontent.com/greenfox-academy/teaching-materials/kicsen_java-gui_module/java-gui/1-swing-basics/centeredwindow.png)

### Counter app
*Simple app which counts all button clicks*
- Create Counter class
- Initialize JFrame and JPanel
- Add a label to panel to counter text and a button too.
- Implement ActionListener interface
  - ActionListener implementation increment a int field and set it to conuter label.
- Add ActionListener to button.

![alt tag](https://raw.githubusercontent.com/greenfox-academy/teaching-materials/kicsen_java-gui_module/java-gui/1-swing-basics/CounterApp.png)

*Reset counter*
- Add another button to Counter app which can reset the counter.

### UI Controls
*Shows the value of input text box*
- Create UIControls class which extends JFrame
- Initialize JFrame and JPanel
- Add a JTextField and two JLabel to panel
- We have a JLabel to show input text and another to show memory (previous value).
- Add and implement ActionListener interface to UIControls class.
- actionPerformed function put the value of JTextField to first JLabel.
- add addActionListener to JTextField

*Shows and remembers the value of input text box*
- Extends the implementation of actionPerformed function to copy the own content to memory label before shows value of input box.

*BoxLayout (Optional)*
- Format the UI Controls app with BoxLayout layout manager.

Handy tools:
  - JPanel.setBorder
  - JPanel.setLayout
```java
Box.createRigidArea(new Dimension(0, 20));
```
*Clear memory (Optional)*
- Add a button which can clear the memory label.
- Disble the clear button when memory is empty.

![alt tag](https://raw.githubusercontent.com/greenfox-academy/teaching-materials/kicsen_java-gui_module/java-gui/1-swing-basics/UIControls.png)

### Image app
*Custom image on panel*
- Create ImageApp class which extends JFrame
- Initialize JFrame and JPanel
- Load image

```java
Toolkit.getDefaultToolkit().createImage("image.jpg");
```

- Draw image to panel in paintComponent function
```java
@Override
    public void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        requestFocus();
        // Draw your image
    }
```
