# Microsoft Developer Studio Project File - Name="idlib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=idlib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "idlib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "idlib.mak" CFG="idlib - Win32 Debug with inlines and memory log"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "idlib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "idlib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "idlib - Win32 Debug with inlines" (based on "Win32 (x86) Static Library")
!MESSAGE "idlib - Win32 Debug with inlines and memory log" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "idlib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release/idLib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release/idLib"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /ML /Zi /W3 /O2 /Og /Ob2 /Oi /Ot /Oy /G6 /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "GAME_DLL" /D "_MBCS" /GF /Gy /GR /c /GX /FD
# ADD CPP /nologo /ML /Zi /W3 /O2 /Og /Ob2 /Oi /Ot /Oy /G6 /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "GAME_DLL" /D "_MBCS" /GF /Gy /GR /c /GX /FD
# ADD BASE MTL /nologo /win32 
# ADD MTL /nologo /win32 
# ADD BASE RSC /l 1033 
# ADD RSC /l 1033 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "idlib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "debug"
# PROP BASE Intermediate_Dir "debug/idLib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "debug"
# PROP Intermediate_Dir "debug/idLib"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MLd /ZI /W3 /Od /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "GAME_DLL" /D "_MBCS" /GR /GZ /c /GX /FD
# ADD CPP /nologo /MLd /ZI /W3 /Od /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "GAME_DLL" /D "_MBCS" /GR /GZ /c /GX /FD
# ADD BASE MTL /nologo /win32 
# ADD MTL /nologo /win32 
# ADD BASE RSC /l 1033 
# ADD RSC /l 1033 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "idlib - Win32 Debug with inlines"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "debug"
# PROP BASE Intermediate_Dir "debug/idLib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "debug"
# PROP Intermediate_Dir "debug/idLib"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MLd /Zi /W3 /Od /Ob1 /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_INLINEDEBUG" /D "GAME_DLL" /D "_MBCS" /GR /GZ /c /GX /FD
# ADD CPP /nologo /MLd /Zi /W3 /Od /Ob1 /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_INLINEDEBUG" /D "GAME_DLL" /D "_MBCS" /GR /GZ /c /GX /FD
# ADD BASE MTL /nologo /win32 
# ADD MTL /nologo /win32 
# ADD BASE RSC /l 1033 /v 
# ADD RSC /l 1033 /v 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "idlib - Win32 Debug with inlines and memory log"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "debug"
# PROP BASE Intermediate_Dir "debug/idLib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "debug"
# PROP Intermediate_Dir "debug/idLib"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MLd /Zi /W3 /Od /Ob1 /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_INLINEDEBUG" /D "ID_REDIRECT_NEWDELETE" /D "ID_DEBUG_MEMORY" /D "ID_DEBUG_UNINITIALIZED_MEMORY" /D "GAME_DLL" /D "_MBCS" /GR /GZ /c /GX /FD
# ADD CPP /nologo /MLd /Zi /W3 /Od /Ob1 /D "__DOOM__" /D "__IDLIB__" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_INLINEDEBUG" /D "ID_REDIRECT_NEWDELETE" /D "ID_DEBUG_MEMORY" /D "ID_DEBUG_UNINITIALIZED_MEMORY" /D "GAME_DLL" /D "_MBCS" /GR /GZ /c /GX /FD
# ADD BASE MTL /nologo /win32 
# ADD MTL /nologo /win32 
# ADD BASE RSC /l 1033 
# ADD RSC /l 1033 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "idlib - Win32 Release"
# Name "idlib - Win32 Debug"
# Name "idlib - Win32 Debug with inlines"
# Name "idlib - Win32 Debug with inlines and memory log"
# Begin Group "idLib"

# PROP Default_Filter ""
# Begin Group "BV"

# PROP Default_Filter ""
# Begin Source File

SOURCE=idlib\bv\Bounds.cpp
# End Source File
# Begin Source File

SOURCE=idlib\bv\Bounds.h
# End Source File
# Begin Source File

SOURCE=idlib\bv\Box.cpp
# End Source File
# Begin Source File

SOURCE=idlib\bv\Box.h
# End Source File
# Begin Source File

SOURCE=idlib\bv\Frustum.cpp
# End Source File
# Begin Source File

SOURCE=idlib\bv\Frustum.h
# End Source File
# Begin Source File

SOURCE=idlib\bv\Sphere.cpp
# End Source File
# Begin Source File

SOURCE=idlib\bv\Sphere.h
# End Source File
# End Group
# Begin Group "Containers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=idlib\containers\BinSearch.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\BTree.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\HashIndex.cpp
# End Source File
# Begin Source File

