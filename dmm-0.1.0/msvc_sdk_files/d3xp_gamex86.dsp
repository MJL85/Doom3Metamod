# Microsoft Developer Studio Project File - Name="d3xp_gamex86" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=d3xp_gamex86 - Win32 Debug with inlines and memory log
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "d3xp_gamex86.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "d3xp_gamex86.mak" CFG="d3xp_gamex86 - Win32 Debug with inlines and memory log"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "d3xp_gamex86 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "d3xp_gamex86 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "d3xp_gamex86 - Win32 Debug with inlines" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "d3xp_gamex86 - Win32 Debug with inlines and memory log" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "d3xp_gamex86 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release/d3xp_gamex86"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release/d3xp_gamex86"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G6 /W3 /GR /GX /Zi /Ot /Og /Oi /Oy /Ob2 /Gy /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GF /c
# ADD CPP /nologo /G6 /W3 /GR /GX /Zi /Ot /Og /Oi /Oy /Ob2 /Gy /D "NDEBUG" /D "_D3XP" /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "CTF" /FD /GF /c
# ADD BASE MTL /nologo /win32
# ADD MTL /nologo /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Release/idLib.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Release/idLib.lib /nologo /dll /machine:I386 /out:"Release/gamex86.dll"

!ELSEIF  "$(CFG)" == "d3xp_gamex86 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "debug"
# PROP BASE Intermediate_Dir "debug/d3xp_gamex86"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "debug"
# PROP Intermediate_Dir "debug/d3xp_gamex86"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GR /GX /ZI /Od /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# ADD CPP /nologo /W3 /GR /GX /ZI /Od /D "_DEBUG" /D "_D3XP" /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "CTF" /FD /GZ /c
# ADD BASE MTL /nologo /win32
# ADD MTL /nologo /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Debug/idLib.lib /nologo /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Debug/idLib.lib /nologo /dll /debug /machine:I386 /out:"debug/gamex86.dll"

!ELSEIF  "$(CFG)" == "d3xp_gamex86 - Win32 Debug with inlines"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "debug"
# PROP BASE Intermediate_Dir "debug/d3xp_gamex86"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "debug"
# PROP Intermediate_Dir "debug/d3xp_gamex86"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GR /GX /ZI /Od /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_INLINEDEBUG" /D "_MBCS" /FD /GZ /c
# ADD CPP /nologo /W3 /GR /GX /ZI /Od /D "_DEBUG" /D "_INLINEDEBUG" /D "_D3XP" /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "CTF" /FD /GZ /c
# ADD BASE MTL /nologo /win32
# ADD MTL /nologo /win32
# ADD BASE RSC /l 0x409 /v
# ADD RSC /l 0x409 /v
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Debug/idLib.lib /nologo /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Debug/idLib.lib /nologo /dll /debug /machine:I386 /out:"debug/gamex86.dll"

!ELSEIF  "$(CFG)" == "d3xp_gamex86 - Win32 Debug with inlines and memory log"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "debug"
# PROP BASE Intermediate_Dir "debug/d3xp_gamex86"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "debug"
# PROP Intermediate_Dir "debug/d3xp_gamex86"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GR /GX /ZI /Od /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "ID_REDIRECT_NEWDELETE" /D "ID_DEBUG_MEMORY" /D "ID_DEBUG_UNINITIALIZED_MEMORY" /D "_MBCS" /FD /GZ /c
# ADD CPP /nologo /W3 /GR /GX /ZI /Od /D "_DEBUG" /D "ID_REDIRECT_NEWDELETE" /D "ID_DEBUG_MEMORY" /D "ID_DEBUG_UNINITIALIZED_MEMORY" /D "_D3XP" /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "CTF" /FD /GZ /c
# ADD BASE MTL /nologo /win32
# ADD MTL /nologo /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Debug/idLib.lib /nologo /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Debug/idLib.lib /nologo /dll /debug /machine:I386 /out:"debug/gamex86.dll"

!ENDIF 

# Begin Target

# Name "d3xp_gamex86 - Win32 Release"
# Name "d3xp_gamex86 - Win32 Debug"
# Name "d3xp_gamex86 - Win32 Debug with inlines"
# Name "d3xp_gamex86 - Win32 Debug with inlines and memory log"
# Begin Group "Game"

# PROP Default_Filter ""
# Begin Group "AI"

# PROP Default_Filter ""
# Begin Source File

SOURCE=d3xp\ai\AAS.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AAS.h
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AAS_debug.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AAS_local.h
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AAS_pathing.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AAS_routing.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AI.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AI.h
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AI_events.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AI_pathing.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\ai\AI_Vagary.cpp
# End Source File
# End Group
# Begin Group "Anim"

# PROP Default_Filter ""
# Begin Source File

SOURCE=d3xp\anim\Anim.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\anim\Anim.h
# End Source File
# Begin Source File

