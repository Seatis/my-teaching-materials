/**
 * File I/O: Working with 2 files
 * 
 * This is an extension of the previous stuff you've been doing, but let's skip doing stuff with
 * taking input data (unless you want to).
 * 
 * In this exercise, we're going to merge 2 files that are already sorted.  This actually was
 * one of the first types of computer programs created in the 1950s and was a core business at 
 * one time for IBM.  https://en.wikipedia.org/wiki/IBM_card_sorter and look at the images.  
 * Note that the mechanical versions trace back to 1908; but IBM started in 1928.  But I digress.
 *
 * So you need to open 2 file streams in.  Supplied as W018_A.dat and W018.B.dat and merge them.
 * 
 * How?  Imagine a zipper.  Well almost a zipper.  Here's a sample of the sorted data; the top
 * row is the starting point in the file.
 *
 * W018A                W018B
 * ======               =====
 * 1234                 454
 * 1288                 1238
 * 1291                 1280
 *                      1299
 *
 *
 * You read the 2 sets into separate "buffers", say bufferA and bufferB.
 * 
 * Then you ask, who is less than bufferA, or bufferB.
 *
 * Whichever it is, that value is written to output and another value is retrieved.
 * 
 * So, to start bufferA=1234, bufferB=454... 
 * bufferB < bufferA so write 454 to output and get the next bufferB (1238)
 * Next loop, who is less?  bufferA=1234, bufferB=1238.  
 * bufferA < bufferB so write 1234 and refresh bufferA
 *
 * This continues until 1 or both of input streams is EOF.
 * 
 * This means that when testing, it's not just that you ask is bufferA < bufferB, you also
 * need to check if they are empty.
 * 
 * Also, what happens if they are equal?
 *
 * This is, though ancient, a typical sort of programming problem.  It's referred to as 
 * creating an algorithm.
 *
 **/

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class Workshop18 {
// you figure out; but hardcode the input and output files.  

}