SOURCE=idlib\containers\HashIndex.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\HashTable.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\Hierarchy.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\LinkList.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\List.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\PlaneSet.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\Queue.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\Stack.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\StaticList.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\StrList.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\StrPool.h
# End Source File
# Begin Source File

SOURCE=idlib\containers\VectorSet.h
# End Source File
# End Group
# Begin Group "Geometry"

# PROP Default_Filter ""
# Begin Source File

SOURCE=idlib\geometry\DrawVert.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\DrawVert.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\JointTransform.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\JointTransform.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface_Patch.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface_Patch.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface_Polytope.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface_Polytope.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface_SweptSpline.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Surface_SweptSpline.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\TraceModel.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\TraceModel.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Winding.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Winding.h
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Winding2D.cpp
# End Source File
# Begin Source File

SOURCE=idlib\geometry\Winding2D.h
# End Source File
# End Group
# Begin Group "Hashing"

# PROP Default_Filter ""
# Begin Source File

SOURCE=idlib\hashing\CRC16.cpp
# End Source File
# Begin Source File

SOURCE=idlib\hashing\CRC16.h
# End Source File
# Begin Source File

SOURCE=idlib\hashing\CRC32.cpp
# End Source File
# Begin Source File

SOURCE=idlib\hashing\CRC32.h
# End Source File
# Begin Source File

SOURCE=idlib\hashing\CRC8.cpp
# End Source File
# Begin Source File

SOURCE=idlib\hashing\CRC8.h
# End Source File
# Begin Source File

SOURCE=idlib\hashing\Honeyman.cpp
# End Source File
# Begin Source File

SOURCE=idlib\hashing\Honeyman.h
# End Source File
# Begin Source File

SOURCE=idlib\hashing\MD4.cpp
# End Source File
# Begin Source File

SOURCE=idlib\hashing\MD4.h
# End Source File
# Begin Source File

SOURCE=idlib\hashing\MD5.cpp
# End Source File
# Begin Source File

SOURCE=idlib\hashing\MD5.h
# End Source File
# End Group
# Begin Group "Math"

# PROP Default_Filter ""
# Begin Source File

SOURCE=idlib\math\Angles.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Angles.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Complex.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Complex.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Curve.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Extrapolate.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Interpolate.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Lcp.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Lcp.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Math.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Math.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Matrix.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Matrix.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Ode.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Ode.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Plane.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Plane.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Pluecker.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Pluecker.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Polynomial.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Polynomial.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Quat.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Quat.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Random.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Rotation.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Rotation.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_3DNow.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_3DNow.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_AltiVec.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_AltiVec.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_Generic.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_Generic.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_MMX.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_MMX.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_SSE.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_SSE.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_SSE2.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_SSE2.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_SSE3.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Simd_SSE3.h
# End Source File
# Begin Source File

SOURCE=idlib\math\Vector.cpp
# End Source File
# Begin Source File

SOURCE=idlib\math\Vector.h
# End Source File
# End Group
# Begin Source File

SOURCE=idlib\Base64.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Base64.h
# End Source File
# Begin Source File

SOURCE=idlib\BitMsg.cpp
# End Source File
# Begin Source File

SOURCE=idlib\BitMsg.h
# End Source File
# Begin Source File

SOURCE=idlib\CmdArgs.cpp
# End Source File
# Begin Source File

SOURCE=idlib\CmdArgs.h
# End Source File
# Begin Source File

SOURCE=idlib\Dict.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Dict.h
# End Source File
# Begin Source File

SOURCE=idlib\Heap.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Heap.h
# End Source File
# Begin Source File

SOURCE=idlib\LangDict.cpp
# End Source File
# Begin Source File

SOURCE=idlib\LangDict.h
# End Source File
# Begin Source File

SOURCE=idlib\Lexer.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Lexer.h
# End Source File
# Begin Source File

SOURCE=idlib\Lib.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Lib.h
# End Source File
# Begin Source File

SOURCE=idlib\MapFile.cpp
# End Source File
# Begin Source File

SOURCE=idlib\MapFile.h
# End Source File
# Begin Source File

SOURCE=idlib\Parser.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Parser.h
# End Source File
# Begin Source File

SOURCE=idlib\precompiled.h
# End Source File
# Begin Source File

SOURCE=idlib\Str.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Str.h
# End Source File
# Begin Source File

SOURCE=idlib\Timer.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Timer.h
# End Source File
# Begin Source File

SOURCE=idlib\Token.cpp
# End Source File
# Begin Source File

SOURCE=idlib\Token.h
# End Source File
# End Group
# End Target
# End Project
