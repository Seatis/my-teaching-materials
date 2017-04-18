# Single Value Annotation
 - Extend 2 class from the previously created screen class
   - class TFTMonitor
   - class LCDMonitor
 - Make sure the annotations are inherited also
 - Add the `String classification()` value to the @interface and set it's default value to "TFT"
 - Correct the classification value if necessary in the inherited classes(LCDMonitor's value is "LCD")