SOURCE=d3xp\anim\Anim_Blend.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\anim\Anim_Import.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\anim\Anim_Testmodel.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\anim\Anim_Testmodel.h
# End Source File
# End Group
# Begin Group "GameSys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=d3xp\gamesys\Class.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\Class.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\DebugGraph.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\DebugGraph.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\Event.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\Event.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\NoGameTypeInfo.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\SaveGame.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\SaveGame.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\SysCmds.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\SysCmds.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\SysCvar.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\SysCvar.h
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\TypeInfo.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\gamesys\TypeInfo.h
# End Source File
# End Group
# Begin Group "Physics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=d3xp\physics\Clip.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Clip.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Constant.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Constant.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Drag.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Drag.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Field.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Field.h
# End Source File
# Begin Source File

SOURCE=.\d3xp\physics\Force_Grab.cpp
# End Source File
# Begin Source File

SOURCE=.\d3xp\physics\Force_Grab.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Spring.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Force_Spring.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Actor.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Actor.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_AF.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_AF.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Base.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Base.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Monster.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Monster.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Parametric.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Parametric.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Player.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Player.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_RigidBody.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_RigidBody.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Static.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_Static.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_StaticMulti.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Physics_StaticMulti.h
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Push.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\physics\Push.h
# End Source File
# End Group
# Begin Group "Script"

# PROP Default_Filter ""
# Begin Source File

SOURCE=d3xp\script\Script_Compiler.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Compiler.h
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Interpreter.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Interpreter.h
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Program.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Program.h
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Thread.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\script\Script_Thread.h
# End Source File
# End Group
# Begin Source File

SOURCE=d3xp\Actor.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Actor.h
# End Source File
# Begin Source File

SOURCE=d3xp\AF.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\AF.h
# End Source File
# Begin Source File

SOURCE=d3xp\AFEntity.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\AFEntity.h
# End Source File
# Begin Source File

SOURCE=d3xp\BrittleFracture.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\BrittleFracture.h
# End Source File
# Begin Source File

SOURCE=d3xp\Camera.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Camera.h
# End Source File
# Begin Source File

SOURCE=d3xp\Entity.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Entity.h
# End Source File
# Begin Source File

SOURCE=d3xp\Fx.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Fx.h
# End Source File
# Begin Source File

SOURCE=d3xp\Game.h
# End Source File
# Begin Source File

SOURCE=d3xp\Game_local.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Game_local.h
# End Source File
# Begin Source File

SOURCE=d3xp\Game_network.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\GameEdit.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\GameEdit.h
# End Source File
# Begin Source File

SOURCE=.\d3xp\Grabber.cpp
# End Source File
# Begin Source File

SOURCE=.\d3xp\Grabber.h
# End Source File
# Begin Source File

SOURCE=d3xp\IK.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\IK.h
# End Source File
# Begin Source File

SOURCE=d3xp\Item.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Item.h
# End Source File
# Begin Source File

SOURCE=d3xp\Light.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Light.h
# End Source File
# Begin Source File

SOURCE=d3xp\Misc.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Misc.h
# End Source File
# Begin Source File

SOURCE=d3xp\Moveable.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Moveable.h
# End Source File
# Begin Source File

SOURCE=d3xp\Mover.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Mover.h
# End Source File
# Begin Source File

SOURCE=d3xp\MultiplayerGame.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\MultiplayerGame.h
# End Source File
# Begin Source File

SOURCE=d3xp\Player.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Player.h
# End Source File
# Begin Source File

SOURCE=d3xp\PlayerIcon.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\PlayerIcon.h
# End Source File
# Begin Source File

SOURCE=d3xp\PlayerView.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\PlayerView.h
# End Source File
# Begin Source File

SOURCE=d3xp\Projectile.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Projectile.h
# End Source File
# Begin Source File

SOURCE=d3xp\Pvs.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Pvs.h
# End Source File
# Begin Source File

SOURCE=d3xp\SecurityCamera.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\SecurityCamera.h
# End Source File
# Begin Source File

SOURCE=d3xp\SmokeParticles.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\SmokeParticles.h
# End Source File
# Begin Source File

SOURCE=d3xp\Sound.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Sound.h
# End Source File
# Begin Source File

SOURCE=d3xp\Target.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Target.h
# End Source File
# Begin Source File

SOURCE=d3xp\Trigger.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Trigger.h
# End Source File
# Begin Source File

SOURCE=d3xp\Weapon.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\Weapon.h
# End Source File
# Begin Source File

SOURCE=d3xp\WorldSpawn.cpp
# End Source File
# Begin Source File

SOURCE=d3xp\WorldSpawn.h
# End Source File
# End Group
# Begin Source File

SOURCE=d3xp\Game.def
# End Source File
# End Target
# End Project
