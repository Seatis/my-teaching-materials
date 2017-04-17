# Lottery filter

 - create a new gradle project
 - add [jopt-simple](http://pholser.github.io/jopt-simple/examples.html) and [opencsv](http://opencsv.sourceforge.net/) as dependencies
 - and also use them ;)
 - use your beloved [otos.csv](../../file-manipulations/lottery/otos.csv) file
 - feel free to any additional features


## Short description

There are three available arguments: `-y <year>`, `-f <file>` and `-o <file>`. `-y` for the year to be filtered, `-f` for the input and `-o` for the output file. Also these can be stacked so `-y 2000 -f otos.csv -o result.csv` is valid.

*It should read the data from otos.csv, and write the data from 2000 to result.csv*

## Cases

1.
    - Given the terminal opened in the project directory
    - When the application ran with the `-y 2015` argument
    - Then it should read the data from `otos.csv`
    - And write every data from 2015 to `output.csv`

2.
    - Given the terminal opened in the project directory
    - When the application ran with the `-y 2011 -f input.csv` argument
    - Then it should read the data from `input.csv`
    - And write every data from 2011 to `output.csv`

3.
    - Given the terminal opened in the project directory
    - When the application ran with the `-y 2003 -o greenfox.csv`
    - Then it should read the data from `otos.csv`
    - And write every data from 2003 to `greenfox.csv`
