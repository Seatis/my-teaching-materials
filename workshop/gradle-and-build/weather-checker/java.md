# Weather checker

 - use library for argument parse
 - use library for CSV parse
 - use [Retrofit](square.github.io/retrofit/) for API calls
 - Here is a simple weather API: https://simple-weather.p.mashape.com/weather
 - use the [`data.csv`](data.csv) contains: country code, latitude, longitude and country name


## Cases

1.
     - Given the terminal opened in the project directory
     - When the application ran with the `-c HU` argument
     - Then it should write the current weather in Hungary to the standard output.

2.
    - Given the terminal opened in the project directory
    - When the application ran with the `-c HU --compare AT` argument
    - Then it should write the weather difference between Hungary and Austria to the standard output.

    *eg there is 20C in Hungary and 15C in Austria, then it should write 5C.*
