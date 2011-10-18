#############################################################################
# Makefile for building: TwoPhotonMake
# Generated by qmake (2.01a) (Qt 4.4.1) on: Thu Sep 2 14:16:02 2010
# Project:  TwoPhotonMake.pro
# Template: app
# Command: c:\qt\bin\qmake.exe -spec ..\..\..\Qt\mkspecs\win32-msvc2008 -win32 CONFIG+=release -o Makefile TwoPhotonMake.pro
#############################################################################

first: all
install: release-install debug-install 
uninstall: release-uninstall debug-uninstall 
MAKEFILE      = Makefile
QMAKE         = c:\qt\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: TwoPhotonMake.pro  ..\..\..\Qt\mkspecs\win32-msvc2008\qmake.conf ..\..\..\Qt\mkspecs\qconfig.pri \
		..\..\..\Qt\mkspecs\features\qt_functions.prf \
		..\..\..\Qt\mkspecs\features\qt_config.prf \
		..\..\..\Qt\mkspecs\features\exclusive_builds.prf \
		..\..\..\Qt\mkspecs\features\default_pre.prf \
		..\..\..\Qt\mkspecs\features\win32\default_pre.prf \
		..\..\..\Qt\src\3rdparty\qwt-5.1.1\qwtconfig.pri \
		..\..\..\Qt\mkspecs\features\release.prf \
		..\..\..\Qt\mkspecs\features\debug_and_release.prf \
		..\..\..\Qt\mkspecs\features\default_post.prf \
		..\..\..\Qt\mkspecs\features\win32\thread.prf \
		..\..\..\Qt\mkspecs\features\warn_on.prf \
		..\..\..\Qt\mkspecs\features\qt.prf \
		..\..\..\Qt\mkspecs\features\moc.prf \
		..\..\..\Qt\mkspecs\features\win32\rtti.prf \
		..\..\..\Qt\mkspecs\features\win32\exceptions.prf \
		..\..\..\Qt\mkspecs\features\win32\stl.prf \
		..\..\..\Qt\mkspecs\features\shared.prf \
		..\..\..\Qt\mkspecs\features\win32\embed_manifest_exe.prf \
		..\..\..\Qt\mkspecs\features\win32\embed_manifest_dll.prf \
		..\..\..\Qt\mkspecs\features\win32\windows.prf \
		..\..\..\Qt\mkspecs\features\resources.prf \
		..\..\..\Qt\mkspecs\features\uic.prf \
		..\..\..\Qt\mkspecs\features\yacc.prf \
		..\..\..\Qt\mkspecs\features\lex.prf \
		c:\Qt\lib\qtmain.prl
	$(QMAKE) -spec ..\..\..\Qt\mkspecs\win32-msvc2008 -win32 CONFIG+=release -o Makefile TwoPhotonMake.pro
..\..\..\Qt\mkspecs\qconfig.pri:
..\..\..\Qt\mkspecs\features\qt_functions.prf:
..\..\..\Qt\mkspecs\features\qt_config.prf:
..\..\..\Qt\mkspecs\features\exclusive_builds.prf:
..\..\..\Qt\mkspecs\features\default_pre.prf:
..\..\..\Qt\mkspecs\features\win32\default_pre.prf:
..\..\..\Qt\src\3rdparty\qwt-5.1.1\qwtconfig.pri:
..\..\..\Qt\mkspecs\features\release.prf:
..\..\..\Qt\mkspecs\features\debug_and_release.prf:
..\..\..\Qt\mkspecs\features\default_post.prf:
..\..\..\Qt\mkspecs\features\win32\thread.prf:
..\..\..\Qt\mkspecs\features\warn_on.prf:
..\..\..\Qt\mkspecs\features\qt.prf:
..\..\..\Qt\mkspecs\features\moc.prf:
..\..\..\Qt\mkspecs\features\win32\rtti.prf:
..\..\..\Qt\mkspecs\features\win32\exceptions.prf:
..\..\..\Qt\mkspecs\features\win32\stl.prf:
..\..\..\Qt\mkspecs\features\shared.prf:
..\..\..\Qt\mkspecs\features\win32\embed_manifest_exe.prf:
..\..\..\Qt\mkspecs\features\win32\embed_manifest_dll.prf:
..\..\..\Qt\mkspecs\features\win32\windows.prf:
..\..\..\Qt\mkspecs\features\resources.prf:
..\..\..\Qt\mkspecs\features\uic.prf:
..\..\..\Qt\mkspecs\features\yacc.prf:
..\..\..\Qt\mkspecs\features\lex.prf:
c:\Qt\lib\qtmain.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ..\..\..\Qt\mkspecs\win32-msvc2008 -win32 CONFIG+=release -o Makefile TwoPhotonMake.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
	-$(DEL_FILE) "\TwoPhotonMake.intermediate.manifest"
	-$(DEL_FILE) TwoPhotonMake5.exp
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile