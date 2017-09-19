using System;
using System.Windows;
using GreenFox;

namespace StarryNight
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            // draw the night sky:
            // - The background should be black
            // - The stars can be small squares
            // - The stars should have random positions on the canvas
            // - The stars should have random color (some shade of grey)

        }
    }
}