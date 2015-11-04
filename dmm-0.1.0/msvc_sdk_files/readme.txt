##########################################################################
#                                                                        #
# Title:         Doom3 mods with Visual C++ 6..                       	 #
# Description:   With This tutorial you'll be able to compile            #
#                the Doom3 mod Source with Visual C++ 6 and              #
#                the free available MS-Toolkit 2003.                     #
#                                                                        #
# Autor:         TTK-Bandit                                              #
#                                                                        #
##########################################################################


I. What you need:
  1. The Doom 3 Mod Source:
     http://www.iddevnet.com/

  2. The MS-Toolkit:
     http://msdn.microsoft.com/visualc/vctoolkit2003/

  3. Informations how to work with .pk4 files..
     Sry I don't have any link atm. Just ask someone who knows ;)


II. Installation:
  1. Install the MS-Toolkit first..
  2. Run Visual C++ 6 and open up the 'Tools' Menu and select 'Options'

  3. Select the tab 'Directories'

  4. In the Left Combobox, select Include files and add a new item
     with the path to the include directory of vc2k3. For example:
     c:\programs\VC2003Toolkit\Include
     move that new item with the arrows to the top position.

  5. repeat 4. with the Combobox items 'executable files' and 'library files':
     c:\programs\VC2003Toolkit\bin
     c:\programs\VC2003Toolkit\lib

  6. Install the Doom3Source (select your doom3 folder, and the source will be placed in Doom3\src)
    of course, after installation you can rename it to whatever you want ;)

  7. Into the source directory (default: Doom3\src) copy the content of this package.

  This directory will now be the source of every new mod. So don't change anything inside it!


III. Create a new mod:
  1. Copy the content of the source directory to a place you like.
     I would recommend f.ex. Doom3\Modname\Source

  2. Run Visual C++ 6 and open the workspace in Doom3\Modname\Source.

  3. Edit your code. (for the first test, here's an example: http://www.iddevnet.com/doom3/code.php)

  4. Compile it.

  4. Now copy the game00.pk4 from the Doom3\base dir to your mod-dir,
     and put the new gamex86.dll inside it (overwrite the existing gamex86.dll).
     This is necessary, to run Doom3 with your dll correctly.
     However the name of the .pk4 is not relevant,  so you can rename it if you want ;)

IV. Run the mod:
  1. Run your mod with "Doom3.exe +set fs_game Modname"


If you have any questions, just ask where you found this file ;)
Have Fun!
Bandit.
