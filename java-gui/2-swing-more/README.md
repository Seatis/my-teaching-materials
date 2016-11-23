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

### Menü

### Draw to image

### Workshop wrapper

### Complex layout
