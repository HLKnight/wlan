# ---------------------------- WLAN SCAN PROJECT ------------------------------

This project scans for wireless networks with the Raspberry Pi then displays
on the screen information about their ESSID, channel, level in graphs.

# ---------------------------- Table of Contents ------------------------------

1. Configuration instructions
2. Installation instructions
3. Operating instructions
4. File manifest
5. Copyright and license
6. Contact information
7. Known bugs
8. Troubleshooting
9. Changelog

# -----------------------------------------------------------------------------

1. Configuration instructions

	This program does not need any configuration to run.

# -----------------------------------------------------------------------------

2. Installation instructions

	2.1. Get installation files
	
		Enter the folder where you want to put the program to and enter the
		command "git clone https://github.com/HLKnight/wlan".
			
	2.2. Install
	
		Run makefile by entering command "make".
		

# -----------------------------------------------------------------------------

3. Operating instructions

	The program can be run by command "./WLAN.a".
	
	Exit the program by pressing "Ctrl + C".
	
# -----------------------------------------------------------------------------

4. File manifest

	graph.c
	graph.h
	main.c
	makefile
	screen.c
	screen.h
	setting.h
	text.c
	text.h
	wifi.c
	wifi.h
	
# -----------------------------------------------------------------------------

5. Copyright and license

	Copyright (C) 2018	Nhat Minh Nguyen

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
                
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
# -----------------------------------------------------------------------------

6. Contact information

	Nhat Minh Nguyen
	
		Vaasa University of Applied Sciences
		School of Technology
		Information Technology
		Wolffintie 30
		65200 VAASA
		FINLAND
		
		Phone: +358 418 097 204
		Email: e1700681@edu.vamk.fi
		
# -----------------------------------------------------------------------------

7. Known bugs

	24.04.2018
	
	-	The program did not display properly the networks whose ESSIDs are
		empty.
	
# -----------------------------------------------------------------------------

8. Troubleshooting

	<empty>
	
# -----------------------------------------------------------------------------

9. Changelog

	24.04.2018
	
	-	Fixed the bug that the program did not display properly the networks
		whose ESSIDs are empty.

# -----------------------------------------------------------------------------
