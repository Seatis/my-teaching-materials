using System;
using System.Windows;
using GreenFox;

namespace LinePlayQuarters
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            // divide the canvas into 4 parts
            // and repeat this pattern in each quarter:
            // [https://github.com/greenfox-academy/teaching-materials/blob/master/workshop/drawing/line-play/r1.png]

        }
    }
}