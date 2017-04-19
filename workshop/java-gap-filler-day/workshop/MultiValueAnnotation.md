# Multi Value Annotation
 - Add the `String classification()` value to the previously created @interface and set it's default value to `"TFT"`
 - Correct the classification value so that every wide screen is `"LCD"`
 - Create 1 enum Property to the Screen class, where you set the size of the screen:
   - `enum Size {INCH15, INCH17, INCH19, INCH21, INCH23, INCH25, INCH29, INCH34}`
 - Instantiate 3 from each extended Screen class (9 at all), and print them everything you know about them 