# C# focus
- We will use our [FoxDraw.cs](./boilerplates/FoxDraw.cs) class in the following examples
  - But you can write your own until the end of the week! :)
- When reading through the specification and the stories keep this in mind.
- Here's an example, it contains
  - a big drawable canvas
  - and handling pressing keys, for moving your hero around
  - be aware that these are just all the needed concepts put in one place
  - you can separate anything anyhow  
  - `RPGGame` is the namespace in the following example

```xml
<Window x:Class="RPGGame.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:RPGGame"
        mc:Ignorable="d"
        Title="MainWindow" Height="551" Width="1008" KeyDown="WindowKeyDown">
    <Grid>
        <Canvas Name="canvas"/>
    </Grid>
</Window>
```

```csharp
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
        var foxDraw = new FoxDraw(canvas);
    }

    private void WindowKeyDown(object sender, KeyEventArgs e)
    {
        if (e.Key == Key.Left)
        {
            Console.WriteLine("To the left!");
        }

        if (e.Key == Key.Right)
        {
            Console.WriteLine("To the right!");
        }
    }
}
```

- You can add images with FoxDraw like this:
  - `foxDraw.AddImage(imagesource, x, y);`
- Steps of adding an Image to your project:
  - Add an `Assets` folder to your project
  - Insert image files in it
  - Set the `Copy to OutPut Directory` property of the image to `Copy Always`

```csharp
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
        var foxDraw = new FoxDraw(canvas);
        foxDraw.AddImage("./Assets/boss.png", 0, 0);
    }
}
```
