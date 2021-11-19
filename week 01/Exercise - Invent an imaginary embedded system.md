# Assignment Requirements
* Cortex-M processor(s?)
* A button that causes an interrupt
* At least three of (ADC, DAC, PWM LED, Smart LED, LCD, sensor, BLE)
* Serial port input and output for debugging/cli
* Some algorithmic piece that makes it interesting. That includes a state machine.
* 3-6 sentences, diagram optional


Personal Goals
========

* Try out the internet kit on an STM32 platform using ethernet.
* Try out high end STM32s. I've done a bunch on low end M0s with 2K of RAM and 16K flash, and some midrange M3 and M4.
* Try 2D graphics UI on an MCU. I've spit out pixels to an LCD / OLED for displaying information, but haven't done an interactive UI.
* Make something I can use, but moreso something that I want that doesn't exist yet.

Inspiration / Discovery Board
==============

For inspiration, I picked up a high end [STM32H745I-DISCO](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html) discovery board (thanks for a good excuse to get more dev boards 🤣) with a nice touch screen LCD and ethernet, and took a look at what was on it and what I could make with it that would solve some things on my wishlist.

The [STM32H745I-DISCO](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html) has a ton of other peripherals too, lots of stuff to play with and options for adding features. The STM32H745XIH6 has 2 cores, an M7 and an M4, and I'm now curious how the dual core stuff works.

# My Embedded Project

I would like to have something on my desk that helps me keep track of calendar appointments/events, and for tracking time on various projects.

While there are a multitude of computer/phone apps that do these things, they run on a general purpose system and often suffer because of it. Some examples: audio alerts for calendar events might play on a headset I'm not wearing, task tracker apps tend to get burried under other windows and forgotten, and my phone is muted and put away when I'm trying to focus.


### Calendar

* Always see my calendar, so I can see if something important is coming up. 
* Audio alerts and bright LEDs in case I'm focused on something and/or wearing headphones.
* Something to detect if I'm not there, so it's not incessently beeping to an empty room.

### Task Tracker

* Task Tracker, like a cross between a stopwatch and log book for tracking project and/or billable hours. Something physical that is aways visible. I wouldn't really want to type out detailed notes on the touchscreen, but a selection of pre-defined projects/tasks could still be useful.
* Something to detect if I'm not there, so it would stop an active tracker after some timeout.

### Hardware

* Ethernet for internet connectivity. The device will need to talk with an API to retrieve calendar information and read and write task information. If feasible, using Google Calendar & Sheets for this data.
* A touchscreen LCD for a user interface. It will display calendar and task information, and accept input for dismissing alerts and for controlling the Task Tracker.
* A physical button for swithing modes or acknowleging alerts.
* External speaker(s) for audio alerts driven from the on-board audio codec.
* Either the onboard user LEDs or external LEDs for visual alerts (in case I'm wearning headphones).
* A sensor for detecting presence. This might be done with the on-board mic, a PIR motion sensor, a distance sensor, a piezo attached to the desk surface to detect small vibrations/sounds from movement or keypresses, or some combination of these.


### Stretch goal: Pretty Audio Visualizer

It's hard to resist putting the mic and LCD to use. Would be cool to have it become a pretty audio visualizer for the desk after hours.

### Stretch goal: Photo slideshow

It would be nice to display something inspirational during work, or to double as a photo slideshow after hours. Perhaps pulling from a feed and caching locally, or from a directory that is loaded by connecting USB as a mass storage device.

With 4G of flash, a hardware JPEG codec, and a nice LCD, this could display a slideshow of images. 

### Stretch goal: Speech to text for notes

Notes for projects / tasks could be added by streaming audio from the mic through a transcription service.
