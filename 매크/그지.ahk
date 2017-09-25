Gui, Add, Text, x30 y5 w110 h20, Hungryrun    ; title
Gui, Add, Text, x60 y25 w50 h20 vA, Ready!    ; status
Gui, Add, Text, x60 y50 w50 h20 vB, 0 Cleared ; clear count
Gui, Add, Button, x20 y80 w110 h20, Start     ; start
Gui, Add, Button, x20 y110 w110 h20, End     ; start
Gui, Show

St_Start := false

return


F2::Pause

F3::
ButtonStart:
{
	St_Start := ture
	Loop
	{	
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\formation.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\echelon2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\changebus2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\bus1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\echelon3.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\changebus3.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\bus2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\returnbase.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\combat.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\emergency.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\field.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\do.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		F6::
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *30 %A_ScriptDir%\Image\hport.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,3}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\set1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\command.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\set1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\start.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		F6::
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktosel1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktosel2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\produce.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight11.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight1_3.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight4.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		sleep, 500
		Loop
		{
		ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *60 %A_ScriptDir%\Image\dragpoint.bmp
			if( ErrorLevel = 0 )
			{
				MouseClickDrag,Left, FoundX, FoundY, FoundX, FoundY+300, 9
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight15.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight6.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
	
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *40 %A_ScriptDir%\Image\clicktofight17.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *40 %A_ScriptDir%\Image\clicktofight8.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\turnfin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,10}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\fin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		
		
		; 2222222
		
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\formation.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\echelon2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\changebus1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\bus2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\echelon3.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\changebus3.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\bus1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\returnbase.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\combat.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\emergency.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\field.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\do.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\hport.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,3}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\set1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\command.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\set1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\start.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight1.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight2.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight3.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight4.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,1}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		sleep, 500
		Loop
		{
		ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *60 %A_ScriptDir%\Image\dragpoint.bmp
			if( ErrorLevel = 0 )
			{
				MouseClickDrag,Left, FoundX, FoundY, FoundX, FoundY+300, 9
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight5.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\clicktofight6.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *40 %A_ScriptDir%\Image\clicktofight7.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *40 %A_ScriptDir%\Image\clicktofight8.bmp
			if( ErrorLevel = 0 )
			{
				Send {Click %FoundX% %FoundY%}
				break
			}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\battlefin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\turnfin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,10}
			break
		}
		}
		sleep, 500
		Loop
		{
			ImageSearch, FoundX, FoundY, 0,0, A_ScreenWidth, A_ScreenHeight, *50 %A_ScriptDir%\Image\fin.bmp
			if( ErrorLevel = 0 )
		{
			Send {Click %FoundX% %FoundY%,50}
			break
		}
		}
		
		if( St_Start = false )
		{
			break
		}
		
	}
}
return

F5::Reload

F4::
ButtonEnd:
{
	St_Start := false
	ExitApp
}
return