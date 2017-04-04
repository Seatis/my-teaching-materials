# Java focus
- Launching the game is running the `Main` class' `main()` method.
- Don't mess around with layouts, draw exactly everything how you want to in one `paint()` method.
    - The specification and the stories *are not* designed for working with layouts
    - but to work well with drawing on a canvas
    - Note: of course the project is doable in any case and using any architecture, just easier to follow the stories when using only one component (eg. `JComponent`)
    - This doesn't mean you have to put everything in one class. You should create and use multiple classes, just not swing components but yours with your own draw method.
- When reading through the specification and the stories keep this in mind.
- Here's an example of a big drawable canvas with one image painted on it:
```java
public class Board extends JComponent {
    public Board() {
        // set the size of your draw board
        setPreferredSize(new Dimension(720, 720));
        setVisible(true);
    }

    @Override
    public void paint(Graphics graphics) {
        super.paint(graphics);
        // here you have a 720x720 canvas
        // you can create and draw an image using the class below e.g.
        PositionedImage image = new PositionedImage("yourimage.png", 300, 300);
        image.draw(graphics);
    }
}
```
- You can use this image class as a base:
```java
public class PositionedImage {

    BufferedImage image;
    int posX, posY;

    public PositionedImage(String filename, int posX, int posY) {
        this.posX = posX;
        this.posY = posY;
        try {
            image = ImageIO.read(new File(filename));
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void draw(Graphics graphics) {
        if (image != null) {
            graphics.drawImage(image, posX, posY, null);
        }
    }
}
```
