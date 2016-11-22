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
|SwingQuickGuide (tutorialspoint)|https://www.tutorialspoint.com/swing/swing_quick_guide.htm||
|JLabel - summary (tutorialspoint)|https://www.tutorialspoint.com/swing/swing_jlabel.htm||
|JButton |https://www.tutorialspoint.com/swing/swing_jbutton.htm||
|JText |https://www.tutorialspoint.com/swing/swing_jtextfield.htm||
|JTextArea| https://www.tutorialspoint.com/swing/swing_jtextarea.htm||
|JScrollBar - like ScrollPane?|https://www.tutorialspoint.com/swing/swing_jscrollbar.htm||

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
