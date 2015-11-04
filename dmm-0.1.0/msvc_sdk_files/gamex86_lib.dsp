# Microsoft Developer Studio Project File - Name="gamex86_lib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=gamex86_lib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gamex86_lib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gamex86_lib.mak" CFG="gamex86_lib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gamex86_lib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "gamex86_lib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gamex86_lib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "__DOOM__" /D "GAME_DLL" /D "WIN32" /D "NDEBUG" /D "WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "gamex86_lib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "gamex86_lib - Win32 Release"
# Name "gamex86_lib - Win32 Debug"
# Begin Group "Game"

# PROP Default_Filter ""
# Begin Group "AI"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\game\ai\AAS.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AAS.h
# End Source File
# Begin Source File

SOURCE=.\game\ai\AAS_debug.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AAS_local.h
# End Source File
# Begin Source File

SOURCE=.\game\ai\AAS_pathing.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AAS_routing.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AI.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AI.h
# End Source File
# Begin Source File

SOURCE=.\game\ai\AI_events.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AI_pathing.cpp
# End Source File
# Begin Source File

SOURCE=.\game\ai\AI_Vagary.cpp
# End Source File
# End Group
# Begin Group "Anim"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\game\anim\Anim.cpp
# End Source File
# Begin Source File

SOURCE=.\game\anim\Anim.h
# End Source File
# Begin Source File

SOURCE=.\game\anim\Anim_Blend.cpp
# End Source File
# Begin Source File

SOURCE=.\game\anim\Anim_Import.cpp
# End Source File
# Begin Source File

SOURCE=.\game\anim\Anim_Testmodel.cpp
# End Source File
# Begin Source File

SOURCE=.\game\anim\Anim_Testmodel.h
# End Source File
# End Group
# Begin Group "GameSys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\game\gamesys\Class.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\Class.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\DebugGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\DebugGraph.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\Event.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\Event.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\NoGameTypeInfo.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\SaveGame.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\SaveGame.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\SysCmds.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\SysCmds.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\SysCvar.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\SysCvar.h
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\TypeInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\game\gamesys\TypeInfo.h
# End Source File
# End Group
# Begin Group "Physics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\game\physics\Clip.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Clip.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Constant.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Constant.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Drag.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Drag.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Field.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Field.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Spring.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Force_Spring.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Actor.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Actor.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_AF.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_AF.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Base.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Base.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Monster.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Monster.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Parametric.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Parametric.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Player.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Player.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_RigidBody.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_RigidBody.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Static.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_Static.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_StaticMulti.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Physics_StaticMulti.h
# End Source File
# Begin Source File

SOURCE=.\game\physics\Push.cpp
# End Source File
# Begin Source File

SOURCE=.\game\physics\Push.h
# End Source File
# End Group
# Begin Group "Script"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\game\script\Script_Compiler.cpp
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Compiler.h
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Interpreter.cpp
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Interpreter.h
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Program.cpp
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Program.h
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Thread.cpp
# End Source File
# Begin Source File

SOURCE=.\game\script\Script_Thread.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\game\Actor.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Actor.h
# End Source File
# Begin Source File

SOURCE=.\game\AF.cpp
# End Source File
# Begin Source File

SOURCE=.\game\AF.h
# End Source File
# Begin Source File

SOURCE=.\game\AFEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\game\AFEntity.h
# End Source File
# Begin Source File

SOURCE=.\game\BrittleFracture.cpp
# End Source File
# Begin Source File

SOURCE=.\game\BrittleFracture.h
# End Source File
# Begin Source File

SOURCE=.\game\Camera.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Camera.h
# End Source File
# Begin Source File

SOURCE=.\game\Entity.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Entity.h
# End Source File
# Begin Source File

SOURCE=.\game\Fx.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Fx.h
# End Source File
# Begin Source File

SOURCE=.\game\Game.h
# End Source File
# Begin Source File

SOURCE=.\game\Game_local.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Game_local.h
# End Source File
# Begin Source File

SOURCE=.\game\Game_network.cpp
# End Source File
# Begin Source File

SOURCE=.\game\GameEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\game\GameEdit.h
# End Source File
# Begin Source File

SOURCE=.\game\IK.cpp
# End Source File
# Begin Source File

SOURCE=.\game\IK.h
# End Source File
# Begin Source File

SOURCE=.\game\Item.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Item.h
# End Source File
# Begin Source File

SOURCE=.\game\Light.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Light.h
# End Source File
# Begin Source File

SOURCE=.\game\Misc.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Misc.h
# End Source File
# Begin Source File

SOURCE=.\game\Moveable.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Moveable.h
# End Source File
# Begin Source File

SOURCE=.\game\Mover.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Mover.h
# End Source File
# Begin Source File

SOURCE=.\game\MultiplayerGame.cpp
# End Source File
# Begin Source File

SOURCE=.\game\MultiplayerGame.h
# End Source File
# Begin Source File

SOURCE=.\game\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Player.h
# End Source File
# Begin Source File

SOURCE=.\game\PlayerIcon.cpp
# End Source File
# Begin Source File

SOURCE=.\game\PlayerIcon.h
# End Source File
# Begin Source File

SOURCE=.\game\PlayerView.cpp
# End Source File
# Begin Source File

SOURCE=.\game\PlayerView.h
# End Source File
# Begin Source File

SOURCE=.\game\Projectile.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Projectile.h
# End Source File
# Begin Source File

SOURCE=.\game\Pvs.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Pvs.h
# End Source File
# Begin Source File

SOURCE=.\game\SecurityCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\game\SecurityCamera.h
# End Source File
# Begin Source File

SOURCE=.\game\SmokeParticles.cpp
# End Source File
# Begin Source File

SOURCE=.\game\SmokeParticles.h
# End Source File
# Begin Source File

SOURCE=.\game\Sound.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Sound.h
# End Source File
# Begin Source File

SOURCE=.\game\Target.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Target.h
# End Source File
# Begin Source File

SOURCE=.\game\Trigger.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Trigger.h
# End Source File
# Begin Source File

SOURCE=.\game\Weapon.cpp
# End Source File
# Begin Source File

SOURCE=.\game\Weapon.h
# End Source File
# Begin Source File

SOURCE=.\game\WorldSpawn.cpp
# End Source File
# Begin Source File

SOURCE=.\game\WorldSpawn.h
# End Source File
# End Group
# End Target
# End Project
