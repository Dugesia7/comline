@echo off
set dxdir=%~dp0dxlib
cl /I %dxdir% /MT /D_MBCS %* /link /LIBPATH:%dxdir%