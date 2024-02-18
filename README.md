# DIY Filming Accessories

### The Boom
I became frustrated with the limitations of tripods in my small shop space and after a few sources of inspiration started working on a balanced arm boom.
The boom is mounted to a single point, but the mount can be reused or dovetailed into a duplicated mounting point.

Projects that I felt most influenced this camera arm:
Two from Marius Hornberger  
https://www.youtube.com/watch?v=7V0NvNZmvXU
https://youtu.be/p68Y1e4acF4?si=vS-Dpx9isLgJdFHX

This massive Gantry from Inheritance Machining  
https://www.youtube.com/watch?v=t1sXvMY_vAw

And a series from The Meandrous Engineer  
https://www.youtube.com/watch?v=fble2ifR0NI

A group of .3mf files and an export of the Fusion 360 (.f3d) have been included.

### The Dolly
Real dollys are expensive, and the ones that are "smart" are much _more_ expensive.
This one is made almost entirely of 3d printed parts, extremely cheap components, and wood.

I used a knockoff arduino mega, a knockoff ILI9341 touchscreen, and some small and inexpensive stepper motors.


The necessary arduino files are {here}
And the models can be found {here}

Wiki information for the specific touch screen I used can be found  
http://www.lcdwiki.com/3.2inch_SPI_Module_ILI9341_SKU:MSP3218

I originally started with much too weak Stepper motors.  
https://www.amazon.com/gp/product/B07YRHX73L/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1

And a related tutorial I used is here:  
https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/

After the initial test and finding that they would not perform the required action, I switched to these nema 17 stepper motors.  
https://www.amazon.com/dp/B00PNEQKC0?psc=1&ref=ppx_yo2ov_dt_b_product_details  
https://www.amazon.com/dp/B00PNEQ79Q?psc=1&ref=ppx_yo2ov_dt_b_product_details

L298N motor drivers  
Testing with these motor drivers resulted in jittery movement and drop in power when controlled in tandem.  
They also got super hot.  
https://www.amazon.com/dp/B00NJOTBOK?psc=1&ref=ppx_yo2ov_dt_b_product_details

And these related tutorial from the same place  
https://lastminuteengineers.com/stepper-motor-l298n-arduino-tutorial/

TB6600 stepper drivers  
I moved on to a more familiar CNC style controller  
https://www.amazon.com/gp/product/B088CRCMP7/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&th=1

And used these tutorials:  
https://www.makerguides.com/tb6600-stepper-motor-driver-arduino-tutorial/

A group of .3mf files and an export of the Fusion 360 (.f3d) have been included.
In addition some of the sub-assembly projects have been included for further customation.
